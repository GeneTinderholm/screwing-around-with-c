#include <stdio.h>

union student {
    char letterGrade;
    int roundedGrade;
    float exactGrade;
};

int main (void) {
    union student var1, var2;

    var1.letterGrade = 'a';
    var1.roundedGrade = 95;
    var1.exactGrade = 94.23;

    puts("var1");
    printf("letterGrade: %c\n", var1.letterGrade);
    printf("roundedGrade: %d\n", var1.roundedGrade);
    printf("exactGrade: %f\n", var1.exactGrade);
    puts("var2");
    var2.letterGrade = 'b';
    printf("letterGrade: %c\n", var2.letterGrade);
    var2.roundedGrade = 80;
    printf("roundedGrade: %d\n", var2.roundedGrade);
    var2.exactGrade = 80.5;
    printf("exactGrade: %f\n", var2.exactGrade);
}
