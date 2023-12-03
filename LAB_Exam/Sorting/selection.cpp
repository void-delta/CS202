#include <iostream>
#include <algorithm>
using namespace std;

void selection_sort(int *arr, int n){
    for(int i = 0; i < n; i++){
        int min_index = i;
        for(int j = i; j < n; j++){
            if(arr[j] < arr[min_index])
                min_index = j;
        }
        if(min_index != i){
            int t = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = t;
        }
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
    // sort(array, array + n);
    selection_sort(array, n);
}