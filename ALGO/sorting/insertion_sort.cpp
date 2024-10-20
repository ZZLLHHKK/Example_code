#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(NULL));
    int a[5];
    for (int i = 0; i < 5; ++i) {
        a[i] = rand() % 10 + 1;
        cout << a[i] << " ";
    }
    cout << endl;

    for (int i = 1; i < 5; ++i) {
        int tmp = a[i];
        int j = i - 1;
        while (j >= 0 && tmp < a[j]) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = tmp;
        cout << i << " : ";
        for (int i = 0; i < 5; ++i)
            cout << a[i] << " ";
        cout << endl;
    }
}
