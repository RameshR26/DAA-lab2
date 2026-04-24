#include <iostream>
using namespace std;

// Merge two subarrays
void merge(int arr[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = 0;

    int temp[100]; // temporary array

    while(i <= mid && j <= right) {
        if(arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i <= mid)
        temp[k++] = arr[i++];

    while(j <= right)
        temp[k++] = arr[j++];

    // Copy back to original array
    for(int p = 0; p < k; p++)
        arr[left + p] = temp[p];
}

// Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10}; // given elements
    int n = 7;

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array:\n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}