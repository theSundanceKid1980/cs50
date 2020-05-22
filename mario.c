#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do {
        height = get_int("Height: ");
    }
    while (height <= 0 || height > 8);

    for (int x=1; x <= height; x++) {
        for (int k=x; k < height; k++) {
            printf(" ");
        }
        for (int k=0; k<x; k++) {
            printf("#");
        }
        for (int k=0; k<2; k++) {
            printf(" ");
        }
        for (int k=0; k<x; k++) {
            printf("#");
        }
        for (int k=x; k < height; k++) {
            printf(" ");
        }
        printf("\n");
    }
}
