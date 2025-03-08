#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long maximizeNumber(unsigned long long num) {
		int digitCount[10] = {0};

		if (num == 0) return 0;

		unsigned long long temp = num;
		while (temp > 0) {
				digitCount[temp % 10]++;
				temp /= 10;
		}

		unsigned long long result = 0;
		for (int i = 9; i >= 0; i--) {
				while (digitCount[i] > 0) {
						result = result * 10 + i;
						digitCount[i]--;
				}
		}

		return result;
}

int main(int argc, char *argv[]) {
		if (argc != 2) {
				printf("Usage: %s <array_size>\n", argv[0]);
				return 1;
		}

		int n = atoi(argv[1]);
		if (n <= 0) {
				printf("Array size must be a positive integer.\n");
				return 1;
		}

		srand(time(NULL));

		unsigned long long *arr = (unsigned long long *)malloc(n * sizeof(unsigned long long));
		if (arr == NULL) {
				printf("Memory allocation failed.\n");
				return 1;
		}

		printf("Original array:\n");
		for (int i = 0; i < n; i++) {
				int numDigits = rand() % 9 + 1;
				arr[i] = 0;
				for (int j = 0; j < numDigits; j++) {
						int digit = (j == 0) ? (rand() % 9 + 1) : (rand() % 10);
						arr[i] = arr[i] * 10 + digit;
				}
				printf("%llu ", arr[i]);
		}
		printf("\n");

		printf("Maximized array:\n");
		for (int i = 0; i < n; i++) {
				unsigned long long maximized = maximizeNumber(arr[i]);
				printf("%llu ", maximized);
		}
		printf("\n");

		free(arr);

		return 0;
}