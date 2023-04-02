#include <iostream>
#include "Polynom_Header.h"


CPolynom4::CPolynom4(double a, double b, double c, double d) {
    polynom.a = a;
    polynom.b = b;
    polynom.c = c;
    polynom.d = d;
}
CPolynom4::CPolynom4(SPolynom polynom) {
    this->polynom = polynom;
}
CPolynom4::CPolynom4() {
    this->polynom.a = 1;
    this->polynom.b = 1;
    this->polynom.c = 1;
    this->polynom.d = 1;
}

double CPolynom4::GetResult(double x) {
    return polynom.a * x * x * x + polynom.b * x * x + polynom.c * x + polynom.d;
}
double CPolynom4::GetDerivative(double x) {
    return 3 * polynom.a * x * x + 2 * polynom.b * x + polynom.c;
}
double CPolynom4::GetIntegral(double x1, double x2) {

    return polynom.a * x2 * x2 * x2 * x2 / 4 + polynom.b * x2 * x2 * x2 / 3 + polynom.c * x2 * x2 / 2 + polynom.d * x2
        - (polynom.a * x1 * x1 * x1 * x1 / 4 + polynom.b * x1 * x1 * x1 / 3 + polynom.c * x1 * x1 / 2 + polynom.d * x1);
}
SResult CPolynom4::GetRoots() {
    RootsFinder finder(polynom);
    return finder.FindByDichotomy();
}
SResult CPolynom4::GetRoots(ldouble leftLim, ldouble rightLim) {
    RootsFinder finder(leftLim, rightLim, polynom);
    return finder.FindByDichotomy();
}
SResult CPolynom4::GetRoots(ldouble leftLim, ldouble rightLim, ldouble epsilon) {
    RootsFinder finder(leftLim, rightLim, epsilon, polynom);
    return finder.FindByDichotomy();
}

SPolynom CPolynom4::GetPolynom() {
    return polynom;
}
void CPolynom4::SetPolynom(ldouble a, ldouble b, ldouble c, ldouble d) {
    polynom.a = a;
    polynom.b = b;
    polynom.c = c;
    polynom.d = d;
}
void CPolynom4::SetPolynom(SPolynom polynom) {
    this->polynom = polynom;
}

CPolynom4 CPolynom4::operator + (const CPolynom4& other) {
    double a, b, c, d;

    a = this->polynom.a + other.polynom.a;
    b = this->polynom.b + other.polynom.b;
    c = this->polynom.c + other.polynom.c;
    d = this->polynom.d + other.polynom.d;
    CPolynom4 NewPol(a, b, c, d);

    return NewPol;
}
CPolynom4 CPolynom4::operator - (const CPolynom4& other) {
    double a, b, c, d;

    a = this->polynom.a - other.polynom.a;
    b = this->polynom.b - other.polynom.b;
    c = this->polynom.c - other.polynom.c;
    d = this->polynom.d - other.polynom.d;
    CPolynom4 NewPol(a, b, c, d);

    return NewPol;
}
bool operator == (const CPolynom4& superior, const CPolynom4& other) {
    if (   superior.polynom.a == other.polynom.a
        && superior.polynom.b == other.polynom.b
        && superior.polynom.c == other.polynom.c
        && superior.polynom.d == other.polynom.d
        )
    {
        return true;
    }
    else
        return false;
}
bool operator != (const CPolynom4& superior, const CPolynom4& other) {
    if (   superior.polynom.a != other.polynom.a
        || superior.polynom.b != other.polynom.b
        || superior.polynom.c != other.polynom.c
        || superior.polynom.d != other.polynom.d
        )
    {
        return true;
    }
    else
        return false;
}

ldouble CPolynom4::operator()(const ldouble x) {
    return GetResult(x);
}

CPolynom4 CPolynom4::operator!() {
    return CPolynom4(-this->polynom.a, -this->polynom.b, -this->polynom.c, -this->polynom.d);
}

CPolynom4 operator* (const CPolynom4& superior, const ldouble scalar) {
    double a, b, c, d;

    a = superior.polynom.a * scalar;
    b = superior.polynom.b * scalar;
    c = superior.polynom.c * scalar;
    d = superior.polynom.d * scalar;
    CPolynom4 NewPol(a, b, c, d);

    return NewPol;
}

ostream& operator << (ostream& os, const CPolynom4& superior) {
    os << endl << endl << "(" << superior.polynom.a << ")x^3 + (" << superior.polynom.b << ")x^2 + (" << superior.polynom.c << ")x + (" << superior.polynom.d << ")" << endl << endl;
    return os;
}

istream& operator >> (istream& is, CPolynom4& superior) {
    is >> superior.polynom.a >> superior.polynom.b >> superior.polynom.c >> superior.polynom.d;
    return is;
}

ldouble& CPolynom4::operator [](int index) {
    while (true) {

        switch (index)
        {
        case 0:
            return this->polynom.a;
            break;
        case 1:
            return this->polynom.b;
            break;
        case 2:
            return this->polynom.c;
            break;
        case 3:
            return this->polynom.d;
            break;
        default:
            if (index < 0)
                index += 4;
            else
                index -= 4;
            break;
        }
    }
}