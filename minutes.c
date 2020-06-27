#include <stdio.h>

int main(void) {
    int minutes;
    double minutes_in_day = 60 * 24;
    double minutes_in_year = minutes_in_day * 365;
    double days,
           years;

    printf("How many minutes?\n");
    scanf("%d", &minutes);

    days = minutes / minutes_in_day;
    years = minutes / minutes_in_year;

    // whole thin in both years and days
    printf("Days: %f\n", days);
    printf("Years: %f\n", years);

    // years with days
    days = (years - (int) years) * 365;
    printf("%d year(s) and %d day(s)\n", (int) years, (int) days);
}
