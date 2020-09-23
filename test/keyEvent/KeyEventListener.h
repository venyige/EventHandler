#pragma once

namespace cae
{
  class KeyEventListener
  {
  public:
    KeyEventListener(Event& iEventNum, Event& iEventStr);

    ~KeyEventListener() = default;

  private:
    void onNumber(const EventArgs& iArgs);

    void onString(const EventArgs& iArgs);
  };
}
