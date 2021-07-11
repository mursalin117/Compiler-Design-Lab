#include <bits/stdc++.h>
using namespace std;

int printMatches(string str, regex reg){
    smatch match;
    int countMatch = 0;
    while(regex_search(str, match, reg)){
        cout << match.str(0) << endl;
        str = match.suffix().str();
        countMatch++;
    }
    return countMatch;
}

int countWord(string str){
    regex reg("[^\\s,]([\\w,-]+)[^\\s,]");
    int noCount = printMatches(str, reg);
    return noCount;
}

int countLetter(string str){
    regex reg("([a-zA-Z])");
    int noCount = printMatches(str, reg);
    return noCount;
}

int countDigit(string str){
    regex reg("([\\d])");
    int noCount = printMatches(str, reg);
    return noCount;
}

int countOther(string str){
    regex reg("([\\W])");
    int noCount = printMatches(str, reg);
    return noCount;
}

void countAll(string str){
    int wordCount = countWord(str);
    cout << "The no of word is = " << wordCount << endl;

    int letterCount = countLetter(str);
    cout << "The no of letter is = " << letterCount << endl;

    int digitCount = countDigit(str);
    cout << "The no of digit is = " << digitCount << endl;

    int otherCount = countOther(str);
    cout << "The no of other characters are = " << otherCount << endl;
}


int main(){
    string str;
    freopen("input-1.txt", "r", stdin);
    getline(cin, str);
    cout << str << endl;
    countAll(str);

    return 0;
}
