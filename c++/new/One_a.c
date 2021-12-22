#include <stdio.h>
#include <string.h>

int isDigit (char ch) {
    if (ch >= '0' && ch <= '9'){
        return 1;
    }
    return 0;
}

int isChar (char ch) {
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')){
        return 1;
    }
    return 0;
}

int isOther (char ch) {
    if (!isChar(ch) && !isDigit(ch)){
        return 1;
    }
    return 0;
}

void countAll (char *str) {
    int len = strlen(str);

    int countWord = 0;
    for (int i = 0; i < len; i++){
        if ((str[i] == ' ' || str[i] == ',') && (isChar(str[i+1]) || isDigit(str[i+1]))){
            countWord++;
        }
        else continue;
    }
    
    int countLetter = 0;
    for (int i = 0; i < len; i++){
        if (isChar(str[i])) {
            countLetter++;
        }
        else continue;
    }
    
    int countDigit = 0;
    for (int i = 0; i < len; i++){
        if (isDigit(str[i])) {
            countDigit++;
        }
        else continue;
    }
    
    int countOther = 0;
    for (int i = 0; i < len; i++){
        if (!isChar(str[i]) && !isDigit(str[i])) {
            countOther++;
        }
        else continue;
    }

    printf("The no. of word is %d\n", countWord +1);
    printf("The no. of letter is %d\n", countLetter);
    printf("The no. of digit is %d\n", countDigit);
    printf("The no. of other character is %d\n", countOther);
}

int main() {
    char* s = "Md. Tareq Zaman, Part-3, 2011";
    
    countAll(s);

    return 0;
}