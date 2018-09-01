#include <stdio.h>
#include <math.h>
int main() {
	/*int i = 2, count = 0, product = 1;

	while (count < 3) {
		i = i + 2;
		product = product*i;
		count++;
	}
	printf("%d", product);
	return 0;*/
	/*int sum = 0;
	for (int count = 1; count <= 15; count = count + 2) {

		sum = sum + count;

	}
	printf("%d", sum);*/

	int i = 1, sum = 0;
	while (i <= 20)
	{
		if (i % 5 == 0)
		{
			printf("%d ", i);
			sum = sum + i;
		}
		i = i + 1;
	}
	printf("\nSum = %d\n", sum);
}