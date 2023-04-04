/**
 * Autogenerated by Thrift Compiler (0.13.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef WeatherService_H
#define WeatherService_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include <memory>
#include "vending_machine_types.h"

namespace vending_machine {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class WeatherServiceIf {
 public:
  virtual ~WeatherServiceIf() {}
  virtual WeatherType::type GetWeather(const int64_t city) = 0;
};

class WeatherServiceIfFactory {
 public:
  typedef WeatherServiceIf Handler;

  virtual ~WeatherServiceIfFactory() {}

  virtual WeatherServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(WeatherServiceIf* /* handler */) = 0;
};

class WeatherServiceIfSingletonFactory : virtual public WeatherServiceIfFactory {
 public:
  WeatherServiceIfSingletonFactory(const ::std::shared_ptr<WeatherServiceIf>& iface) : iface_(iface) {}
  virtual ~WeatherServiceIfSingletonFactory() {}

  virtual WeatherServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(WeatherServiceIf* /* handler */) {}

 protected:
  ::std::shared_ptr<WeatherServiceIf> iface_;
};

class WeatherServiceNull : virtual public WeatherServiceIf {
 public:
  virtual ~WeatherServiceNull() {}
  WeatherType::type GetWeather(const int64_t /* city */) {
    WeatherType::type _return = (WeatherType::type)0;
    return _return;
  }
};

typedef struct _WeatherService_GetWeather_args__isset {
  _WeatherService_GetWeather_args__isset() : city(false) {}
  bool city :1;
} _WeatherService_GetWeather_args__isset;

class WeatherService_GetWeather_args {
 public:

  WeatherService_GetWeather_args(const WeatherService_GetWeather_args&);
  WeatherService_GetWeather_args& operator=(const WeatherService_GetWeather_args&);
  WeatherService_GetWeather_args() : city(0) {
  }

  virtual ~WeatherService_GetWeather_args() noexcept;
  int64_t city;

  _WeatherService_GetWeather_args__isset __isset;

  void __set_city(const int64_t val);

  bool operator == (const WeatherService_GetWeather_args & rhs) const
  {
    if (!(city == rhs.city))
      return false;
    return true;
  }
  bool operator != (const WeatherService_GetWeather_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const WeatherService_GetWeather_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class WeatherService_GetWeather_pargs {
 public:


  virtual ~WeatherService_GetWeather_pargs() noexcept;
  const int64_t* city;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _WeatherService_GetWeather_result__isset {
  _WeatherService_GetWeather_result__isset() : success(false) {}
  bool success :1;
} _WeatherService_GetWeather_result__isset;

class WeatherService_GetWeather_result {
 public:

  WeatherService_GetWeather_result(const WeatherService_GetWeather_result&);
  WeatherService_GetWeather_result& operator=(const WeatherService_GetWeather_result&);
  WeatherService_GetWeather_result() : success((WeatherType::type)0) {
  }

  virtual ~WeatherService_GetWeather_result() noexcept;
  WeatherType::type success;

  _WeatherService_GetWeather_result__isset __isset;

  void __set_success(const WeatherType::type val);

  bool operator == (const WeatherService_GetWeather_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const WeatherService_GetWeather_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const WeatherService_GetWeather_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _WeatherService_GetWeather_presult__isset {
  _WeatherService_GetWeather_presult__isset() : success(false) {}
  bool success :1;
} _WeatherService_GetWeather_presult__isset;

class WeatherService_GetWeather_presult {
 public:


  virtual ~WeatherService_GetWeather_presult() noexcept;
  WeatherType::type* success;

  _WeatherService_GetWeather_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class WeatherServiceClient : virtual public WeatherServiceIf {
 public:
  WeatherServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  WeatherServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
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
  WeatherType::type GetWeather(const int64_t city);
  void send_GetWeather(const int64_t city);
  WeatherType::type recv_GetWeather();
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class WeatherServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::std::shared_ptr<WeatherServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (WeatherServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_GetWeather(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  WeatherServiceProcessor(::std::shared_ptr<WeatherServiceIf> iface) :
    iface_(iface) {
    processMap_["GetWeather"] = &WeatherServiceProcessor::process_GetWeather;
  }

  virtual ~WeatherServiceProcessor() {}
};

class WeatherServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  WeatherServiceProcessorFactory(const ::std::shared_ptr< WeatherServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::std::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::std::shared_ptr< WeatherServiceIfFactory > handlerFactory_;
};

class WeatherServiceMultiface : virtual public WeatherServiceIf {
 public:
  WeatherServiceMultiface(std::vector<std::shared_ptr<WeatherServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~WeatherServiceMultiface() {}
 protected:
  std::vector<std::shared_ptr<WeatherServiceIf> > ifaces_;
  WeatherServiceMultiface() {}
  void add(::std::shared_ptr<WeatherServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  WeatherType::type GetWeather(const int64_t city) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->GetWeather(city);
    }
    return ifaces_[i]->GetWeather(city);
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class WeatherServiceConcurrentClient : virtual public WeatherServiceIf {
 public:
  WeatherServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(prot);
  }
  WeatherServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
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
  WeatherType::type GetWeather(const int64_t city);
  int32_t send_GetWeather(const int64_t city);
  WeatherType::type recv_GetWeather(const int32_t seqid);
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
