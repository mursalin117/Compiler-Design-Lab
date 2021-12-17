#include <bits/stdc++.h>
using namespace std;

int printMatches(string str, regex reg){
    smatch match;

    if(regex_search(str, match, reg)) return 1;
    else return 0;
}

int intVar(string str){
    regex reg("^([i-nI-N][a-zA-Z0-9]*)$");
    int result = printMatches(str, reg);
    return result;
}

int shortInt(string str){
    regex reg("^([1-9][0-9]{0,3})$");
    int result = printMatches(str, reg);
    return result;
}

int longInt(string str){
    regex reg("^([1-9][0-9]{4,})$");
    int result = printMatches(str, reg);
    return result;
}

void check(string str){
    int result1 = intVar(str);
    int result2 = shortInt(str);
    int result3 = longInt(str);

    if(result1) cout << "Integer Variable" << endl;
    else if(result2) cout << "ShortInt Number" << endl;
    else if(result3) cout << "LongInt Number" << endl;
    else cout << "Otherwise" << endl;

}

int main(){
    string str;
    while(getline(cin, str)){
        if(str == "stop") break;
        else check(str);
    }

    return 0;
}
