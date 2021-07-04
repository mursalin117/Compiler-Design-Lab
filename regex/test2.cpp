#include <bits/stdc++.h>
#include <regex>

using namespace std;

void regexSrc(string str, regex reg){
    sregex_iterator currentMatch(str.begin(), str.end(), reg);
    sregex_iterator lastMatch;

    while(currentMatch != lastMatch){
        smatch match = *currentMatch;
        cout << match.str() << endl;
        currentMatch++;
    }
}

int main(){
    string str = "The ape in the apex";
    // create regular expression
    regex reg("(ape)x?");
    regexSrc(str, reg);

    return 0;
}
