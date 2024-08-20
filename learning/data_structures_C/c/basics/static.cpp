#include <stdio.h>

void function() {
    static int staticVar = 0; // Static variable
    printf("Static variable: %d\n", staticVar);
    staticVar++;
}

int main() {
    function(); // Static variable: 0
    function(); // Static variable: 1
    function(); // Static variable: 2
    return 0;
}
