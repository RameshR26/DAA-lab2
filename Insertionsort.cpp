#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};  // given elements
    int n = 6;

    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements greater than key
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    cout << "Sorted array:\n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}