#include <bits/stdc++.h>
using namespace std;

class A {
private:
    int x;
public:
    A() {
        cout << "object A construct." << endl;
    }
    A(int _x) : x(_x) {}
    ~A() {
        cout << "object A destroyed." << endl;
    }
    void setX(int _x) {
        x = _x;
    }
    int getX() {
        return x;
    }
    void display() {
        cout << "object A has a value integer " << getX() << endl;
    }
};

int main() {
    int t;
    cin >> t;

    A a;
    a.setX(t);
    a.display();
}
