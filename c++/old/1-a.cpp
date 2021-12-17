#include <iostream>

using namespace std;

// letter checking
int is_char(char ch){
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) return 1;
    else return 0;
}

// digit checking
int is_digit(char ch){
    if(ch >= '0' && ch <= '9') return 1;
    else return 0;
}

// other character checking
int is_other(char ch){
    if(is_char(ch) || is_digit(ch)) return 0;
    else return 1;
}

// letter counting
int letter(string st){
 // cout << st << endl;
 int lt_count = 0;
 for (int i = 0; i < st.length(); i++){
    if(is_char(st[i])){
        lt_count++;
    }
    else continue;
 }
 return lt_count;
}

// digit counting
int digit(string st){
    // cout << st << endl;
 int dt_count = 0;
 for (int i = 0; i < st.length(); i++){
    if(is_digit(st[i])){
        dt_count++;
    }
    else continue;
 }
 return dt_count;
}

// other character counting
int others(string st){
    // cout << st << endl;
 int ot_count = 0;
 for (int i = 0; i < st.length(); i++){
    if(is_other(st[i])){
        ot_count++;
    }
    else continue;
 }
 return ot_count;
}

// word counting
int word(string st){
    int wd_count = 0;
    for(int i = 0; i < st.length(); i++){
        if(st[i] == ' ' || st[i] == ',' || st[i] == '.'){
            if(is_char(st[i-1]) || is_digit(st[i-1]))
                wd_count++;
            else continue;
        }
        else if(st[i+1] == '\0' && (is_char(st[i]) || is_digit(st[i]) || st[i] == '.'))
            wd_count++;
        else continue;
    }
    return wd_count;
}

int main(){

    string str;
    // input of string from file
    //freopen("input-1.txt", "r", stdin);
    getline(cin, str);

    // printing the string
    cout << str << endl;
    // cout << str.length() << endl;

    // word count show
    int wd_count = word(str);
    cout << wd_count << endl;

    // letter count show
    int lt_count = letter(str);
    cout << lt_count << endl;

    // digit count show
    int dt_count = digit(str);
    cout << dt_count << endl;

    // other character count show
    int ot_count = others(str);
    cout << ot_count << endl;
    return 0;
}
