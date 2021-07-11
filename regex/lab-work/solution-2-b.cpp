#include <bits/stdc++.h>
using namespace std;

string printMatches(string str, regex reg){
    sregex_iterator currentMatch(str.begin(), str.end(), reg);
    sregex_iterator lastMatch;
    string strMatch = "";
    int mark[300] = {0};
    while(currentMatch != lastMatch){
        smatch match = *currentMatch;
        string ch = match.str();
//        cout << ch << endl;
        if(mark[ch[0]] == 0){
            cout << ch << endl;
            strMatch.append(ch);
            mark[ch[0]]++;
        }
        currentMatch++;
    }
    strMatch.append("\0");
    return strMatch;
}

void countVowel(string str){
    regex reg("([aAeEiIoOuU])");
    string result = printMatches(str, reg);
    cout << "The distinct vowels are = " << result << endl;
}

void countConsonant(string str){
    regex reg("([b-dB-Df-hF-Hj-nJ-Np-tP-Tv-zV-Z])");
    string result = printMatches(str, reg);
    cout << "The distinct constants are : " << result << endl;
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



