#include <bits/stdc++.h>

using namespace std;

int isVowel (char ch) {
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
    {
        if (ch == 'A' || ch == 'a' || ch == 'E' || ch == 'e' || ch == 'I' || ch == 'i' || ch == 'O' || ch == 'o' || ch == 'U' || ch == 'u')
        {
            return 1;
        }
        return 0;   
    }
    return 0;
}

int isConsonant (char ch) {
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
    {
        if (ch == 'A' || ch == 'a' || ch == 'E' || ch == 'e' || ch == 'I' || ch == 'i' || ch == 'O' || ch == 'o' || ch == 'U' || ch == 'u')
        {
            return 0;
        }
        return 1;   
    }
    return 0;
}

void countAll (string str) {
    int len = str.length();

    int countVowel = 0;
    for (int i = 0; i < len; i++){
        if (isVowel(str[i])) {
            countVowel++;
        }
        else continue;
    }
    cout << "The no. of vowel is " << countVowel << endl;

    int countConsonant = 0;
    for (int i = 0; i < len; i++){
        if (isConsonant(str[i])){
            countConsonant++;
        }
    }
    cout << "The no. of consonant is " << countConsonant << endl;
}

int main() {
    string s = "Md. Tareq Zaman, Part-3, 2011";
    countAll(s);
    return 0;
}