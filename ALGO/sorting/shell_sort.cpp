#include <bits/stdc++.h>
#define SIZE 8
using namespace std;

int main() {
    srand(time(NULL));
    int a[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        a[i] = rand() % 10 + 1;
        cout << a[i] << " ";
    }
    cout << endl;

    int gap = SIZE / 2, k = 1;
    for (gap; gap > 0; gap /= 2) {
        for (int i = gap ; i < 8; ++i) {
            int tmp = a[i], j;
            for (j = i; j >= gap && tmp < a[j-gap]; j -= gap) 
                a[j] = a[j-gap];
            a[j] = tmp;
        }
        cout << k++ << " : ";
        for (int r = 0; r < 8; ++r)
            cout << a[r] << " ";
        cout << endl;
    }
}
