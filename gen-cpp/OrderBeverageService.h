/**
 * Autogenerated by Thrift Compiler (0.13.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef OrderBeverageService_H
#define OrderBeverageService_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include <memory>
#include "vending_machine_types.h"

namespace vending_machine {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class OrderBeverageServiceIf {
 public:
  virtual ~OrderBeverageServiceIf() {}
  virtual void PlaceOrder(std::string& _return, const int64_t city) = 0;
};

class OrderBeverageServiceIfFactory {
 public:
  typedef OrderBeverageServiceIf Handler;

  virtual ~OrderBeverageServiceIfFactory() {}

  virtual OrderBeverageServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(OrderBeverageServiceIf* /* handler */) = 0;
};

class OrderBeverageServiceIfSingletonFactory : virtual public OrderBeverageServiceIfFactory {
 public:
  OrderBeverageServiceIfSingletonFactory(const ::std::shared_ptr<OrderBeverageServiceIf>& iface) : iface_(iface) {}
  virtual ~OrderBeverageServiceIfSingletonFactory() {}

  virtual OrderBeverageServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(OrderBeverageServiceIf* /* handler */) {}

 protected:
  ::std::shared_ptr<OrderBeverageServiceIf> iface_;
};

class OrderBeverageServiceNull : virtual public OrderBeverageServiceIf {
 public:
  virtual ~OrderBeverageServiceNull() {}
  void PlaceOrder(std::string& /* _return */, const int64_t /* city */) {
    return;
  }
};

typedef struct _OrderBeverageService_PlaceOrder_args__isset {
  _OrderBeverageService_PlaceOrder_args__isset() : city(false) {}
  bool city :1;
} _OrderBeverageService_PlaceOrder_args__isset;

class OrderBeverageService_PlaceOrder_args {
 public:

  OrderBeverageService_PlaceOrder_args(const OrderBeverageService_PlaceOrder_args&);
  OrderBeverageService_PlaceOrder_args& operator=(const OrderBeverageService_PlaceOrder_args&);
  OrderBeverageService_PlaceOrder_args() : city(0) {
  }

  virtual ~OrderBeverageService_PlaceOrder_args() noexcept;
  int64_t city;

  _OrderBeverageService_PlaceOrder_args__isset __isset;

  void __set_city(const int64_t val);

  bool operator == (const OrderBeverageService_PlaceOrder_args & rhs) const
  {
    if (!(city == rhs.city))
      return false;
    return true;
  }
  bool operator != (const OrderBeverageService_PlaceOrder_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const OrderBeverageService_PlaceOrder_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class OrderBeverageService_PlaceOrder_pargs {
 public:


  virtual ~OrderBeverageService_PlaceOrder_pargs() noexcept;
  const int64_t* city;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _OrderBeverageService_PlaceOrder_result__isset {
  _OrderBeverageService_PlaceOrder_result__isset() : success(false), se(false) {}
  bool success :1;
  bool se :1;
} _OrderBeverageService_PlaceOrder_result__isset;

class OrderBeverageService_PlaceOrder_result {
 public:

  OrderBeverageService_PlaceOrder_result(const OrderBeverageService_PlaceOrder_result&);
  OrderBeverageService_PlaceOrder_result& operator=(const OrderBeverageService_PlaceOrder_result&);
  OrderBeverageService_PlaceOrder_result() : success() {
  }

  virtual ~OrderBeverageService_PlaceOrder_result() noexcept;
  std::string success;
  ServiceException se;

  _OrderBeverageService_PlaceOrder_result__isset __isset;

  void __set_success(const std::string& val);

  void __set_se(const ServiceException& val);

  bool operator == (const OrderBeverageService_PlaceOrder_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(se == rhs.se))
      return false;
    return true;
  }
  bool operator != (const OrderBeverageService_PlaceOrder_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const OrderBeverageService_PlaceOrder_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _OrderBeverageService_PlaceOrder_presult__isset {
  _OrderBeverageService_PlaceOrder_presult__isset() : success(false), se(false) {}
  bool success :1;
  bool se :1;
} _OrderBeverageService_PlaceOrder_presult__isset;

class OrderBeverageService_PlaceOrder_presult {
 public:


  virtual ~OrderBeverageService_PlaceOrder_presult() noexcept;
  std::string* success;
  ServiceException se;

  _OrderBeverageService_PlaceOrder_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class OrderBeverageServiceClient : virtual public OrderBeverageServiceIf {
 public:
  OrderBeverageServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  OrderBeverageServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void PlaceOrder(std::string& _return, const int64_t city);
  void send_PlaceOrder(const int64_t city);
  void recv_PlaceOrder(std::string& _return);
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class OrderBeverageServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::std::shared_ptr<OrderBeverageServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (OrderBeverageServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_PlaceOrder(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  OrderBeverageServiceProcessor(::std::shared_ptr<OrderBeverageServiceIf> iface) :
    iface_(iface) {
    processMap_["PlaceOrder"] = &OrderBeverageServiceProcessor::process_PlaceOrder;
  }

  virtual ~OrderBeverageServiceProcessor() {}
};

class OrderBeverageServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  OrderBeverageServiceProcessorFactory(const ::std::shared_ptr< OrderBeverageServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::std::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::std::shared_ptr< OrderBeverageServiceIfFactory > handlerFactory_;
};

class OrderBeverageServiceMultiface : virtual public OrderBeverageServiceIf {
 public:
  OrderBeverageServiceMultiface(std::vector<std::shared_ptr<OrderBeverageServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~OrderBeverageServiceMultiface() {}
 protected:
  std::vector<std::shared_ptr<OrderBeverageServiceIf> > ifaces_;
  OrderBeverageServiceMultiface() {}
  void add(::std::shared_ptr<OrderBeverageServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void PlaceOrder(std::string& _return, const int64_t city) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->PlaceOrder(_return, city);
    }
    ifaces_[i]->PlaceOrder(_return, city);
    return;
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class OrderBeverageServiceConcurrentClient : virtual public OrderBeverageServiceIf {
 public:
  OrderBeverageServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(prot);
  }
  OrderBeverageServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void PlaceOrder(std::string& _return, const int64_t city);
  int32_t send_PlaceOrder(const int64_t city);
  void recv_PlaceOrder(std::string& _return, const int32_t seqid);
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync_;
};

#ifdef _MSC_VER
  #pragma warning( pop )
#endif

} // namespace

#endif
