#include <bits/stdc++.h>

using namespace std;

int isDigit (char ch) {
    if (ch >= '0' && ch <= '9'){
        return 1;
    }
    return 0;
}

int isChar (char ch) {
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')){
        return 1;
    }
    return 0;
}

int isOther (char ch) {
    if (!isChar(ch) && !isDigit(ch)){
        return 1;
    }
    return 0;
}

void countAll (string str) {
    int len = str.length();

    int countWord = 0;
    for (int i = 0; i < len; i++){
        if ((str[i] == ' ' || str[i] == ',') && (isChar(str[i+1]) || isDigit(str[i+1]))){
            countWord++;
        }
        else continue;
    }
    
    int countLetter = 0;
    for (int i = 0; i < len; i++){
        if (isChar(str[i])) {
            countLetter++;
        }
        else continue;
    }
    
    int countDigit = 0;
    for (int i = 0; i < len; i++){
        if (isDigit(str[i])) {
            countDigit++;
        }
        else continue;
    }
    
    int countOther = 0;
    for (int i = 0; i < len; i++){
        if (!isChar(str[i]) && !isDigit(str[i])) {
            countOther++;
        }
        else continue;
    }

    cout << "The no. of word is " << countWord +1 << endl;
    cout << "The no. of letter is " << countLetter << endl;
    cout << "The no. of digit is " << countDigit << endl;
    cout << "The no. of other character is " << countOther << endl;
}

int main() {
    string s = "Md. Tareq Zaman, Part-3, 2011";
    
    countAll(s);

    return 0;
}