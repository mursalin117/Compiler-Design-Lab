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

void separate(string st){
    char lt_sep[100], dt_sep[100], ot_sep[100];
    int in_lt = 0, in_dt = 0, in_ot = 0;

    for(int i = 0; i < st.length(); i++){
        if(is_char(st[i])){
            lt_sep[in_lt++] = st[i];
            lt_sep[in_lt++] = ' ';
        }
        else if(is_digit(st[i])){
            dt_sep[in_dt++] = st[i];
            dt_sep[in_dt++] = ' ';
        }
        else{
            //cout << st[i] << endl;
            ot_sep[in_ot++] = st[i];
            ot_sep[in_ot++] = ' ';
        }
    }
    lt_sep[in_lt] = '\0';
    dt_sep[in_dt] = '\0';
    ot_sep[in_ot] = '\0';

    cout << "The separated letters are:\n" << lt_sep << endl;
    cout << "The separated digits are:\n" << dt_sep << endl;
    cout << "The separated other characters are:\n" << ot_sep << endl;
}

//void separateone(string st){
//    char lt_sep[100], dt_sep[100], ot_sep[100];
//    int in_lt = 0, in_dt = 0, in_ot = 0;
//    int markl[300] = {0}, markd[300] = {0}, marko[300]= {0};
//
//    for(int i = 0; i < st.length(); i++){
//        int x = (int)st[i];
//
//        if(is_char(st[i])){
//            if(markl[x] == 0){
//                lt_sep[in_lt++] = st[i];
//                markl[x]++;
//            }
//            else markl[x]++;
//        }
//        else if(is_digit(st[i])){
//            if(markd[x] == 0){
//                dt_sep[in_dt++] = st[i];
//                dt_sep[in_dt++] = ' ';
//                markd[x]++;
//            }
//            else markd[x]++;
//        }
//        else{
//            //cout << st[i] << endl;
//            if(marko[x] == 0){
//                ot_sep[in_ot++] = st[i];
//                ot_sep[in_ot++] = ' ';
//            }
//            else marko[x]++;
//        }
//    }
//    lt_sep[in_lt] = '\0';
//    dt_sep[in_dt] = '\0';
//    ot_sep[in_ot] = '\0';
//    for(int i = 0; lt_sep[i]!= '\0'; i++){
//        printf("The letter is %c and it repeats %d\n", lt_sep[i], markl[(int)lt_sep[i]]);
//    }
//    cout << "The separated letters are:\n" << lt_sep << endl;
//    cout << "The separated digits are:\n" << dt_sep << endl;
//    cout << "The separated other characters are:\n" << ot_sep << endl;
//}

int main(){
    string str;

    freopen("input-1.txt", "r", stdin);
    getline(cin, str);

    cout << str << endl;
    separate(str);
//    separateone(str);

    return 0;
}
