#include <bits/stdc++.h>
#include <regex>

using namespace std;

void regexSrc(string str, regex reg){
    smatch match;

    while(regex_search(str, match, reg)){
        // first match printing
        cout << match.str(1) << endl;
        // update string
        str = match.suffix().str();
    }
}

int main(){
    string str = "The ape in the apex"; //
    // create regular expression
    regex reg("((apex)|(ape))");
    regexSrc(str, reg);

    return 0;
}
