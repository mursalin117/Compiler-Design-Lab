#include <bits/stdc++.h>
#include <regex>

using namespace std;

int regexSrc(string str, regex reg){
    sregex_iterator currentMatch(str.begin(), str.end(), reg);
    sregex_iterator lastMatch;

//    while(currentMatch != lastMatch){
//        smatch match = *currentMatch;
//        //cout << match.str() << endl;
//        currentMatch++;
//    }
    if(currentMatch != lastMatch) return 1;
    else return 0;
}

void intVar(string str){
    regex reg("(^[i-nI-N][a-zA-Z0-9]*$)");
    int result = regexSrc(str, reg);
    if(result) cout << "Integer Variable" << endl;
    else cout << "Otherwise" << endl;
}

int main(){
    string str;
    while(getline(cin, str)){
        if(str == "stop") break;
        intVar(str);
    }
    // [i-nI-N.,-+%$]

    // create regular expression
    // regex reg("(ape)x?");
    // regexSrc(str, reg);

    return 0;
}

