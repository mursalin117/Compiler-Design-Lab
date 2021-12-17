#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    string str;
    getline(cin, str);
    cout << str << endl;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == 'C' && str[i+1] == 'S' && str[i+2] == 'E'){
            cout << "Computer Science and Engineering, ";
            i = i+2;
        }
        else if(str[i] == '3' && i == 4) cout << "3rd year, ";
        else if(str[i] == '1' && i == 5) cout << "1st semester, ";
        else if(str[i] == '4' && i == 6) cout << "Compiler Design, ";
        else if(str[i] == '1' && i == 7) cout << "Theory." << endl;
        else continue;
    }
    return 0;
}
