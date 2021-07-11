#include <bits/stdc++.h>
using namespace std;

int printMatches(string str, regex reg){
    sregex_iterator currentMatch(str.begin(), str.end(), reg);
    sregex_iterator lastMatch;
    int countMatch = 0;
    while(currentMatch != lastMatch){
        smatch match = *currentMatch;
        cout << match.str() << endl;
        countMatch++;
        currentMatch++;
    }
    return countMatch;
}

void countVowel(string str){
    regex reg("([aAeEiIoOuU])");
    int result = printMatches(str, reg);
    cout << "The no of vowels are = " << result << endl;
}

void countConsonant(string str){
    regex reg("([b-dB-Df-hF-Hj-nJ-Np-tP-Tv-zV-Z])");
    int result = printMatches(str, reg);
    cout << "The no of constants are : " << result << endl;
}

int main(){
    string str;
    freopen("input-2.txt", "r", stdin);
    getline(cin, str);
    cout << str << endl;
    countVowel(str);
    countConsonant(str);

    return 0;
}


