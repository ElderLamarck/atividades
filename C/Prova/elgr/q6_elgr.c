#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int count_letters(char array_char[], char array_verify[])
{
	int count = 0;
	int i = 0;
	while (array_char[i] == array_verify[i] && array_char[i] != '\0' &&
	       array_verify[i] != '\0') {
		count++;
		i++;
	}
	if (array_char[i] != '\0' && array_verify[i] != '\0') {
		if (array_char[i] != array_verify[i]) {
			count++;
		}
	}

	return count;
}

int main(void)
{
	int first, second;
	int count_compare;
	int count;
	int start;
	int mid;
	int end;

	scanf("%d %d", &first, &second);
	char array_char[first][11];
	char array_verify[second][11];

	for (count = 0; count != first; count++) {
		scanf("%s", array_char[count]);
	}
	for (count = 0; count != second; count++) {
		scanf("%s", array_verify[count]);
	}
	for (count = 0; count != second; count++) {
		int start = 0;
		int mid;
		int end = first - 1;
		int key = 0;

		count_compare = 0;

		while (start <= end && key == 0) {
			mid = (start + end) / 2;
			if (strcmp(array_char[mid], array_verify[count]) == 0) {
				count_compare += strlen(array_char[mid]);
				printf("SIM %d\n", count_compare);
				key = 1;
			} else if (strcmp(array_char[mid],
					  array_verify[count]) < 0) {
				count_compare += count_letters(
					array_char[mid], array_verify[count]);
				start = mid + 1;
			} else {
				count_compare += count_letters(
					array_char[mid], array_verify[count]);
				end = mid - 1;
			}
		}
		if (key == 0) {
			printf("NAO %d\n", count_compare);
		}
	}
	return 0;
}