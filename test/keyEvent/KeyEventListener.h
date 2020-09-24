#pragma once
#include <iostream>
#include <functional>
//#include "../../src/Event.h"
//#include "../../src/EventArgs.h"
#include "Event.h"
#include "EventArgs.h"



namespace cae
{
class StrEventArgs:public EventArgs{
public:
    StrEventArgs(const std::string&);
    const std::string& getData() const;
private:
    const std::string& _inStr;
};
class NumEventArgs:public EventArgs{
public:
    NumEventArgs(const std::string&);
    const std::string& getData() const;
private:
    const std::string& _inNum;
};
class KeyEventListener
{
public:
    KeyEventListener(Event iEventNum, Event iEventStr, bool verbose);

    void processNumEvent(const std::string&);
    void processStrEvent(const std::string&);

    ~KeyEventListener() = default;

private:
    void onNumber(const EventArgs& iArgs);

    void onString(const EventArgs& iArgs);
    Event _iEventNum;
    Event _iEventStr;
    bool _verbose;
};

/* UTILITY ----------------------------------------------------------*/
enum convertRes{fail, fit, not_fit};
convertRes convertNumStr(const std::string& inStr);
std::vector<std::string> split_string(std::string);
}
