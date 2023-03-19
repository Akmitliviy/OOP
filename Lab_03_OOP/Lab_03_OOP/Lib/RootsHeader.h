#pragma once
#include <cmath>

using namespace std;

typedef long double ldouble;

typedef struct{
    ldouble a;
    ldouble b;
    ldouble c;
    ldouble d;

} SPolynom;

typedef struct {
    ldouble roots[3];
    int num;

} SResult;

class RootsFinder {
private:
    ldouble leftLim, rightLim, eps, uLeft, uRight;
    SResult result;
    SPolynom polynom;

    ldouble f(ldouble x);
    int D(SPolynom pol);
    ldouble FindSecant(ldouble leftLim, ldouble rightLim);
    bool SetLimits(bool isFirst);
    int numOfRoots;

public:
    RootsFinder(SPolynom polynom);

    RootsFinder(ldouble leftLim, ldouble rightLim, SPolynom polynom);

    RootsFinder(ldouble leftLim, ldouble rightLim, ldouble epsilon, SPolynom polynom);

    SResult FindBySecant();
    SResult FindByDichotomy();

};
