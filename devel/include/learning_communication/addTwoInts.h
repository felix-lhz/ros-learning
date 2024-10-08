// Generated by gencpp from file learning_communication/addTwoInts.msg
// DO NOT EDIT!


#ifndef LEARNING_COMMUNICATION_MESSAGE_ADDTWOINTS_H
#define LEARNING_COMMUNICATION_MESSAGE_ADDTWOINTS_H

#include <ros/service_traits.h>


#include <learning_communication/addTwoIntsRequest.h>
#include <learning_communication/addTwoIntsResponse.h>


namespace learning_communication
{

struct addTwoInts
{

typedef addTwoIntsRequest Request;
typedef addTwoIntsResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct addTwoInts
} // namespace learning_communication


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::learning_communication::addTwoInts > {
  static const char* value()
  {
    return "6a2e34150c00229791cc89ff309fff21";
  }

  static const char* value(const ::learning_communication::addTwoInts&) { return value(); }
};

template<>
struct DataType< ::learning_communication::addTwoInts > {
  static const char* value()
  {
    return "learning_communication/addTwoInts";
  }

  static const char* value(const ::learning_communication::addTwoInts&) { return value(); }
};


// service_traits::MD5Sum< ::learning_communication::addTwoIntsRequest> should match
// service_traits::MD5Sum< ::learning_communication::addTwoInts >
template<>
struct MD5Sum< ::learning_communication::addTwoIntsRequest>
{
  static const char* value()
  {
    return MD5Sum< ::learning_communication::addTwoInts >::value();
  }
  static const char* value(const ::learning_communication::addTwoIntsRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::learning_communication::addTwoIntsRequest> should match
// service_traits::DataType< ::learning_communication::addTwoInts >
template<>
struct DataType< ::learning_communication::addTwoIntsRequest>
{
  static const char* value()
  {
    return DataType< ::learning_communication::addTwoInts >::value();
  }
  static const char* value(const ::learning_communication::addTwoIntsRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::learning_communication::addTwoIntsResponse> should match
// service_traits::MD5Sum< ::learning_communication::addTwoInts >
template<>
struct MD5Sum< ::learning_communication::addTwoIntsResponse>
{
  static const char* value()
  {
    return MD5Sum< ::learning_communication::addTwoInts >::value();
  }
  static const char* value(const ::learning_communication::addTwoIntsResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::learning_communication::addTwoIntsResponse> should match
// service_traits::DataType< ::learning_communication::addTwoInts >
template<>
struct DataType< ::learning_communication::addTwoIntsResponse>
{
  static const char* value()
  {
    return DataType< ::learning_communication::addTwoInts >::value();
  }
  static const char* value(const ::learning_communication::addTwoIntsResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // LEARNING_COMMUNICATION_MESSAGE_ADDTWOINTS_H
