typedef struct int_node {
    int value;
    struct int_node* next;
} int_node;

int insert_node_at_start(int_node** head, int value);
int insert_node_at_end(int_node** head, int value);
int insert_node_at_position(int_node** head, int position, int value);
int delete_node_at_position(int_node** head, int position);
int update_node_at_position(int_node* head, int position, int value);
int search_for_value(int_node* head, int value);
void display_list(int_node* head);
void free_list(int_node* head);
