#include <iostream>
#include <algorithm>
using namespace std;

void insertion_sort(int *arr, int n){
    int key;
    for(int i = 0; i < n; i++){
        key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main(){
    int n;
    cin >> n;
    int *array = new int[n];
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        array[i] = temp;
    }
    insertion_sort(array, n);
}