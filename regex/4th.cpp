#include <bits/stdc++.h>
using namespace std;

//int printMatches(string str, regex reg){
//    int mCount = 0;
//    smatch match;
//
//    while(regex_search(str, match, reg)){
////        cout << match.str(1) << endl;
//        str = match.suffix().str();
//        ++mCount;
////        cout << "This " << mCount << endl;
//    }
//    return mCount;
//}

int printMatches(string str, regex reg){
    smatch match;
    if(regex_search(str, match, reg)) return 1;
    else return 0;
}

int intVar(string str){
//    regex reg("[^\\W]([i-nI-N][a-zA-Z0-9]*)[^\\W]");
    regex reg("(^([i-nI-N][a-zA-Z0-9]*)$)");
    if(printMatches(str, reg)) return 1;
    else return 0;
}

int shorInt(string str){
    regex reg("(^[1-9][0-9]{0,3}$)");
    if(printMatches(str, reg)) return 1;
    else return 0;
}

int longInt(string str){
    regex reg("(^([1-9][0-9]{4,})$)");
    if(printMatches(str, reg)) return 1;
    else return 0;
}

void check(string str){
    int result1 = shorInt(str);
    int result2 = longInt(str);
    int result3 = intVar(str);

    if(result1) printf("Short Integer\n");
    else if(result2) printf("Long Integer\n");
    else if(result3) printf("Integer Variable\n");
    else printf("Otherwise\n");
}

int main(){
    string str;
    while(getline(cin, str)){
        if(str == "stop") break;
        check(str);
    }
    return 0;
}
