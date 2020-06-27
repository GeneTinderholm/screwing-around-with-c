#include <stdio.h>
#include <complex.h>
#include <math.h>

int main (void) {
    double complex squ = I * I;

    printf("squ - real: %.2f imaginary: %.2f\n", creal(squ), cimag(squ));
    double complex pw = pow(I, 2);
    printf("squ - real: %.2f imaginary: %.2f\n", creal(pw), cimag(pw));
}
