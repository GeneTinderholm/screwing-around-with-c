#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    double height = atof(argv[1]);
    double width = atof(argv[2]);
    double perimeter = 2 * height + 2 * width;
    double area = height * width;

    printf("height: %.3f\nwidth: %.3f\nperimeter: %.3f\narea: %.3f\n",
            height,
            width,
            perimeter,
            area);
    return 0;
}
