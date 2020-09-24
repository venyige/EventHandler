#include <iostream>
#include <vector>

#include "KeyEventListener.h"


using namespace std;

int main(int argc, char** argv){
    bool verbose=(argc>1 && string(argv[1]).length()==2 && argv[1][0]=='-' && (argv[1][1]=='v' || argv[1][1]=='V'))?true:false;
    cae::Event numEvt{}, strEvt{};
    cae::KeyEventListener keyEvtListener(move(numEvt), move(strEvt), verbose);

    while(true){
        string inStr;
        vector<string> stringVec;
        cin>>inStr;
        stringVec=cae::split_string(inStr);
        for(auto sii:stringVec)
            keyEvtListener.processNumEvent(sii);
    }


    return 0;
}
