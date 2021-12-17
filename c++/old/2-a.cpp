#include <iostream>

using namespace std;

int vowel(char ch){
    if(ch == 'A' || ch == 'a' || ch == 'E' || ch == 'e' || ch == 'I' || ch == 'i' || ch == 'O' || ch == 'o' || ch == 'U' || ch == 'u') return 1;
    else return 0;
}

void lt_count(string st){
    int vo_count = 0, co_count = 0;
    for(int i = 0; i < st.length(); i++){
        if((st[i] >= 'A' && st[i] <= 'Z') || (st[i] >= 'a' && st[i] <= 'z')){
            if(vowel(st[i])){
                vo_count++;
            }
            else co_count++;
        }
        else continue;
    }
    cout << "The no of vowel is " << vo_count << endl;
    cout << "The no of consonant is " << co_count << endl;
}

int main(){
    string str;
    freopen("input-2.txt", "r", stdin);
    getline(cin, str);
    cout << str << endl;
    lt_count(str);

    return 0;
}
