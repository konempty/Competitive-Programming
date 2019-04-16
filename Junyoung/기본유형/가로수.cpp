// https://www.acmicpc.net/problem/2485

#include <stdio.h>
#define MAXTREE 100000

// Euclidean Algorithm
long long get_gcd(long long a, long long b) {
    long long mod;
 
    while ((mod = a%b) > 0) {
        a = b;
        b = mod;
    }
    return b;
}
 
int main() {
    int N;
    long long tree[MAXTREE];
    long long pos, min = 0;
    long long cnt = 0;
 
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &tree[i]);
    }
     
    min = tree[1] - tree[0];
    for (int i = 1; i < N-1; i++) {
        min = get_gcd(min, tree[i+1] - tree[i]);
    }
 
    cnt = (tree[N-1] - tree[0]) / min + 1 - N;
    printf("%lld", cnt);
    return 0;
}