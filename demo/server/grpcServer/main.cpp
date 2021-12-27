#include <QCoreApplication>
#include <iostream>
#include <memory>
#include <string>
#include <QDebug>
#include <QString>
#include <QThread>

#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

#include "proto/Algorithm_FileProcess.grpc.pb.h"

#include "proto/Algorithm_FileProcess.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerWriter;
using grpc::Status;
using Algorithm::Request;
using Algorithm::Response;
using Algorithm::FileProcess;

// 继承并重写服务处理
class GreeterServiceImpl final : public FileProcess::Service
{
    //普通调用返回
    Status Process(ServerContext* context, const Request* request, Response* reply) override
    {
        context->AddInitialMetadata("key1", "value1");  //设置一个上下文的值
        context->AddInitialMetadata("key2", "value2");

        std::string prefix("Hello ");
        for(int i=0; i<10; i++)
        {
            //返回多个结果
            reply->add_result(prefix + QString::number(i).toStdString() + request->name());
        }
        return Status::OK;
    }

    //流式调用返回,可用于算法处理进度返回到client
    Status ListFeatures(ServerContext* context, const Request* request, ServerWriter< ::Algorithm::Response>* writer) override
    {
        (void) context;
        (void) request;
        for (int i=0; i<100; i++)
        {
            Response reMsg;
            std::string msg =  QString::number(i+1).toStdString() + "%";
            reMsg.add_result(msg);
            writer->Write(reMsg);
            QThread::sleep(1);
        }
        return Status::OK;
    }
};

void RunServer() {
    std::string server_address("127.0.0.1:50052");

    GreeterServiceImpl service;     //具体服务处理类，继承后重写具体的处理接口

    grpc::EnableDefaultHealthCheckService(true);                //一些状态监测，貌似屏蔽掉也没关系
    grpc::reflection::InitProtoReflectionServerBuilderPlugin(); //同上

    ServerBuilder builder;  //服务创建类

    //监听
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());

    //注册
    builder.RegisterService(&service);

    //创建并启动服务
    std::unique_ptr<Server> server = builder.BuildAndStart();

    qDebug() << "Server listening on " << server_address.c_str();

    //阻塞，等待接收client请求并处理
    server->Wait();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    RunServer();

    return a.exec();
}
