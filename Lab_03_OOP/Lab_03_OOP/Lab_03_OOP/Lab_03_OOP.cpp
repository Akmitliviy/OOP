#include <iostream>
#include <cassert>
#include "PolynomHeader.h"


    CPolynom4::CPolynom4(double a, double b, double c, double d) {
        assert(a > 0);
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
    bool CPolynom4::operator == (const CPolynom4& other) {
        if (   this->polynom.a == other.polynom.a
            && this->polynom.b == other.polynom.b
            && this->polynom.c == other.polynom.c
            && this->polynom.d == other.polynom.d
           ) 
        {
            return true;
        }
        else
            return false;
    }
    bool CPolynom4::operator != (const CPolynom4& other) {
        if (   this->polynom.a != other.polynom.a
            || this->polynom.b != other.polynom.b
            || this->polynom.c != other.polynom.c
            || this->polynom.d != other.polynom.d
            )
        {
            return true;
        }
        else
            return false;
    }