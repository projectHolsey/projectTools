#include <stdio.h>

int main() {

    char* mys[] = {"Some String", "some String 2"};
    
    char** argv = mys;

    printf("%s\n", argv[0]);
    printf("%s\n", mys[0]);

    return 0;
}