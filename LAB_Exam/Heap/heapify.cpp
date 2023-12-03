#include <iostream>
#include <algorithm>
using namespace std;

void max_heapify(int *arr, int n, int k){
    int large = k;
    int left_ch = 2*k + 1;
    int right_ch = 2*k + 2;
    if(left_ch < n && arr[left_ch] > arr[large])
        large = left_ch;
    if(right_ch < n && arr[right_ch] > arr[large])
        large = right_ch;
    if(large != k){
        int t = arr[large];
        arr[large] = arr[k];
        arr[k] = t;
        max_heapify(arr, n, large);
    }
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
    max_heapify(arr, n, 0);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}