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

void vowelShowing (string str) {
    string out = "";
    for (int  i = 0; i < str.length(); i++){
        if (isVowel(str[i])) {
            out = out + str[i];
        }
        else continue;
    }
    cout << "The vowels are: " << out << endl;
}

void consonantShowing (string str) {
    string out = "";
    for (int  i = 0; i < str.length(); i++){
        if (isConsonant(str[i])) {
            out = out + str[i];
        }
        else continue;
    }
    cout << "The Consonants are: " << out << endl;
}

void checkDistinct (string str) {
    int ch[300] = {0};
    string vCheck = "";
    string cCheck = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (isVowel(str[i]))
        {
            if (ch[(int)str[i]] == 0)
            {
                vCheck = vCheck + str[i];
            }
            ch[(int)str[i]]++;
        }
        if (isConsonant(str[i])) 
        {
            if (ch[(int)str[i]] == 0)
            {
                cCheck = cCheck + str[i];
            }
            ch[(int)str[i]]++;
        }
    }
    cout << "Distinct vowel: " << vCheck << endl;
    cout << "Distinct constant: " << cCheck << endl;
}

int main () {
    string s = "Md. Tareq Zaman, Part-3, 2011";
    vowelShowing(s);
    consonantShowing(s);  
    checkDistinct(s); 
    return 0;
}
