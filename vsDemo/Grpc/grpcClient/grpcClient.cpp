// grpcClient.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include "grpcpp/grpcpp.h"

#include "Algorithm_FileProcess.grpc.pb.h"


using grpc::Channel;
using grpc::ClientReader;
using grpc::ClientContext;
using grpc::ServerWriter;
using grpc::Status;
using Algorithm::Request;
using Algorithm::Response;
using Algorithm::FileProcess;


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
			for (int i = 0; i < reply.result_size(); i++)
			{
				std::cout << reply.result(i) << std::endl;
			}
			return "OK";
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
			for (int i = 0; i < feature.result_size(); i++)
			{
				std::cout << "flow call received: " << feature.result(i).c_str() << std::endl;
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
};

int main()
{
	std::string target_str;

	target_str = "127.0.0.1:50052";

	GreeterClient greeter(grpc::CreateChannel(target_str, grpc::InsecureChannelCredentials()));
	std::string user("world");

	//普通调用
	std::string reply = greeter.Process(user);
	if (reply.empty())
	{
		reply = greeter.Process(user);
	}
	std::cout << "general call received: " << reply << std::endl;

	//调用流式服务接口
	greeter.ListFeatures(user);

	while (1);

}
