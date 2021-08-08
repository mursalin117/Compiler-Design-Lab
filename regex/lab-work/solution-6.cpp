#include <bits/stdc++.h>
using namespace std;

int printMatches(string str, regex reg){
    smatch match;

    if(regex_search(str, match, reg)) return 1;
    else return 0;
}

int charVar(string str){
    regex reg("^((ch_)[a-zA-Z0-9]+)$");
    int result = printMatches(str, reg);
    return result;
}

int binVar(string str){
    regex reg("^((bn_)[a-zA-Z0-9]+)$");
    int result = printMatches(str, reg);
    return result;
}

int binNum(string str){
    regex reg("(^(0(0|1)+)$)");
    int result = printMatches(str, reg);
    return result;
}

void check(string str){
    int result1 = charVar(str);
    int result2 = binVar(str);
    int result3 = binNum(str);

    if(result1) cout << "Character Variable" << endl;
    else if(result2) cout << "Binary Variable" << endl;
    else if(result3) cout << "Binary Number" << endl;
    else cout << "Otherwise" << endl;
}

int main(){
    string str;
    while(getline(cin, str)){
//        cout << str << endl;
        if(str == "stop") break;
        else check(str);
    }

    return 0;
}

