/* 문제: 10808
#include <stdio.h>
#include <string.h>

int main(void) {
	char s[100] = { 0 };
	scanf("%s", s);
	char letter[26] = { 0 };

	for (int i = 0; i < strlen(s); i++) {
		for (int j = 0; j < 26; j++) {
			if (s[i] - 'a' == j) {
				letter[j]++;
			}
		}
	}

	for (int i = 0; i < 26; i++) {
		printf("%d ", letter[i]);
	}

	return 0;
}
*/
