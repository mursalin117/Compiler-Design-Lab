#include <bits/stdc++.h>
using namespace std;

int printMatches(string str, regex reg){
    int mCount = 0;
    smatch match;

    while(regex_search(str, match, reg)){
        cout << match.str(1) << endl;
        str = match.suffix().str();
        ++mCount;
//        cout << "This " << mCount << endl;
    }
    return mCount;
}

void wordCount(string str){
    regex reg("[^\\s,]([\\w-]+)[^\\s,]");
    int result = printMatches(str, reg);
    cout << "No of word is " << result << endl;
}

void letterCount(string str){
    regex reg("([a-zA-z])");
    int result = printMatches(str, reg);
    cout << "No of letter is " << result << endl;
}

void digitCount(string str){
    regex reg("\\d");
    int result = printMatches(str, reg);
    cout << "No of digit is " << result << endl;
}

void otherCount(string str){
    regex reg("\\W");
    int result = printMatches(str, reg);
    cout << "No of other character is " << result << endl;
}

void check(string str){
    wordCount(str);
    letterCount(str);
    digitCount(str);
    otherCount(str);
}

int main(){
    string str;
    freopen("input-1.txt", "r", stdin);
    getline(cin, str);
    cout << str << endl;
    check(str);

    return 0;
}
