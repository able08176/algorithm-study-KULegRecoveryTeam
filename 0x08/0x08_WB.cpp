/* 문제: 10799
#include <stdio.h>
#define MAX 100001
int main(){
    char stack[MAX];
    int top = 0, result = 0;
    scanf("%s", stack);
    for (int i = 0; stack[i] != '\0'; i++)
        if (stack[i] == '(')
            top++;
        else{
            if (i > 0 && stack[i-1] == '(')
                result += --top;
            else{
                result++;
                top--;
            }
        }
    printf("%d\n", result);
}
*/
