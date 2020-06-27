#include <stdio.h>

int func () {
    return 5;
}

int cnuf () {
    return 5;
}

int taco (int x) {
    if (x == 1) {
        return 1;
    }

    return 50;
}

int main (void) {
    int x[] = {1};
    int y = 0;

    for (int i = 0; i != -1; ++i)
        y += x[i];

    func();
    cnuf();
    taco(1);
    taco(-1);

    return 0;
}
