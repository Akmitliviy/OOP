#pragma once
#include "..\Lib\RootsHeader.h"

class  CPolynom4 {
private:
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

    CPolynom4 operator + (const CPolynom4& other);
    CPolynom4 operator - (const CPolynom4& other);
    bool operator == (const CPolynom4& other);
    bool operator != (const CPolynom4& other);
};
