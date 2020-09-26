#include <stdio.h>
#include "singly_linked_lists.h"

int main (void) {
    int command = 0;
    int value = 0;
    int position = 0;
    int_node* head = NULL;

    while (command != 7) {
        printf("Input command:\n");
        printf("1. Insert node at start of list\n");
        printf("2. Insert node at end of list\n");
        printf("3. Insert node at position (0 based)\n");
        printf("4. Delete node at position (0 based)\n");
        printf("5. Update node at position (0 based)\n");
        printf("6. Search for value\n");
        printf("7. Exit\n");

        scanf("%d", &command);

        switch (command) {
            case 1:
                printf("What value?: ");
                scanf("%d", &value);
                insert_node_at_start(&head, value);
                display_list(head);
                break;
            case 2:
                printf("What value?: ");
                scanf("%d", &value);
                insert_node_at_end(&head, value);
                display_list(head);
                break;
            case 3:
                printf("What position?: ");
                scanf("%d", &position);
                printf("What value?: ");
                scanf("%d", &value);
                insert_node_at_position(&head, position, value);
                display_list(head);
                break;
            case 4:
                printf("What position?: ");
                scanf("%d", &position);
                delete_node_at_position(&head, position);
                display_list(head);
                break;
            case 5:
                printf("What position?: ");
                scanf("%d", &position);
                printf("What value?: ");
                scanf("%d", &value);
                update_node_at_position(head, position, value);
                display_list(head);
                break;
            case 6:
                printf("What value?: ");
                scanf("%d", &value);
                position = search_for_value(head, value);
                if (position == -1) {
                    printf("Value not found.");
                } else {
                    printf("It is at position %d.\n", position);
                }
                display_list(head);
                break;
            default:
                break;
        }
    }

    free_list(head);
    return 0;
}
