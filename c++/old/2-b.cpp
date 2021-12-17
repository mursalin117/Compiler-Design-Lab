#include <iostream>

using namespace std;

int vowel(char ch){
    if(ch == 'A' || ch == 'a' || ch == 'E' || ch == 'e' || ch == 'I' || ch == 'i' || ch == 'O' || ch == 'o' || ch == 'U' || ch == 'u') return 1;
    else return 0;
}

void lt_count(string st){
    char vo[100], co[100];
    int vo_count = 0, co_count = 0;
    int markv[300] = {0}, markc[300] = {0};

    for(int i = 0; i < st.length(); i++){
        if((st[i] >= 'A' && st[i] <= 'Z') || (st[i] >= 'a' && st[i] <= 'z')){
            if(vowel(st[i])){
                if(markv[(int)st[i]] == 0){
                    vo[vo_count++] = st[i];
                    vo[vo_count++] = ' ';
                    markv[(int)st[i]]++;
                }
                else markv[(int)st[i]]++;
            }
            else{
                if(markc[(int)st[i]] == 0){
                    co[co_count++] = st[i];
                    co[co_count++] = ' ';
                    markc[(int)st[i]]++;
                }
                else markc[(int)st[i]]++;
            }
        }
        else continue;
    }
    vo[vo_count] = '\0';
    co[co_count] = '\0';

    cout << "The vowels are: \n" << vo << endl;
    cout << "The consonants are: \n" << co << endl;

    cout << endl;
    for(int i = 0; vo[i] != '\0'; i++){
        if(vo[i] == ' ') continue;
        printf("The vowel %c repeats %d times.\n", vo[i], markv[(int)vo[i]]);
    }
    cout << endl;
    for(int i = 0; co[i] != '\0'; i++){
        if(co[i] == ' ') continue;
        printf("The consonant %c repeats %d times.\n", co[i], markc[(int)co[i]]);
    }
}

int main(){
    string str;
    freopen("input-2.txt", "r", stdin);
    getline(cin, str);
    cout << str << endl;
    lt_count(str);

    return 0;
}

