#include <stdio.h>

/* 문제: 10871
int main(void) {
	int n, x;
	scanf("%d %d", &n, &x);

	int num;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &num);
		if (num < x) printf("%d ", num);
	}
	return 0;
}
*/

/* 문제: 2309 
int main(void) {
	int height[9];
	int sum = 0;
	int over = 0;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &height[i]);
		sum = sum + height[i];
	}
	over = sum - 100;

	int a = 0;
	int b = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (height[i] + height[j] == over) {
				a = i;
				b = j;
				break;
			}
		}
	}

	int tmp;
	int dwarf[7];
	int c = 0;
	for (int i = 0; i < 9; i++) {
		if (i != a && i != b) {
			dwarf[c] = height[i];
			c++;
		}
	}


	for (int i = 0; i < 7; i++) {
		for (int j = i + 1; j < 7; j++) {
			if (dwarf[i] > dwarf[j]) {
				tmp = dwarf[i];
				dwarf[i] = dwarf[j];
				dwarf[j] = tmp;
			}
		}
	}

	for (int i = 0; i < 7; i++) {
		printf("%d\n", dwarf[i]);
	}

	return 0;
}
*/
