#include <bits/stdc++.h>
using namespace std;

int printMatches(string str, regex reg){
    smatch match;

    if(regex_search(str, match, reg)) return 1;
    else return 0;
}

int floatVar(string str){
    regex reg("^([a-hA-Ho-zO-Z][\\w]*)$");
    int result = printMatches(str, reg);
    return result;
}

int floatNum(string str){
    regex reg("^((0|([1-9][\\d]*))\\.[\\d]{1,2})$");
    int result = printMatches(str, reg);
    return result;
}

int doubleNum(string str){
    regex reg("^((0|([1-9][\\d]*))\\.[\\d]{3,})$");
    int result = printMatches(str, reg);
    return result;
}

void check(string str){
    int result1 = floatVar(str);
    int result2 = floatNum(str);
    int result3 = doubleNum(str);

    if(result1) cout << "Float Variable" << endl;
    else if(result2) cout << "Float Number" << endl;
    else if(result3) cout << "Double Number" << endl;
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

