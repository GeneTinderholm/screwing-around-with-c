#include <stdio.h>

int f1(int x) {
    int b;
  
    if(x==1)
        return 1;
    else {
        int y = f1(x-1);
        printf("x: %d\n", x);
        printf("y: %d\n", y);
        b=x*y;
        return b;
    }
}
int main() {
    int n;
    n=f1(5);
    printf("%d",n);
}
