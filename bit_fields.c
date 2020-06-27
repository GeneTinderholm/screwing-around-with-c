#include <stdio.h>
#include <stdbool.h>

// numbers after the colon represent the bit width
// unnamed members are bit padding
struct onscreen_box {
    unsigned int :4;
    unsigned int opaque:1;
    unsigned int color:3;
    unsigned int :2;
    unsigned int border:1;
    unsigned int border_color:3;
    unsigned int border_style:2;
};

// 3 bits: bgr
enum color {
    black,
    red,
    green,
    yellow,
    blue,
    magenta,
    cyan,
    white
};
enum style {
    solid,
    dotted,
    dashed
};

void print_onscreen_box (struct onscreen_box ob);
char* get_color_name (int color);
char* get_style_name (int style);

int main (void) {
    struct onscreen_box ob;
    ob.opaque = true;
    ob.color = blue;
    ob.border = true;
    ob.border_color = cyan;
    ob.border_style = dashed;
    printf("The size of an onscreen_box is %d bytes.\n\n", (int) sizeof(struct onscreen_box));
    printf("Original box settings: \n");
    print_onscreen_box(ob);

    ob.opaque = false;
    ob.color = yellow;
    ob.border = false;
    ob.border_style = dotted;
    printf("\nModified box settings: \n");
    print_onscreen_box(ob);
}

void print_onscreen_box (struct onscreen_box ob) {
    printf("The box is %s.\n", ob.opaque ? "opaque" : "transparent");
    printf("The box is %s.\n", get_color_name(ob.color));
    printf("The box has %s border\n", ob.border ? "a" : "no");
    if (ob.border) {
        printf("The border is %s.\n", get_color_name(ob.border_color));
    }
    printf("The boarder is %s.\n", get_style_name(ob.border_style));
}

char* get_color_name (int color) {
    char* colors[] = {
        "black",
        "red",
        "green",
        "yellow",
        "blue",
        "magenta",
        "cyan",
        "white"
    };
    return colors[color];
}

char* get_style_name (int style) {
    char* styles[] = {
        "solid",
        "dotted",
        "dashed"
    };

    return styles[style];
}
