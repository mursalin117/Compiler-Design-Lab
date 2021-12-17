#include <bits/stdc++.h>

using namespace std;

int isVowel(char ch)
{
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
    {
        if (ch == 'A' || ch == 'a' || ch == 'E' || ch == 'e' || ch == 'I' || ch == 'i' || ch == 'O' || ch == 'o' || ch == 'U' || ch == 'u')
        {
            return 1;
        }
        return 0;
    }
    return 0;
}

int isConsonant(char ch)
{
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
    {
        if (ch == 'A' || ch == 'a' || ch == 'E' || ch == 'e' || ch == 'I' || ch == 'i' || ch == 'O' || ch == 'o' || ch == 'U' || ch == 'u')
        {
            return 0;
        }
        return 1;
    }
    return 0;
}

void vowelString(string str)
{
    int i, j;
    string out = "";
    for (i = 0; i < str.length(); i++)
    {
        if (i == 0 && isVowel(str[i]))
        {
            for (j = i; !(str[j] == ' ' || str[j] == ','); j++)
            {
                out = out + str[j];
            }
            out = out + ' ';
            i = j - 1;
        }
        else if (str[i] == ' ' && isVowel(str[i + 1]))
        {
            for (j = i + 1; !(str[j] == ' ' || str[j] == ','); j++)
            {
                out = out + str[j];
            }
            out = out + ' ';
            i = j - 1;
        }
        else
            continue;
    }
    cout << "The vowel string is: " << out << endl;
}

void consonantString(string str)
{
    int i, j;
    string out = "";
    for (i = 0; i < str.length(); i++)
    {
        if (i == 0 && isConsonant(str[i]))
        {
            for (j = i; !(str[j] == ' ' || str[j] == ','); j++)
            {
                out = out + str[j];
            }
            out = out + ' ';
            i = j - 1;
        }
        else if (str[i] == ' ' && isConsonant(str[i + 1]))
        {
            for (j = i + 1; !(str[j] == ' ' || str[j] == ','); j++)
            {
                out = out + str[j];
            }
            out = out + ' ';
            i = j - 1;
        }
        else
            continue;
    }
    cout << "The consonant string is: " << out << endl;
}

int main(int argc, char const *argv[])
{
    string s = "Ok, This is our Md. Tareq Zaman and we are in Part-3, 2011";
    cout << s << endl;
    vowelString(s);
    consonantString(s);
    return 0;
}
