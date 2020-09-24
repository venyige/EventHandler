#include <iostream>
#include <vector>

#include "KeyEventListener.h"


using namespace std;

int main(int argc, char** argv){
    bool verbose=(argc>1 && string(argv[1]).length()==2 && argv[1][0]=='-' && (argv[1][1]=='v' || argv[1][1]=='V'))?true:false;
    cae::Event numEvt{}, strEvt{};
    cae::KeyEventListener keyEvtListener(move(numEvt), move(strEvt), verbose);
    cout<<"If started with \"-v\" switch, then the output is verbose."<<endl;
    cout<<"    After started the program can be terminated with \"Ctrl-c\"."<<endl;

    while(true){
        string inStr;
        vector<string> stringVec;
        cin>>inStr;
        cout<<endl;
        stringVec=cae::split_string(inStr);
        for(auto sii:stringVec)
            if(cae::convertNumStr(sii)!=cae::convertRes::fail)
                keyEvtListener.processNumEvent(sii);
            else
                keyEvtListener.processStrEvent(sii);

    }

    return 0;
}
