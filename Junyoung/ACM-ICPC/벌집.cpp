// https://www.acmicpc.net/problem/2292

#include <stdio.h>
 
int main() {
    int num;
    int start = 1, dif = 6;
    int dist = 1;
    scanf("%d", &num);
 
    while (num > start) {
        start += dist * dif;
        dist++;
    }
    printf("%d", dist);
    return 0;
}