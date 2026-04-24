#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50}; // given elements
    int n = 5;
    int key = 30; // element to search

    int found = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            cout << "Element found at position: " << i + 1;
            found = 1;
            break;
        }
    }

    if(found == 0)
        cout << "Element not found";

    return 0;
}