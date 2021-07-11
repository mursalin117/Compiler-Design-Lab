#include <bits/stdc++.h>
using namespace std;

int regMatch(string str, regex reg){
    int countMatch = 0;
    sregex_iterator currentMatch(str.begin(), str.end(), reg);
    sregex_iterator lastMatch;
    while(currentMatch != lastMatch){
        smatch match = *currentMatch;
        cout << match.str() << endl;
        countMatch++;
        currentMatch++;
    }
    return countMatch;
}

int main(){
    string str;
    freopen("input-1.txt", "r", stdin);
    getline(cin, str);
    cout << str << endl;

    // word count - ,\s \w-> 0-9,a-z,A-Z
    regex reg("([\\w.-]+)");
    int result = regMatch(str, reg);
    cout << "The no of words: " << result << endl;

    // letter count
    regex reg2("([a-zA-Z])");
    result = regMatch(str, reg2);
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
