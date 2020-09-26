// ints
// insert node at first
// insert node at last
// insert node at position
// delete node at position
// update node value
// search element in list
// display list

#include <stdlib.h>
#include <stdio.h>
#include "singly_linked_lists.h"


int insert_node_at_start(int_node** head, int value) {
    int_node* current_head = *head;
    int_node* new_head = malloc(sizeof(int_node));

    if (new_head == NULL) {
        return -1;
    }

    new_head->value = value;
    new_head->next = current_head;
    *head = new_head;

    return 0;
}

int insert_node_at_end(int_node** head, int value) {
    int_node* current = *head;
    int_node* new_node = malloc(sizeof(int_node));

    if (new_node == NULL) {
        return -1;
    }

    new_node->value = value;

    if (current == NULL) {
        new_node->next = NULL;
        *head = new_node;
    } else {
        int_node* next = current->next;

        while (next != NULL) {
            current = next;
            next = current->next;
        }
        current->next = new_node;
    }

    return 0;
}

int insert_node_at_position(int_node** head, int position, int value) {
    // zero based
    if (position == 0) {
        return insert_node_at_start(head, value);
    }

    int_node* prev = NULL;
    int_node* current = *head;

    for (int i = 0; i < position; ++i) {
        if (current == NULL) {
            return -1;
        }
        prev = current;
        current = current->next;
    }

    int_node* new_node = malloc(sizeof(int_node));

    if (new_node == NULL) {
        return -1;
    }

    new_node->value = value;
    new_node->next = current;
    prev->next = new_node;

    return 0;
}

int delete_node_at_position(int_node** head, int position) {
    int_node* prev = NULL;
    int_node* current = *head;

    if (current == NULL) {
        return -1;
    }

    for (int i = 0; i < position; ++i) {
        if (current == NULL) {
            return -1;
        }
        prev = current;
        current = current->next;
    }

    if (position == 0) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
    return 0;
}

int update_node_at_position(int_node* head, int position, int value) {
    int_node* current = head;

    for (int i = 0; i < position; ++i) {
        if (current == NULL) {
            return -1;
        }

        current = current->next;
    }
    current->value = value;
    return 0;
}

int search_for_value(int_node* head, int value) {
    int_node* current =  head;

    int index = 0;
    while (current != NULL) {
        if (current->value == value) {
            return index;
        }
        ++index;
        current = current->next;
    }
    return -1;
}

void display_list(int_node* head) {
    int_node* current = head;

    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

void free_list(int_node* head) {
    if (head == NULL) {
        return;
    }
    int_node* current = head;

    while (current != NULL) {
        int_node* tmp = current;
        current = current->next;
        free(tmp);
    }
}
