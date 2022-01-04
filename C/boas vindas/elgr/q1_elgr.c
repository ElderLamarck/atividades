#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {

    char box, barran;
    int quant;
    int caps = 0, perTeacher = 0, i = 0;
    

    while ( i < 7 ) {
        scanf("%d", &quant);

        scanf("%c%c", &barran, &box);

        if (box == 'p' || box == 'P') {
            caps = (10 * quant) + caps;
        }
        else if (box == 'g' || box == 'G') {
            caps = (16 * quant) + caps;
        }
        i++;
    }

    perTeacher = (caps * 2) / 7;

    printf("%d\n", caps);
    printf("%d", perTeacher);
    return 0;
}