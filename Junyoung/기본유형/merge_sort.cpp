#include <cstdio>
using namespace std;

const int MAX_N = 1000000;
 
int arr[MAX_N];
int temp[MAX_N];
  
void merge_sort(int* arr, int l, int r) {
    int len = r-l+1;
    int m = (l + r) / 2;
  
    // divide
    if (len > 2) {
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
    }
    // merge & sort (conquer)
    int i = l, j = m+1, k = 0;
  
    while (i <= m && j <= r)
        temp[k++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
    while (i <= m)
        temp[k++] = arr[i++];
    while (j <= r)
        temp[k++] = arr[j++];
      
    // commit
    for (int i = 0; i < len; i++){
        arr[l+i] = temp[i];
	}
}
  
int main() {
    int N;
      
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    merge_sort(arr, 0, N-1);
  
    for (int i = 0; i < N; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}
