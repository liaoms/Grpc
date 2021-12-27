#include <QCoreApplication>
#include <iostream>
#include <memory>
#include <string>
#include <QProcess>
#include <QThread>
#include <QDebug>
#include <QDateTime>
#include "grpc/include/grpcpp/grpcpp.h"

#include "proto/Algorithm_FileProcess.grpc.pb.h"

using grpc::Channel;
using grpc::ClientReader;
using grpc::ClientContext;
using grpc::ServerWriter;
using grpc::Status;
using Algorithm::Request;
using Algorithm::Response;
using Algorithm::FileProcess;

//#define _WIN32_WINNT 0x6000

class GreeterClient {
public:
    //通过通道channel去创建存根stub_
    GreeterClient(std::shared_ptr<Channel> channel) : stub_(FileProcess::NewStub(channel)) {}

    //普通调用
    std::string Process(const std::string& user)
    {
        //向服务请求的参数
        Request request;
        request.set_name(user);

        //保存服务返回的结果
        Response reply;

        //上下文，用不用看具体情况
        ClientContext context;

        //通过存根，调用定义好的接口
        Status status = stub_->Process(&context, request, &reply);

        if (status.ok())
        {
            for(int i=0; i<reply.result_size(); i++)
            {
                qDebug() << currentTime() + reply.result(i).c_str();
            }

            qDebug() << currentTime() + "key1 = " + QString(context.GetServerInitialMetadata().find("key1")->second.data());
            qDebug() << currentTime() + "key2 = " + QString(context.GetServerInitialMetadata().find("key2")->second.data());
            return "OK";
        }
        else if(grpc::UNAVAILABLE == status.error_code())
        {
            qDebug() << "start grpcServer.exe begin";
            QProcess::startDetached("grpcServer.exe");
            qDebug() << "start grpcServer.exe end";

            return "";
        }
        else
        {
            std::cout << status.error_code() << ": " << status.error_message() << std::endl;
            return "RPC failed";
        }
    }

    //一次请求，服务端为流式返回，直到没有内容返回为止
    void ListFeatures(const std::string& user)
    {
        //向服务请求的参数
        Request request;
        request.set_name(user);

        //保存服务每次返回的流结果
        Response feature;

        //上下文
        ClientContext context;


        std::unique_ptr<ClientReader<Response> > reader(stub_->ListFeatures(&context, request));

        //读取由服务端返回的流数据，知道服务端没有流，才跳出while循环，否则一直读
        while (reader->Read(&feature))
        {
            std::cout << "feature.result_size() = " << feature.result_size() << std::endl;
            for(int i=0; i<feature.result_size(); i++)
            {
                std::cout << currentTime().toStdString() <<  "flow call received: " << feature.result(i).c_str() << std::endl;
//                system("clear");
            }
//            std::cout << "flow call received: " << feature.result() << std::endl;
        }

        Status status = reader->Finish();
        if (status.ok())
        {
            std::cout << "ListFeatures rpc succeeded." << std::endl;
        }
        else
        {
            std::cout << "ListFeatures rpc failed." << std::endl;
        }
    }

private:
    std::unique_ptr<FileProcess::Stub> stub_;  //存根，调用接口都在存根里边，即：都是通过存根去调用服务接口

private:
    QString currentTime()
    {
        return QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") + " -> ";
    }
};


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::string target_str;

    target_str = "127.0.0.1:50052";

    GreeterClient greeter(grpc::CreateChannel(target_str, grpc::InsecureChannelCredentials()));
    std::string user("world");

    //普通调用
    while(1)
    {
        std::string reply = greeter.Process(user);
        if(reply.empty())
        {
            reply = greeter.Process(user);
        }
        std::cout <<  "general call received: " << reply << std::endl;

        //调用流式服务接口
        greeter.ListFeatures(user);
        QThread::sleep(1);
    }

    return a.exec();
}
