#include "Globals.h"
#include "Scanner.cpp"

void badParam() {
    cout << "Usage: lsi [file name]" << endl;
}

void run() {
    TokenRecord tk = getNextToken();
    printf("%s\n", tk.attribute.stringval);
    tk = getNextToken();
    printf("%s\n", tk.attribute.stringval);
    tk = getNextToken();
    printf("%s\n", tk.attribute.stringval);
    tk = getNextToken();
    printf("%s\n", tk.attribute.stringval);
    tk = getNextToken();
    printf("%s\n", tk.attribute.stringval);
    tk = getNextToken();
    printf("%s\n", tk.attribute.stringval);
}

int main(int argc,char *argv[]) {
    if(argc < 2) {
        badParam();
        exit(0);
    }

    code = fopen(argv[1], "r");
    run();
}
