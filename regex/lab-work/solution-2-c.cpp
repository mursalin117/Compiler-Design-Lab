#include <bits/stdc++.h>
using namespace std;

string printMatches(string str, regex reg){
    sregex_iterator currentMatch(str.begin(), str.end(), reg);
    sregex_iterator lastMatch;
    string strMatch = "";
    while(currentMatch != lastMatch){
        smatch match = *currentMatch;
        cout << match.str() << endl;
        strMatch.append(match.str());
        strMatch.append(" ");
        currentMatch++;
    }
    strMatch.append("\0");
    return strMatch;
}

void countVowel(string str){
    regex reg("\\b([aAeEiIoOuU][\\w]*)\\b");
    string result = printMatches(str, reg);
    cout << "The string of vowels are = " << result << endl;
}

void countConsonant(string str){
    regex reg("\\b([b-dB-Df-hF-Hj-nJ-Np-tP-Tv-zV-Z][\\w]*)\\b");
    string result = printMatches(str, reg);
    cout << "The string of constants are : " << result << endl;
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

