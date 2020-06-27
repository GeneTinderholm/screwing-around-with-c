#include <stdlib.h>
#include <stdio.h>

typedef struct item {
    char* itemName;
    int quantity;
    float price;
    float amount;
} item;

void read_item (item* it);
void print_item (item* it);

int main (void) {
    item* it = malloc(sizeof(item));
    read_item(it);
    print_item(it);
}

void read_item (item* it) {
    char temp[20];
    printf("Name: ");
    scanf("%s", temp);
    for (int i = 0; i < 20; i++) if(temp[i] == '\n') temp[i] = '\0';
    it->itemName = temp;
    printf("Quantity: ");
    scanf("%d", &it->quantity);
    printf("Price: ");
    scanf("%f", &it->price);
    it->amount = it->price * it->quantity;
}
void print_item (item* it) {
    printf("Name:     %s\n", it->itemName);
    printf("Quantity: %d\n", it->quantity);
    printf("Price:    %f\n", it->price);
    printf("Amount:   %f\n", it->amount);
}
