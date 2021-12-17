#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int is_vowel(char ch){
    if(ch == 'A' || ch == 'a' || ch == 'E' || ch == 'e' || ch == 'I' || ch == 'i' || ch == 'O' || ch == 'o' || ch == 'U' || ch == 'u')
        return 1;
    else return 0;
}
int is_char(char ch){
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) return 1;
    else return 0;
}

void separate(string st){
    // adding a space in the beginning
    st = ' ' + st;
    cout << st << endl;

    char vo[100], co[100];
    int vo_count = 0, co_count = 0, j;
    for(int i = 0; i < st.length(); i++){
        // if the first character is space and the 2nd character is vowel
        if((st[i] == ' ' || st[i] == ',') && is_vowel(st[i+1])){
            for(j = i+1; ; j++){
                if(st[j] == '\0' || st[j] == ',' || st[j] == ' ' || (st[j] == '.' && st[j+1] == '\0')) break;
                vo[vo_count++] = st[j];
            }
            vo[vo_count++] = ' ';
            i = j-1;
        }
        else if((st[i] == ' ' || st[i] == ',') && is_char(st[i+1])){
            for(j = i+1; ; j++){
                if(st[j] == '\0' || st[j] == ',' || st[j] == ' ' || (st[j] == '.' && st[j+1] == '\0')) break;
                co[co_count++] = st[j];
            }
            co[co_count++] = ' ';
            i = j-1;
        }
        else continue;
    }
    vo[vo_count] = '\0';
    co[co_count] = '\0';

    cout << vo << endl;
    cout << co << endl;
}

int main(){
    string str;
    freopen("input-2.txt", "r", stdin);
    getline(cin, str);
    separate(str);

    return 0;
}
