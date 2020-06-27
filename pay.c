#include <stdio.h>

float get_pay(int hours_worked, float pay) {
    int overtime_threshold = 40;

    if (hours_worked < overtime_threshold) {
        return hours_worked * pay;
    }

    float main_pay = pay * 40;
    int overtime = hours_worked - 40;
    float overtime_pay = overtime * pay * 1.5;

    return main_pay + overtime_pay;
}

/*
 * taxes 
 * 15% of first $300
 * 20% of next $150
 * 25% of rest
 */
float get_tax(float pay) {
    if (pay <= 300.0) {
        return pay * 0.15;
    }

    float tax_300 = 300 * 0.15;

    if (pay <= 450.0) {
        float pay_over_300 = pay - 300;
        return tax_300 + (pay_over_300 * 0.20);
    }
    
    float tax_450 = 150 * 0.20;

    float pay_over_450 = pay - 450;

    return tax_300 + tax_450 + (pay_over_450 * 0.25);
}

int main (void) {
    float hourly_pay = 12.00;
    int hours_worked;

    printf("enter hours worked: ");
    scanf("%d", &hours_worked);
    float pay = get_pay(hours_worked, hourly_pay);
    float tax = get_tax(pay);

    printf("Gross pay:  %.2f\n", pay);
    printf("Tax:        %.2f\n", tax);
    printf("Weekly pay: %.2f\n", pay - tax);
}
