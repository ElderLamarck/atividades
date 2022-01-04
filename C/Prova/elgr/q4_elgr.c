#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int min(int first_value, int second_value, int third_value)
{
	int min = first_value;

	if (min > second_value) {
		min = second_value;
	}
	if (min > third_value) {
		min = third_value;
	}
	return min;
}

int main(void)
{
	int line;
	int column;
	int size;
	int max = 0;

	scanf("%d", &size);
	int matriz[size][size];
	int table[size][size];

	for (line = 0; line != size; line++) {
		for (column = 0; column != size; column++) {
			scanf("%d", &matriz[line][column]);
		}
	}

	for (line = 0; line != size; line++) {
		for (column = 0; column != size; column++) {
			if (line == 0 || column == 0) {
				table[line][column] = matriz[line][column];
			} else if (matriz[line][column] == 0) {
				table[line][column] = 0;
			} else {
				table[line][column] =
					min(table[line - 1][column - 1],
					    table[line - 1][column],
					    table[line][column - 1]) +
					1;
			}
		}
	}

	for (line = 0; line != size; line++) {
		for (column = 0; column != size; column++) {
			if (table[line][column] > max) {
				max = table[line][column];
			}
		}
	}
	max = max * max;
	printf("%d", max);

	return 0;
}