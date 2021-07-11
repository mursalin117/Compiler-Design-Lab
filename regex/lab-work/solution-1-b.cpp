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
        currentMatch++;
    }
    strMatch.append("\0");
    return strMatch;
}

void countLetter(string str){
    regex reg("([a-zA-Z])");
    string result = printMatches(str, reg);
    cout << "The letters are : " << result << endl;
}

void countDigit(string str){
    regex reg("([\\d])");
    string result = printMatches(str, reg);
    cout << "The digits are : " << result << endl;
}

void countOther(string str){
    regex reg("([\\W])");
    string result = printMatches(str, reg);
    cout << "The other characters are: " << result << endl;
}

int main(){
    string str;
    freopen("input-1.txt", "r", stdin);
    getline(cin, str);
    cout << str << endl;
    countLetter(str);
    countDigit(str);
    countOther(str);

    return 0;
}

