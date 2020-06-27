#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int hireDate;
    float salary;
} employee;

employee* get_other_employee(void);
void display_employee(employee* emp);

int main (void) {
    employee joe = {
        .name = "Joe",
        .hireDate = 4,
        .salary = 70000.00
    };
    employee* other = get_other_employee();
    display_employee(&joe);
    display_employee(other);
}

employee* get_other_employee(void) {
    employee* other = malloc(sizeof(employee));
    printf("Employee name: ");
    scanf("%s", other->name);
    printf("Employee start date: ");
    scanf("%d", &other->hireDate);
    printf("Employee salary: ");
    scanf("%f", &other->salary);

    return other;
}
void display_employee(employee* emp) {
    printf("Name: %s\nHire Date: %d\nSalary: %f\n\n",
            emp->name, 
            emp->hireDate,
            emp->salary);
}
