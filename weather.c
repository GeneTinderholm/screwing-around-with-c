// float array 5 rows 12 columngs
//
// output: year total rainfall for year
// yearly averages
// each month monthly averages

#include <stdio.h>
int main (void) {
    float rainfall[5][12] = {
        /* 1    2    3    4    5    6    7    8    9   10   11   12 */
        {4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
        {8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
        {9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
        {7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
        {7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2}
    };

    printf("YEAR  RAINFALL\n");
    /* yearly averages */
    float yearly_totals[5] = {0.0, 0.0, 0.0, 0.0, 0.0};
    float total_rainfall = 0.0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 12; ++j) {
            yearly_totals[i] += rainfall[i][j];
        }
        printf("%d  %.2f\n", 2010 + i, yearly_totals[i]);
        total_rainfall += yearly_totals[i];
    }
    printf("\nThe yearly average is %.2f inches\n", total_rainfall / 5);
    putchar('\n');
    printf("Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec\n");
    float monthly_totals[12];
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 5; ++j) {
            monthly_totals[i] += rainfall[j][i];
        }
        printf("%.2f ", monthly_totals[i] / 5);
    }
    putchar('\n');


    return 0;
}
