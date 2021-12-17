#include <iostream>

using namespace std;

int character(char ch){
    if(ch >= 'A' && ch <= 'Z') return 1;
    if(ch >= 'a' && ch <= 'z') return 1;

    return 0;
}

int digit(char ch){
    if(ch >= '0' && ch <= '9') return 1;
    else return 0;
}

int word(string str){
    int wd_count = 0;
    //cout << "form function: " << str << endl;
    for (int i = 1; str[i] != '\0'; i++){

        if(str[i] == ' ' || str[i] == ',' || str[i] == '.'){
            if(character(str[i-1]) || digit(str[i-1])) wd_count++;
            else continue;
            //cout << str[i-1] << endl;
        }
        else if(str[i+1] == '\0' && (character(str[i-1]) || digit(str[i-1]) || str[i-1] == '.')){
            wd_count++;
            //cout << str[i] << endl;
        }
        else continue;
    }
    return wd_count;
}

int main(){
    string str;
    //char str[200];
    //freopen("input-1.txt", "r", stdin);
    getline(cin, str);
    cout << str << endl;
    int result = word(str);
    cout << result << endl;
    return 0;
}

