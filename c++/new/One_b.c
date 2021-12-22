#include <stdio.h>
#include <string.h>

void sepDigit (char* str) {
    char* out = "";
    int i, cnt = 0;
    for (i = 0; i < strlen(str); i++){
        if (str[i] >= '0' && str[i] <= '9'){
            out[cnt++] = str[i];
            // out = out + str[i];
        }
        else continue;    
    }
    out[cnt] = '\0';
    printf("%s\n", out);
}

void sepChar (char* str) {
    char* out = "";
    int i, cnt = 0;
    for (i = 0; i < strlen(str); i++){
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
            // out = out + str[i];
            out[cnt++] = str[i];
        }
        else continue;    
    }
    out[cnt] = '\0';
    printf("%s\n", out);
}

void sepOther (char* str) {
    char* out = "";
    int i, cnt = 0;
    for (i = 0; i < strlen(str); i++){
        if (!(str[i] >= '0' && str[i] <= '9') && (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')))) {
            // out = out + str[i];
            out[cnt++] = str[i];
        }
        else continue;    
    }
    out[cnt] = '\0';
    printf("%s\n", out);
}

int main() {
    char* s = "Md. Tareq Zaman, Part-3, 2011";
    sepDigit(s);
    sepChar(s);
    sepOther(s);

    return 0;
}