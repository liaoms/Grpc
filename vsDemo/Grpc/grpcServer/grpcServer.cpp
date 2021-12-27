// grpcServer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <sstream>
#include <iostream>
#include <string>
#include <stdio.h>

#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

#include "Algorithm_FileProcess.grpc.pb.h"
#include "Algorithm_FileProcess.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerWriter;
using grpc::Status;
using Algorithm::Request;
using Algorithm::Response;
using Algorithm::FileProcess;

using namespace std;

// 继承并重写服务处理
class GreeterServiceImpl final : public FileProcess::Service
{
	//普通调用返回
	Status Process(ServerContext* context, const Request* request, Response* reply) override
	{
		(void)context;
		std::string prefix("Hello ");
		for (int i = 0; i < 10; i++)
		{
			//返回多个结果
			char strNum[3];
			sprintf_s(strNum, "%d", i);
			reply->add_result(prefix + strNum + " " + request->name());
		}
		return Status::OK;
	}

	//流式调用返回,可用于算法处理进度返回到client
	Status ListFeatures(ServerContext* context, const Request* request, ServerWriter< ::Algorithm::Response>* writer) override
	{
		(void)context;
		(void)request;
		for (int i = 0; i < 100; i++)
		{
			Response reMsg;
			char tmp[3];
			sprintf_s(tmp, "%d", i);
			string strNum(tmp);
			std::string msg = strNum + "%";
			reMsg.add_result(msg);
			writer->Write(reMsg);
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

	std::cout << "Server listening on " << server_address.c_str() << std::endl;

	//阻塞，等待接收client请求并处理
	server->Wait();
}

int main()
{
	RunServer();
}
