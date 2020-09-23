#include "Event.h"
#include "EventArgs.h"

namespace cae
{
  Event& Event::operator+=(TCallback iCallback)
  {
    if (iCallback != nullptr)
      mCallbacks.emplace_back(iCallback);
    return *this;
  }

  void Event::Raise(const EventArgs& iArgs)
  {
    for (auto callback : mCallbacks)
      callback(iArgs);
  }
}
