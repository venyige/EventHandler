#pragma once

namespace cae
{
  /// @brief base class of event arguments
  class EventArgs
  {
  public:
    /// @brief constructor
    EventArgs() = default;

    /// @brief destructor
    virtual ~EventArgs() = default;

    /// @brief disabled copy constructor
    EventArgs(const Event& iRhs) = delete;

    /// @brief disabled assigment operator
    EventArgs& operator=(const EventArgs& iRhs) = delete;
  };
}
