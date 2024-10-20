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

    for (int i = 0; i < 4; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            if (a[i] > a[j])
                swap(a[i], a[j]);
        }
    }

    for (int i = 0; i < 5; ++i)
        cout << a[i] << " ";
    cout << endl;
}
