/******************************************************************
*
*  mUPnP for C++
*
*  Copyright (C) Satoshi Konno 2002
*
*  File: NotifyRequest.h
*
*  Revision;
*
*  07/08/03
*    - first revision
*
******************************************************************/

#ifndef _MUPMPCC_NOTIFYREQUEST_H_
#define _MUPMPCC_NOTIFYREQUEST_H_

#include <cybergarage/soap/SOAPRequest.h>
#include <mupnp/device/NT.h>
#include <mupnp/device/NTS.h>
#include <mupnp/event/Property.h>
#include <mupnp/event/Subscription.h>
#include <mupnp/event/Subscriber.h>
#include <mupnp/event/PropertyList.h>

#include <sstream>

namespace mUPnP {
class NotifyRequest : public CyberSOAP::SOAPRequest {
  PropertyList propList;

 public:
  static const char *XMLNS;
  static const char *PROPERTY;
  static const char *PROPERTYSET;

  ////////////////////////////////////////////////
  // Constructor
  ////////////////////////////////////////////////
  
 public:
  NotifyRequest() {
  }

  NotifyRequest(uHTTP::HTTPRequest *httpReq) {
    set(httpReq);
  }

  ////////////////////////////////////////////////
  // NT
  ////////////////////////////////////////////////

 public:
  void setNT(const std::string &value) {
    setHeader(uHTTP::HTTP::NT, value);
  }

  ////////////////////////////////////////////////
  // NTS
  ////////////////////////////////////////////////

 public:
  void setNTS(const std::string &value) {
    setHeader(uHTTP::HTTP::NTS, value);
  }

  ////////////////////////////////////////////////
  // SID
  ////////////////////////////////////////////////

 public:
  void setSID(const std::string &sid) {
    std::string buf;
    setHeader(uHTTP::HTTP::SID, Subscription::toSIDHeaderString(sid, buf));
  }

  const char *getSID(std::string &buf) {
    return Subscription::GetSID(getHeaderValue(uHTTP::HTTP::SID), buf);
  }

  ////////////////////////////////////////////////
  // SEQ
  ////////////////////////////////////////////////

 public:
  void setSEQ(long value) {
    setHeader(uHTTP::HTTP::SEQ, value);
  }

  long getSEQ() {
    return getLongHeaderValue(uHTTP::HTTP::SEQ);
  }

  ////////////////////////////////////////////////
  // Request
  ////////////////////////////////////////////////

 public:
  bool setRequest(Subscriber *sub, const std::string &varName, const std::string &value);

private:
  
  CyberXML::Node *createPropertySetNode(const std::string &varName, const std::string &value);

  CyberXML::Node *getVariableNode();

  ////////////////////////////////////////////////
  // Property
  ////////////////////////////////////////////////

private:
  
  Property *getProperty(CyberXML::Node *varNode);

 public:
  PropertyList *getPropertyList();
  
};

}

#endif
