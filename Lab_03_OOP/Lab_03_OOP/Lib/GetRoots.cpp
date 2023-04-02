#include <iostream>
#include "RootsHeader.h"

ldouble RootsFinder::f(ldouble x) {
    return polynom.a * x * x * x + polynom.b * x * x + polynom.c * x + polynom.d;
}

int RootsFinder::D(SPolynom pol) {
    int result = 0;
    ldouble D = 0;
    if (fabs(pol.a) <= 0.000000000000001) {
        if (fabs(pol.b) <= 0.000000000000001 && fabs(pol.c) <= 0.000000000000001) {
            result = 0;
            cout << "Equation has no roots" << endl << endl;
        }
        else if (fabs(pol.b) <= 0.000000000000001) {
            result = 1;
        }
        else {
            D = pol.c * pol.c - 4 * pol.b * pol.d;

            if (D < 0)
                result = 0;
            else if (fabs(D) < 0.000000000000001)
                result = 1;
            else
                result = 2;
        }
    }
    else if (fabs(pol.a) > 0.000000000000001 && fabs(pol.b) <= 0.000000000000001 && fabs(pol.c) <= 0.000000000000001 && fabs(pol.d) <= 0.000000000000001) {
        result = 1;
    }
    else {
        ldouble r = pol.b / pol.a, s = pol.c / pol.a, t = pol.d / pol.a;
        ldouble p = (3 * s - r * r) / 3, q = (2 * r * r * r) / 27 - r * s / 3 + t;
        D = p * p * p / 27 + q * q / 4;
        if (D > 0)
            result = 1;
        else if (fabs(D) < 0.000000000000001)
            result = 2;
        else
            result = 3;
    }

    return result;
}

ldouble RootsFinder::FindSecant(ldouble leftLim, ldouble rightLim) {
    return leftLim - (f(leftLim) * (rightLim - leftLim)) / (f(rightLim) - f(leftLim));
}

SResult RootsFinder::FindBySecant() {
    ldouble savedRightLim = rightLim;
    bool resultIsFound = false, isFirst = true;
    while (numOfRoots) {

        resultIsFound = SetLimits(isFirst);
        isFirst = false;

        if (!result.num)
            break;

        if (resultIsFound) {
            result.roots[numOfRoots - 1] = leftLim;
        }
        else {
            result.roots[numOfRoots - 1] = FindSecant(leftLim, rightLim);

            ldouble staticPoint = 0;
            ldouble xPrev = result.roots[numOfRoots - 1];
            while (!resultIsFound) {

                if (f(result.roots[numOfRoots - 1]) * f(leftLim) <= 0)
                    staticPoint = leftLim;
                else
                    staticPoint = rightLim;

                xPrev = result.roots[numOfRoots - 1];
                result.roots[numOfRoots - 1] = FindSecant(result.roots[numOfRoots - 1], staticPoint);

                if (fabs(result.roots[numOfRoots - 1] - xPrev) <= eps)
                    resultIsFound = true;
            }
        }
        numOfRoots--;
        resultIsFound = false;
        leftLim = rightLim;
        rightLim = savedRightLim;
    }
    return result;
}

SResult RootsFinder::FindByDichotomy()
{
    ldouble midLim = 0, savedRightLim = rightLim;
    bool BordersAreSetting = true, resultIsFound = false, isFirst = true;
    while (numOfRoots) {

        resultIsFound = SetLimits(isFirst);
        isFirst = false;

        if (!result.num)
            break;

        if (resultIsFound)
            midLim = leftLim;

        while (!resultIsFound) {

            midLim = (leftLim + rightLim) / 2;
            if (f(leftLim) * f(midLim) <= 0) {
                rightLim = midLim;
            }
            else {
                leftLim = midLim;
            }

            midLim = (leftLim + rightLim) / 2;
            if (fabs(leftLim - rightLim) < eps)
                resultIsFound = true;

        }
        result.roots[numOfRoots - 1] = midLim;
        numOfRoots--;
        resultIsFound = false;
        leftLim = rightLim;
        rightLim = savedRightLim;
    }
    return result;
}

bool RootsFinder::SetLimits(bool isFirst) {
    bool onGoing = true, resultIsFound = false;
    ldouble step = (fabs(leftLim) + fabs(rightLim)) / 10, fX = 0, fLeft = 0;

    if (leftLim > rightLim) {
        ldouble temp = leftLim;
        leftLim = rightLim;
        rightLim = temp;
    }

    if (step >= 1)
        step = 1;

    fLeft = f(leftLim);
    if (fLeft == 0 && isFirst) {
        resultIsFound = true;
        onGoing = false;
    }

    while (onGoing) {

        for (ldouble x = leftLim + step; x < rightLim; x += step) {
            fX = f(x);

            if (fabs(fX) <= eps) {
                leftLim = x;
                ldouble k = x + eps;
                while (fabs(k) <= eps)
                    k += eps;
                rightLim = k;
                resultIsFound = true;
                onGoing = false;
                break;
            }

            if (fLeft * fX <= 0) {
                leftLim = x - step;
                rightLim = x;
                onGoing = false;
                break;
            }

            fLeft = fX;
        }
        step /= 10;
        if (step <= eps) {
            result.num = 0;
            result.roots[0] = NULL;
            result.roots[1] = NULL;
            result.roots[2] = NULL;
            cout << "There are no roots in range [" << uLeft << "; " << uRight << "], or not all of them. Please, set your range" << endl << endl;
            onGoing = false;

        }
    }

    return resultIsFound;
}

RootsFinder::RootsFinder(SPolynom polynom) {
    this->leftLim = -100;
    this->rightLim = 100;
    this->polynom = polynom;
    eps = 0.000001;
    uLeft = leftLim;
    uRight = rightLim;
    result.roots[0] = NAN;
    result.roots[1] = NAN;
    result.roots[2] = NAN;
    result.num = D(polynom);
    numOfRoots = result.num;
}

RootsFinder::RootsFinder(ldouble leftLim, ldouble rightLim, SPolynom polynom) {
    this->leftLim = leftLim;
    this->rightLim = rightLim;
    this->polynom = polynom;
    eps = 0.000001;
    uLeft = leftLim;
    uRight = rightLim;
    result.roots[0] = NAN;
    result.roots[1] = NAN;
    result.roots[2] = NAN;
    result.num = D(polynom);
    numOfRoots = result.num;
}

RootsFinder::RootsFinder(ldouble leftLim, ldouble rightLim, ldouble epsilon, SPolynom polynom) {
    this->leftLim = leftLim;
    this->rightLim = rightLim;
    this->polynom = polynom;
    eps = epsilon;
    uLeft = leftLim;
    uRight = rightLim;
    result.roots[0] = NAN;
    result.roots[1] = NAN;
    result.roots[2] = NAN;
    result.num = D(polynom);
    numOfRoots = result.num;
}