#include <bits/stdc++.h>

using namespace std;

void sepDigit (string str) {
    string out = "";
    for (int i = 0; i < str.length(); i++){
        if (str[i] >= '0' && str[i] <= '9'){
            out = out + str[i];
        }
        else continue;    
    }
    cout << out << endl;
}

void sepChar (string str) {
    string out = "";
    for (int i = 0; i < str.length(); i++){
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
            out = out + str[i];
        }
        else continue;    
    }
    cout << out << endl;
}

void sepOther (string str) {
    string out = "";
    for (int i = 0; i < str.length(); i++){
        if (!(str[i] >= '0' && str[i] <= '9') && (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')))) {
            out = out + str[i];
        }
        else continue;    
    }
    cout << out << endl;
}

int main() {
    string s = "Md. Tareq Zaman, Part-3, 2011";
    sepDigit(s);
    sepChar(s);
    sepOther(s);

    return 0;
}