#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string str1;
int EXPR1(string str, int left, int right);
int calc(int one, int c, int two);
int toInt(string str, int left, int right);

char atDebug(int pos) {
    return str1.at(pos - 1);
}

int main() {
    cin >> str1;

    int c = EXPR1(str1, 1, str1.length());


    cout << c;
}

int EXPR1(string str, int left, int right) {
    // Status Enum: 1-Found Plus 3-Found Multiply
    int stat = 0;

    int t, i, splitPos = -1, s;

    t = 0; s = 0;
    for(i=right; i>=left; i--) {
        char temp = atDebug(i);
        if(temp == ')') s++;
        if(temp == '(') s--;
        if(s == 0 && (temp == '+' || temp == '-')) {
            if(temp == '+') t = 1; else t = 2;
            splitPos = i; break;
        }
    }

    if(t == 0) {
        s = 0;
        for(i=right; i>=left; i--) {
            char temp = atDebug(i);
            if(temp == ')') s++;
            if(temp == '(') s--;
            if(s == 0 && (temp == '*' || temp == '/')) {
                if(temp == '*') t = 3; else t = 4;
                splitPos = i; break;
            }
        }
    }

    if(t == 0 && atDebug(left) == '(')
        return EXPR1(str, left+1, right-1);

    if(t == 0) return toInt(str, left, right);

    if(t > 0) return calc(EXPR1(str, left, splitPos-1), t, EXPR1(str, splitPos+1, right));

}

int calc(int one, int c, int two) {
    if(c == 1) return one + two;
    if(c == 2) return one - two;
    if(c == 3) return one * two;
    if(c == 4) return one / two;
}
int toInt(string str, int left, int right) {
    int i, temp = 0;
    for(i=right; i>=left; i--) temp += (i - right + 1) * (atDebug(i) - '0');
    return temp;
}
