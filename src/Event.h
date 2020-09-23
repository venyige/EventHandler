#pragma once

#include <functional>
#include <vector>

namespace cae
{
  class EventArgs;

  /// @brief event handling class 
  class Event
  {
    /// @brief alias for callback type
    using TCallback = std::function<void(const EventArgs&)>;

  public:
    /// @brief constructor
    Event() = default;

    /// @brief destructor
    ~Event() = default;

    /// @brief subscribing a callback to the event
    /// @param iCallback input callback
    /// @return modified event
    Event& operator+=(TCallback iCallback);

    /// @brief invoking the event to all subscribers
    /// @param iArgs input arguments
    void Raise(const EventArgs& iArgs);

  private:
    std::vector<TCallback> mCallbacks; ///< vector of callbacks
  };
}
