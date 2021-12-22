#include <bits/stdc++.h>
using namespace std;

/*
    Here,   E' = R,
            epsilon = #,
            T' = Y,
            id = i
*/

string grammar[] = {"E->TR", "R->+TR", "T->FY", "Y->*FY", "F->(E)", "R->#", "Y->#", "F->i"};
string FIRST[] = {"(i", "+", "(i", "*", "(", "#", "#", "i"};
string FOLLOW[10];

bool mark[200] , vis[150];
map<char,vector<string>>table;
char str[50];
vector<char>terminal;

string checkFirst(char ch, int pos, int val) {

    string ans = "";
    int i, j;
    for (i = 0; i < 8; i++){
    
        if (ch == grammar[i][0]) {  // finding the matching row
    
            for (j = 0; j < FIRST[i].size(); j++){
    
                if (FIRST[i][j] != '#') // if terminal just add it
                    ans += FIRST[i][j];
    
                else {
    
                    if (grammar[pos][val+1] == '\0') // if in last epsilon then the row's 
                        ans += FOLLOW[pos];  // starting follow is the follow
    
                    else if (grammar[pos][val+1] >= 'A' && grammar[pos][val+1] <= 'Z') // if non terminal
                        ans += checkFirst(grammar[pos][val+1], pos, val+1);  // again check the first
    
                    else // if after putting epsilon we get a non terminal afterwards 
                        ans += grammar[pos][val+1];
                }
            }
        }
    }
    return ans;
}

void calculateFollow() {
    int i, j, k;

    for (i = 0; i < 8; i++) {
        if (FOLLOW[0].size() == 0)
            FOLLOW[i] += "$";
        
        for (j = 0; j < 8; j++) {

            for (k = 3; k < grammar[j].size(); k++) {

                if (grammar[i][0] == grammar[j][k]) { // checking same E == E 
                
                    if (grammar[j][k+1] == '\0')    // if E is in end, the row's 
                        FOLLOW[i] += FOLLOW[j];     // starting follow is follow

                    else if (grammar[j][k+1] >= 'A' && grammar[j][k+1] <= 'Z') // if non terminal
                        FOLLOW[i] += checkFirst(grammar[j][k+1], j, k+1);  // check first                     
                    
                    else 
                        FOLLOW[i] += grammar[j][k+1]; // if terminal add to follow
                }
            }
        }
    }
    cout << "=============================== Follow ===============================" << endl;
    
    for (i = 0; i < 8; i++){
        memset(mark, 0, sizeof(mark)); // set all follow mark to zero
        string temp ="";

        for (j = 0; j < FOLLOW[i].size(); j++) {
            
            if (!mark[FOLLOW[i][j]]) {
                temp += FOLLOW[i][j]; // first time add follow to temp
                mark[FOLLOW[i][j]] = 1; // and mark follow as 1
            }
        }

        FOLLOW[i] = temp; // insert the unique follow to follow array

        if (!vis[grammar[i][0]]) { // showing for unique grammar
            temp = "{";

            for (j = 0; j < FOLLOW[i].size()-1; j++) 
                temp = temp + FOLLOW[i][j] + ',';    
            
            temp = temp + FOLLOW[i][j] + '}'; 
            vis[grammar[i][0]] = 1; // mark as 1 for not showing anymore
            cout << grammar[i][0] << " = " << temp << endl;
        }
    }
}

void cpy_str(string &s){
    int i = 0;
    for(i = 0 ; i < s.size() ; i++)
        str[i] = s[i];
    str[i] = '\0';

    printf("%-10s",str);
}

void calculateLLParsingTable() {
    // at first we have to find the no terminals from first and follow (excluding epsilon)
    memset(mark, 0, sizeof(mark));
    mark['#'] = 1;
    int i, j, k;

    for (i = 0; i < 8; i++) {

        for (j = 0; j < FIRST[i].size(); j++) {
            
            if (!mark[FIRST[i][j]]) {
                terminal.push_back(FIRST[i][j]);
                mark[FIRST[i][j]] = 1;
            }
        }
        for (j = 0; j < FOLLOW[i].size(); j++) {
            
            if (!mark[FOLLOW[i][j]]) {
                terminal.push_back(FOLLOW[i][j]);
                mark[FOLLOW[i][j]] = 1;
            }
        }        
    }
    
    printf("\n");
    printf("=============================== LL Parsing Table ===============================\n\n");
    printf("%-10c", ' ');
    for (i = 0; i < terminal.size(); i++) {   
        printf("%-10c", terminal[i]);
    }
    cout << endl;
    cout << endl;

    for (i = 0; i < 8; i++) {

        for (j = 0; j < FIRST[i].size(); j++) {
            
            if (FIRST[i][j] != '#') // if not epsilon, push the corresponding grammar
                table[FIRST[i][j]].push_back(grammar[i]);
            
            else { // if epsilon, push the follow to the grammar to the corresponding follow

                for (k = 0; k < FOLLOW[i].size(); k++)
                    table[FOLLOW[i][k]].push_back(grammar[i]);
            }
        }
    }
    
    for (i = 0 ; i < 5 ; i++) {
        char ch = grammar[i][0];
        
        printf("%-10c", ch);
        
        for (j = 0 ; j < terminal.size(); j++) {
            char ter = terminal[j];
            for (k = 0 ; k < table[ter].size() ; k++) {
                if(table[ter][k][0] == ch) {
                    cpy_str(table[ter][k]);
                    goto br;   
                }
            }
            printf("%-10s","");
            br:;
        }
        printf("\n");
    }
    cout<<endl;
}

int main(int argc, char const *argv[]) {
    
    calculateFollow();
    calculateLLParsingTable();
    return 0;
}
