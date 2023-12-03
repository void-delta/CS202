#include <iostream>
#include <algorithm>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int l, int h){
    int pivot = arr[h];
    int i = l - 1;

    for(int j = l; j < h; j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return i + 1;
}

void quick_sort(int *arr, int l, int h){
    if(l < h){
        int par = partition(arr, l, h);
        quick_sort(arr, l, par - 1);
        quick_sort(arr, par + 1, h);
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
    quick_sort(arr, 0, n - 1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";

    // Free dynamically allocated memory
    delete[] arr;

    return 0;
}
