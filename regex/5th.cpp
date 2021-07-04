#include <bits/stdc++.h>
using namespace std;

int printMatches(string str, regex reg){
    smatch match;
    if(regex_search(str, match, reg)) return 1;
    else return 0;
}

int floatVar(string str){
    regex reg("(^([a-hA-Ho-zO-Z][a-zA-Z0-9]*)$)");
    if(printMatches(str, reg)) return 1;
    else return 0;
}

int floatNum(string str){
    regex reg("(^((0|([1-9][0-9]*))\.[0-9]{1,2})$)");
    if(printMatches(str, reg)) return 1;
    else return 0;
}

int doubleNum(string str){
    regex reg("(^((0|([1-9][0-9]*))\.[0-9]{3,})$)");
    if(printMatches(str, reg)) return 1;
    else return 0;
}

void check(string str){
    int result1 = floatNum(str);
    int result2 = doubleNum(str);
    int result3 = floatVar(str);

    if(result1) printf("Float Number\n");
    else if(result2) printf("Double Number\n");
    else if(result3) printf("Float Variable\n");
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

