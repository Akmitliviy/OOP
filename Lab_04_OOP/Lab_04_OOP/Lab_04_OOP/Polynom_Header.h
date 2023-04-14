#pragma once
#include <iostream>
#include "RootsHeader.h"

class  CPolynom4 {
private:
    static int number_of_objects;
    SPolynom polynom;
public:
    CPolynom4(double a, double b, double c, double d);
    CPolynom4(SPolynom polynom);
    CPolynom4();

    double GetResult(double x);
    double GetDerivative(double x);
    double GetIntegral(double x1, double x2);
    SResult GetRoots();
    SResult GetRoots(ldouble leftLim, ldouble rightLim);
    SResult GetRoots(ldouble leftLim, ldouble rightLim, ldouble epsilon);

    SPolynom GetPolynom();
    void SetPolynom(ldouble a, ldouble b, ldouble c, ldouble d);
    void SetPolynom(SPolynom polynom);

    static int GetNumOfObjects() {
        return number_of_objects;
    }

    CPolynom4 operator + (const CPolynom4& other);
    CPolynom4 operator - (const CPolynom4& other);
    ldouble operator () (const ldouble x);
    CPolynom4 operator ! ();
    ldouble& operator [] (int index);
    friend ostream& operator << (ostream& os, const CPolynom4& superior);
    friend istream& operator >> (istream& is, CPolynom4& superior);
    friend CPolynom4 operator * (const CPolynom4& superior, const ldouble scalar);
    friend bool operator == (const CPolynom4& superior, const CPolynom4& other);
    friend bool operator != (const CPolynom4& superior, const CPolynom4& other);
};