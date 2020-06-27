#include <stdio.h>
#include <stdlib.h>

int main (void) {
    int len;
    printf("Enter length of text: ");
    scanf("%d", &len);

    char* user_str = malloc(( len + 1 ) * sizeof(char));
    printf("Enter string: ");
    scanf("%s", user_str);
    printf("%s\n", user_str);

    free(user_str);
    user_str = NULL;
}
