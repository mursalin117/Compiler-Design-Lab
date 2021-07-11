#include <bits/stdc++.h>
using namespace std;

string regMatch(string str, regex reg){
    string strMatch = "";
    sregex_iterator currentMatch(str.begin(), str.end(), reg);
    sregex_iterator lastMatch;
    while(currentMatch != lastMatch){
        smatch match = *currentMatch;
        cout << match.str() << endl;
        strMatch.append(match.str());
        currentMatch++;
    }
    strMatch.append("\0");
    return strMatch;
}

int main(){
    string str;
    freopen("input-1.txt", "r", stdin);
    getline(cin, str);
    cout << str << endl;

    // letter count
    regex reg2("([a-zA-Z])");
    string result = regMatch(str, reg2);
    cout << "The no of letters: " << result << endl;

    // digit count -> \\d
    regex reg3("([\\d])");
    result = regMatch(str, reg3);
    cout << "The no of digits: " << result << endl;

    // other characters
    regex reg4("([\\W])");
    result = regMatch(str, reg4);
    cout << "The no of others: " << result << endl;
    return 0;
}

