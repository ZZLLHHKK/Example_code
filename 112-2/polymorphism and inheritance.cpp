#include <bits/stdc++.h>
using namespace std;

class Shape {
public:
    Shape() {
        cout << "construct a shape" << endl;
    }
    virtual double area() = 0;
};

class square : public Shape {
protected:
    double length;
public:
    square(double l) : length(l) {}
    double getLength() {
        return length;
    }
    double area() override {
        return getLength() * getLength();
    }
    void display() {
        cout << "This is a Square" << endl;
        cout << "Length : " << getLength() << endl;
    }
};

class rectangle : public Shape {
protected:
    double side, width;
public:
    rectangle(double s, double w) : side(s), width(w) {}
    double getSide() {
        return side;
    }
    double getWidth() {
        return width;
    }
    double area() override {
        return getSide() * getWidth();
    }
    void display() {
        cout << "This is a Rectangle" << endl;
        cout << "Side : " << getSide() << " Width : " << getWidth() << endl;
    }
};

class triangle : public Shape {
protected:
    double s1, s2, s3;
public:
    double S = 0;
    triangle(double _s1, double _s2, double _s3) : s1(_s1), s2(_s2), s3(_s3) {
        S = (_s1 + _s2 + _s3) / 2;
    }
    double getS1() {
        return s1;
    }
    double getS2() {
        return s2;
    }
    double getS3() {
        return s3;
    }
    double area() override {
        return sqrt(S*(S-getS1())*(S-getS2())*(S-getS3()));
    }
    void display() {
        cout << "This is a Triangle" << endl;
        cout << "Side1 : " << getS1() << " Side2 : " << getS2() << " Side3 : " << getS3() << endl;
    }
};

class circle : public Shape {
protected:
    double radius;
public:
    circle(double r) : radius(r) {}
    double getR() {
        return radius;
    }
    double area() override {
        return acos(-1) * radius * radius;
    }
    void display() {
        cout << "This is a Circle" << endl;
        cout << "Radius : " << getR() << endl;
    }
};

void showArea(Shape &s) {
    cout << "Area : " << s.area() << endl;
}

int main() {
    srand(time(NULL));

    double a = rand() % 10 + 1;
    square s(a);
    s.display();
    showArea(s);
    cout << endl;

    double b = rand() % 10 + 1, c = rand() % 10 + 1;
    rectangle rec(b, c);
    rec.display();
    showArea(rec);
    cout << endl;

    double d = rand() % 10 + 1, e = rand() % 10 + 1, f = rand() % 10 + 1;
    triangle t(d, e, f);
    t.display();
    showArea(t);
    cout << endl;

    double g = rand() % 10 + 1;
    circle cir(g);
    cir.display();
    showArea(cir);
    cout << endl;
}
