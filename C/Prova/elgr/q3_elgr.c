#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int multi(int rope, int price)
{
	if (price == 0) {
		return 0;
	} else {
		return (rope + multi(rope, price - 1));
	}
}

int main(void)
{
	int coin;
	int rope;
	int price;
	int result;

	while (scanf("%d %d %d", &rope, &coin, &price) != EOF) {
		result = multi(rope, price);
		if ((coin - result) >= 0) {
			printf("Sim\n");
		} else {
			printf("Nao\n");
		}
	}
	return 0;
}