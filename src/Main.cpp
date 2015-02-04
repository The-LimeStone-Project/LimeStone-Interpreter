#include "Scanner.cpp"

int main() {
    code = fopen("test.lss", "r");
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
