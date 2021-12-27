// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: Algorithm_FileProcess.proto
#ifndef GRPC_Algorithm_5fFileProcess_2eproto__INCLUDED
#define GRPC_Algorithm_5fFileProcess_2eproto__INCLUDED

#include "Algorithm_FileProcess.pb.h"

#include <functional>
#include <grpc/impl/codegen/port_platform.h>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/client_context.h>
#include <grpcpp/impl/codegen/completion_queue.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace Algorithm {

// 服务
class FileProcess final {
 public:
  static constexpr char const* service_full_name() {
    return "Algorithm.FileProcess";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status Process(::grpc::ClientContext* context, const ::Algorithm::Request& request, ::Algorithm::Response* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Algorithm::Response>> AsyncProcess(::grpc::ClientContext* context, const ::Algorithm::Request& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Algorithm::Response>>(AsyncProcessRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Algorithm::Response>> PrepareAsyncProcess(::grpc::ClientContext* context, const ::Algorithm::Request& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Algorithm::Response>>(PrepareAsyncProcessRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientReaderInterface< ::Algorithm::Response>> ListFeatures(::grpc::ClientContext* context, const ::Algorithm::Request& request) {
      return std::unique_ptr< ::grpc::ClientReaderInterface< ::Algorithm::Response>>(ListFeaturesRaw(context, request));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::Algorithm::Response>> AsyncListFeatures(::grpc::ClientContext* context, const ::Algorithm::Request& request, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::Algorithm::Response>>(AsyncListFeaturesRaw(context, request, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::Algorithm::Response>> PrepareAsyncListFeatures(::grpc::ClientContext* context, const ::Algorithm::Request& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::Algorithm::Response>>(PrepareAsyncListFeaturesRaw(context, request, cq));
    }
    class experimental_async_interface {
     public:
      virtual ~experimental_async_interface() {}
      virtual void Process(::grpc::ClientContext* context, const ::Algorithm::Request* request, ::Algorithm::Response* response, std::function<void(::grpc::Status)>) = 0;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      virtual void Process(::grpc::ClientContext* context, const ::Algorithm::Request* request, ::Algorithm::Response* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      #else
      virtual void Process(::grpc::ClientContext* context, const ::Algorithm::Request* request, ::Algorithm::Response* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
      #endif
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      virtual void ListFeatures(::grpc::ClientContext* context, ::Algorithm::Request* request, ::grpc::ClientReadReactor< ::Algorithm::Response>* reactor) = 0;
      #else
      virtual void ListFeatures(::grpc::ClientContext* context, ::Algorithm::Request* request, ::grpc::experimental::ClientReadReactor< ::Algorithm::Response>* reactor) = 0;
      #endif
    };
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    typedef class experimental_async_interface async_interface;
    #endif
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    async_interface* async() { return experimental_async(); }
    #endif
    virtual class experimental_async_interface* experimental_async() { return nullptr; }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::Algorithm::Response>* AsyncProcessRaw(::grpc::ClientContext* context, const ::Algorithm::Request& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::Algorithm::Response>* PrepareAsyncProcessRaw(::grpc::ClientContext* context, const ::Algorithm::Request& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientReaderInterface< ::Algorithm::Response>* ListFeaturesRaw(::grpc::ClientContext* context, const ::Algorithm::Request& request) = 0;
    virtual ::grpc::ClientAsyncReaderInterface< ::Algorithm::Response>* AsyncListFeaturesRaw(::grpc::ClientContext* context, const ::Algorithm::Request& request, ::grpc::CompletionQueue* cq, void* tag) = 0;
    virtual ::grpc::ClientAsyncReaderInterface< ::Algorithm::Response>* PrepareAsyncListFeaturesRaw(::grpc::ClientContext* context, const ::Algorithm::Request& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status Process(::grpc::ClientContext* context, const ::Algorithm::Request& request, ::Algorithm::Response* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Algorithm::Response>> AsyncProcess(::grpc::ClientContext* context, const ::Algorithm::Request& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Algorithm::Response>>(AsyncProcessRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Algorithm::Response>> PrepareAsyncProcess(::grpc::ClientContext* context, const ::Algorithm::Request& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Algorithm::Response>>(PrepareAsyncProcessRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientReader< ::Algorithm::Response>> ListFeatures(::grpc::ClientContext* context, const ::Algorithm::Request& request) {
      return std::unique_ptr< ::grpc::ClientReader< ::Algorithm::Response>>(ListFeaturesRaw(context, request));
    }
    std::unique_ptr< ::grpc::ClientAsyncReader< ::Algorithm::Response>> AsyncListFeatures(::grpc::ClientContext* context, const ::Algorithm::Request& request, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReader< ::Algorithm::Response>>(AsyncListFeaturesRaw(context, request, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReader< ::Algorithm::Response>> PrepareAsyncListFeatures(::grpc::ClientContext* context, const ::Algorithm::Request& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReader< ::Algorithm::Response>>(PrepareAsyncListFeaturesRaw(context, request, cq));
    }
    class experimental_async final :
      public StubInterface::experimental_async_interface {
     public:
      void Process(::grpc::ClientContext* context, const ::Algorithm::Request* request, ::Algorithm::Response* response, std::function<void(::grpc::Status)>) override;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      void Process(::grpc::ClientContext* context, const ::Algorithm::Request* request, ::Algorithm::Response* response, ::grpc::ClientUnaryReactor* reactor) override;
      #else
      void Process(::grpc::ClientContext* context, const ::Algorithm::Request* request, ::Algorithm::Response* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
      #endif
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      void ListFeatures(::grpc::ClientContext* context, ::Algorithm::Request* request, ::grpc::ClientReadReactor< ::Algorithm::Response>* reactor) override;
      #else
      void ListFeatures(::grpc::ClientContext* context, ::Algorithm::Request* request, ::grpc::experimental::ClientReadReactor< ::Algorithm::Response>* reactor) override;
      #endif
     private:
      friend class Stub;
      explicit experimental_async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class experimental_async_interface* experimental_async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class experimental_async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::Algorithm::Response>* AsyncProcessRaw(::grpc::ClientContext* context, const ::Algorithm::Request& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::Algorithm::Response>* PrepareAsyncProcessRaw(::grpc::ClientContext* context, const ::Algorithm::Request& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientReader< ::Algorithm::Response>* ListFeaturesRaw(::grpc::ClientContext* context, const ::Algorithm::Request& request) override;
    ::grpc::ClientAsyncReader< ::Algorithm::Response>* AsyncListFeaturesRaw(::grpc::ClientContext* context, const ::Algorithm::Request& request, ::grpc::CompletionQueue* cq, void* tag) override;
    ::grpc::ClientAsyncReader< ::Algorithm::Response>* PrepareAsyncListFeaturesRaw(::grpc::ClientContext* context, const ::Algorithm::Request& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_Process_;
    const ::grpc::internal::RpcMethod rpcmethod_ListFeatures_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status Process(::grpc::ServerContext* context, const ::Algorithm::Request* request, ::Algorithm::Response* response);
    virtual ::grpc::Status ListFeatures(::grpc::ServerContext* context, const ::Algorithm::Request* request, ::grpc::ServerWriter< ::Algorithm::Response>* writer);
  };
  template <class BaseClass>
  class WithAsyncMethod_Process : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_Process() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_Process() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Process(::grpc::ServerContext* /*context*/, const ::Algorithm::Request* /*request*/, ::Algorithm::Response* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestProcess(::grpc::ServerContext* context, ::Algorithm::Request* request, ::grpc::ServerAsyncResponseWriter< ::Algorithm::Response>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_ListFeatures : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_ListFeatures() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_ListFeatures() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ListFeatures(::grpc::ServerContext* /*context*/, const ::Algorithm::Request* /*request*/, ::grpc::ServerWriter< ::Algorithm::Response>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestListFeatures(::grpc::ServerContext* context, ::Algorithm::Request* request, ::grpc::ServerAsyncWriter< ::Algorithm::Response>* writer, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncServerStreaming(1, context, request, writer, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_Process<WithAsyncMethod_ListFeatures<Service > > AsyncService;
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_Process : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithCallbackMethod_Process() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::Algorithm::Request, ::Algorithm::Response>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::Algorithm::Request* request, ::Algorithm::Response* response) { return this->Process(context, request, response); }));}
    void SetMessageAllocatorFor_Process(
        ::grpc::experimental::MessageAllocator< ::Algorithm::Request, ::Algorithm::Response>* allocator) {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
    #else
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::experimental().GetHandler(0);
    #endif
      static_cast<::grpc::internal::CallbackUnaryHandler< ::Algorithm::Request, ::Algorithm::Response>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~ExperimentalWithCallbackMethod_Process() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Process(::grpc::ServerContext* /*context*/, const ::Algorithm::Request* /*request*/, ::Algorithm::Response* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* Process(
      ::grpc::CallbackServerContext* /*context*/, const ::Algorithm::Request* /*request*/, ::Algorithm::Response* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* Process(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::Algorithm::Request* /*request*/, ::Algorithm::Response* /*response*/)
    #endif
      { return nullptr; }
  };
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_ListFeatures : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithCallbackMethod_ListFeatures() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodCallback(1,
          new ::grpc::internal::CallbackServerStreamingHandler< ::Algorithm::Request, ::Algorithm::Response>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::Algorithm::Request* request) { return this->ListFeatures(context, request); }));
    }
    ~ExperimentalWithCallbackMethod_ListFeatures() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ListFeatures(::grpc::ServerContext* /*context*/, const ::Algorithm::Request* /*request*/, ::grpc::ServerWriter< ::Algorithm::Response>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerWriteReactor< ::Algorithm::Response>* ListFeatures(
      ::grpc::CallbackServerContext* /*context*/, const ::Algorithm::Request* /*request*/)
    #else
    virtual ::grpc::experimental::ServerWriteReactor< ::Algorithm::Response>* ListFeatures(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::Algorithm::Request* /*request*/)
    #endif
      { return nullptr; }
  };
  #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
  typedef ExperimentalWithCallbackMethod_Process<ExperimentalWithCallbackMethod_ListFeatures<Service > > CallbackService;
  #endif

  typedef ExperimentalWithCallbackMethod_Process<ExperimentalWithCallbackMethod_ListFeatures<Service > > ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_Process : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_Process() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_Process() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Process(::grpc::ServerContext* /*context*/, const ::Algorithm::Request* /*request*/, ::Algorithm::Response* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_ListFeatures : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_ListFeatures() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_ListFeatures() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ListFeatures(::grpc::ServerContext* /*context*/, const ::Algorithm::Request* /*request*/, ::grpc::ServerWriter< ::Algorithm::Response>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_Process : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_Process() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_Process() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Process(::grpc::ServerContext* /*context*/, const ::Algorithm::Request* /*request*/, ::Algorithm::Response* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestProcess(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_ListFeatures : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_ListFeatures() {
      ::grpc::Service::MarkMethodRaw(1);
    }
    ~WithRawMethod_ListFeatures() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ListFeatures(::grpc::ServerContext* /*context*/, const ::Algorithm::Request* /*request*/, ::grpc::ServerWriter< ::Algorithm::Response>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestListFeatures(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncWriter< ::grpc::ByteBuffer>* writer, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncServerStreaming(1, context, request, writer, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_Process : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithRawCallbackMethod_Process() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->Process(context, request, response); }));
    }
    ~ExperimentalWithRawCallbackMethod_Process() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Process(::grpc::ServerContext* /*context*/, const ::Algorithm::Request* /*request*/, ::Algorithm::Response* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* Process(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* Process(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #endif
      { return nullptr; }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_ListFeatures : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithRawCallbackMethod_ListFeatures() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodRawCallback(1,
          new ::grpc::internal::CallbackServerStreamingHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const::grpc::ByteBuffer* request) { return this->ListFeatures(context, request); }));
    }
    ~ExperimentalWithRawCallbackMethod_ListFeatures() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ListFeatures(::grpc::ServerContext* /*context*/, const ::Algorithm::Request* /*request*/, ::grpc::ServerWriter< ::Algorithm::Response>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerWriteReactor< ::grpc::ByteBuffer>* ListFeatures(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/)
    #else
    virtual ::grpc::experimental::ServerWriteReactor< ::grpc::ByteBuffer>* ListFeatures(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/)
    #endif
      { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_Process : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_Process() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::Algorithm::Request, ::Algorithm::Response>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::Algorithm::Request, ::Algorithm::Response>* streamer) {
                       return this->StreamedProcess(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_Process() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status Process(::grpc::ServerContext* /*context*/, const ::Algorithm::Request* /*request*/, ::Algorithm::Response* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedProcess(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::Algorithm::Request,::Algorithm::Response>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_Process<Service > StreamedUnaryService;
  template <class BaseClass>
  class WithSplitStreamingMethod_ListFeatures : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithSplitStreamingMethod_ListFeatures() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::internal::SplitServerStreamingHandler<
          ::Algorithm::Request, ::Algorithm::Response>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerSplitStreamer<
                     ::Algorithm::Request, ::Algorithm::Response>* streamer) {
                       return this->StreamedListFeatures(context,
                         streamer);
                  }));
    }
    ~WithSplitStreamingMethod_ListFeatures() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status ListFeatures(::grpc::ServerContext* /*context*/, const ::Algorithm::Request* /*request*/, ::grpc::ServerWriter< ::Algorithm::Response>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with split streamed
    virtual ::grpc::Status StreamedListFeatures(::grpc::ServerContext* context, ::grpc::ServerSplitStreamer< ::Algorithm::Request,::Algorithm::Response>* server_split_streamer) = 0;
  };
  typedef WithSplitStreamingMethod_ListFeatures<Service > SplitStreamedService;
  typedef WithStreamedUnaryMethod_Process<WithSplitStreamingMethod_ListFeatures<Service > > StreamedService;
};

}  // namespace Algorithm


#endif  // GRPC_Algorithm_5fFileProcess_2eproto__INCLUDED
