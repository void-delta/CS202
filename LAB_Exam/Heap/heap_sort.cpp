#include <iostream>
#include <algorithm>
using namespace std;

void max_heapify(int *arr, int n, int i){
    int large = i;
    int left_ch = 2*i + 1;
    int right_ch = 2*i + 2;

    if(left_ch < n && arr[left_ch] > arr[large])
        large = left_ch;
    if(right_ch < n && arr[right_ch] > arr[large])
        large = right_ch;
    if(large != i){
        int t = arr[i];
        arr[i] = arr[large];
        arr[large] = t;
        max_heapify(arr, n, large);
    }
}

void heap_sort(int *arr, int n){
    for(int i = n/2 - 1; i >= 0; i--){
        max_heapify(arr, n, i);
    }
    for(int i = n - 1; i > 0; i--){
        int t = arr[0];
        arr[0] = arr[i];
        arr[i] = t;
        max_heapify(arr, i, 0);
    }
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        arr[i] = t;
    }
    heap_sort(arr, n);
}