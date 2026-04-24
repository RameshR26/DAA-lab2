#include <iostream>
using namespace std;

#define LEFT -1
#define RIGHT 1

// Structure for element with direction
struct Element {
    int value;
    int dir;
};

// Find largest mobile element
int getMobile(Element a[], int n) {
    int mobile = 0;
    int mobileIndex = -1;

    for(int i = 0; i < n; i++) {
        int next = i + a[i].dir;

        if(next >= 0 && next < n && a[i].value > a[next].value) {
            if(a[i].value > mobile) {
                mobile = a[i].value;
                mobileIndex = i;
            }
        }
    }
    return mobileIndex;
}

// Print current permutation
void printPermutation(Element a[], int n) {
    for(int i = 0; i < n; i++)
        cout << a[i].value << " ";
    cout << endl;
}

void johnsonTrotter(int n) {
    Element a[10];

    // Initialize
    for(int i = 0; i < n; i++) {
        a[i].value = i + 1;
        a[i].dir = LEFT;
    }

    printPermutation(a, n);

    while(true) {
        int mobileIndex = getMobile(a, n);

        if(mobileIndex == -1)
            break;

        int swapIndex = mobileIndex + a[mobileIndex].dir;

        // Swap
        Element temp = a[mobileIndex];
        a[mobileIndex] = a[swapIndex];
        a[swapIndex] = temp;

        // Change direction of larger elements
        for(int i = 0; i < n; i++) {
            if(a[i].value > a[swapIndex].value)
                a[i].dir *= -1;
        }

        printPermutation(a, n);
    }
}

int main() {
    int n = 3;  // number of elements

    cout << "Permutations:\n";
    johnsonTrotter(n);

    return 0;
}