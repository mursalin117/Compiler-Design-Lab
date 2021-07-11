#include <bits/stdc++.h>
using namespace std;

void printMatches(string str, regex reg){
    sregex_iterator currentMatch(str.begin(), str.end(), reg);
    sregex_iterator lastMatch;

    if(currentMatch != lastMatch){
        cout << "Computer Science and Engineering, 3rd year, 1st semester, Compiler Design, Theory." << endl;
    }
    else cout << "Something else";
}

int main(){
    string str;
    getline(cin, str);
    regex reg("(CSE-3141)");
    printMatches(str, reg);

    return 0;
}
