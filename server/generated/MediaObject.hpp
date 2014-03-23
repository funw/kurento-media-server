/* Autogenerated with Kurento Idl */

#ifndef __MEDIA_OBJECT_HPP__
#define __MEDIA_OBJECT_HPP__

#include <jsoncpp/json/json.h>
#include <JsonRpcException.hpp>
#include <ObjectRegistrar.hpp>
#include <memory>
#include <vector>
#include "Error.hpp"
#include <sigc++/sigc++.h>
#include <EventHandler.hpp>

namespace kurento {

class MediaPipeline;

class MediaObject : public std::enable_shared_from_this<MediaObject>    {

public:

  MediaObject () {};
  virtual ~MediaObject () {};

  virtual std::shared_ptr<MediaPipeline> getMediaPipeline () {throw "Not implemented";};
  virtual std::shared_ptr<MediaObject> getParent () {throw "Not implemented";};

  virtual std::string connect(const std::string &eventType, std::shared_ptr<EventHandler> handler);

  sigc::signal<void, Error> signalError;

  class Factory : public virtual kurento::Factory
  {
  public:
    Factory () {};

    virtual std::string getName () {
      return "MediaObject";
    };

  private:

    virtual MediaObject * createObjectPointer (const Json::Value &params);

    MediaObject * createObject (int garbagePeriod);

    class StaticConstructor
    {
    public:
      StaticConstructor();
    };

    static StaticConstructor staticConstructor;

  };

  class Invoker
  {
  public:
    Invoker() {};
    virtual void invoke (std::shared_ptr<MediaObject> obj,
        const std::string &methodName, const Json::Value &params,
        Json::Value &response);
  };

  virtual Invoker &getInvoker() {
    return invoker;
  }

  private:
    Invoker invoker;

};

} /* kurento */

#endif /*  __MEDIA_OBJECT_HPP__ */