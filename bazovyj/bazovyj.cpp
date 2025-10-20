// bazovyj.cpp : Defines the entry point for the console application.

#include <iostream>
#include <cmath>
using namespace std;

class Equation {
public:
    virtual void solve() = 0;
    virtual ~Equation() {}
};

class LineEquation : public Equation {
private:
    double a, b;

public:
    LineEquation(double a, double b) : a(a), b(b) {}

    void solve() override {
        if (a == 0) {
            if (b == 0) {
                cout << "Infinite solutions" << endl;
            }
            else {
                cout << "No solution" << endl;
            }
        }
        else {
            double x = -b / a;
            cout << "Linear equation solution: x = " << x << endl;
        }
    }
};

class QuadEquation : public Equation {
private:
    double a, b, c;

public:
    QuadEquation(double a, double b, double c) : a(a), b(b), c(c) {}

    void solve() override {
        if (a == 0) {
            LineEquation lineEq(b, c);
            lineEq.solve();
            return;
        }

        double D = b * b - 4 * a * c;

        if (D < 0) {
            cout << "No real solutions" << endl;
        }
        else if (D == 0) {
            double x = -b / (2 * a);
            cout << "One real solution: x = " << x << endl;
        }
        else {
            double x1 = (-b + sqrt(D)) / (2 * a);
            double x2 = (-b - sqrt(D)) / (2 * a);
            cout << "Two real solutions: x1 = " << x1 << ", x2 = " << x2 << endl;
        }
    }
};

int main() {
    
    double a, b, c;

    cout << "Enter coefficients a, b, c for the quadratic equation (ax^2 + bx + c = 0): ";
    cin >> a >> b >> c;

    Equation* eq = new QuadEquation(a, b, c);
    eq->solve();
    delete eq;

    cout << "\nEnter coefficients a, b for the linear equation (ax + b = 0): ";
    cin >> a >> b;

    eq = new LineEquation(a, b);
    eq->solve();
    delete eq;

}
