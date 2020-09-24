#include "KeyEventListener.h"
#include <memory>
#include <algorithm>
namespace cae
{
NumEventArgs::NumEventArgs(const std::string& inStr):_inNum{inStr}{}
const std::string& NumEventArgs::getData() const{
    return this->_inNum;
}

StrEventArgs::StrEventArgs(const std::string& inStr):_inStr{inStr}{}
const std::string& StrEventArgs::getData() const{
    return this->_inStr;
}

KeyEventListener::KeyEventListener(Event numEvt, Event strEvt, bool verbose=false):
    _iEventNum{numEvt},
    _iEventStr{strEvt},
    _verbose{verbose}{
    _iEventStr+=([this](const EventArgs& eA){this->onString(eA);});
    _iEventNum+=([this](const EventArgs& eA){this->onNumber(eA);});

}

void KeyEventListener::onNumber(const EventArgs &iArgs){
    if(_verbose){
        std::cout<<"Number event result: "<<static_cast<const NumEventArgs&>(iArgs).getData()<<std::endl;
        if(convertNumStr(static_cast<const NumEventArgs&>(iArgs).getData())==convertRes::fit)
            std::cout<<"    The source string could be converted to \"long double\" type,"<<std::endl<<
                       "    and fits to the limits of this type."<<std::endl<<std::scientific<<
                       "    Its value in scientific notation is: "<<
                       std::stold(static_cast<const NumEventArgs&>(iArgs).getData())<<std::endl<<std::endl;

        else
            std::cout<<"    The source string is a numeric string,"<<std::endl<<
                       "    but its value does not fit to the \"long double\" type."<<std::endl<<std::endl;
    }else{
        std::cout<<static_cast<const NumEventArgs&>(iArgs).getData()<<std::endl;
    }
}

void KeyEventListener::onString(const EventArgs &iArgs){
    if(_verbose){
        std::cout<<"String event result: "<<static_cast<const StrEventArgs&>(iArgs).getData()<<
                   std::endl<<std::endl;
    }else{
        std::cout<<static_cast<const StrEventArgs&>(iArgs).getData()<<std::endl;
    }
}

void KeyEventListener::processNumEvent(const std::string & strIn){
    _iEventNum.Raise(NumEventArgs(strIn));
}

void KeyEventListener::processStrEvent(const std::string & strIn){
    _iEventStr.Raise(StrEventArgs(strIn));
}

/* UTILITY ----------------------------------------------------------*/

convertRes convertNumStr(const std::string& inStr){
    long double resLD{};
    try {
        resLD=std::stold(inStr);
    } catch (std::invalid_argument _) {
        return convertRes::fail;
    }
    catch(std::out_of_range _){
        return  convertRes::not_fit;
    }
    return convertRes::fit;
}

std::vector<std::string> split_string(std::string input_string)
{
    std::vector<std::string> retVec;
    size_t iii = 0;
    std::string::iterator new_end = std::unique(input_string.begin(),
                                                input_string.end(),
                                                [](const char &lead,
                                                const char &end) {
        return lead == end and end == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
    {
        input_string.pop_back();
    }

    size_t pos = input_string.find(' ');

    while (pos != std::string::npos)
    {
        retVec.push_back(input_string.substr(iii, pos - iii));

        iii = pos + 1;
        pos = input_string.find(' ', iii);
    }

    retVec.push_back(input_string.substr(iii, std::min(pos, input_string.length()) - iii + 1));

    return retVec;
}

}
