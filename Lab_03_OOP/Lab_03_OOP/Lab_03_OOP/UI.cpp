//#include <iostream>
//#include "PolynomHeader.h"
//
//int main() {
//
//    cout << "Crearting object 'my' of CPolynom4 class using base constructor" << endl;
//    CPolynom4 my;
//    SPolynom p = my.GetPolynom();
//    cout << "It's private field, accessed via getter: (" << p.a << ", " << p.b << ", " << p.c << ", " << p.d << ")" << endl;
//    cout << "It's result if x = 3: " << my.GetResult(3) << endl << endl;
//
//    cout << "Crearting object 'custom' of CPolynom4 class and passing values of polynom via constructor parameters" << endl;
//    CPolynom4 custom(1, -4, -7, 10);
//    p = custom.GetPolynom();
//    cout << "It's private field, accessed via getter: (" << p.a << ", " << p.b << ", " << p.c << ", " << p.d << ")" << endl;
//    cout << "It's result if x = 1: " << custom.GetResult(1) << endl << endl;
//
//    cout << "Crearting object 'sum' of CPolynom4 class and initializing it by sum of 'my' and 'custom' fields" << endl;
//    CPolynom4 sum = my + custom;
//    p = sum.GetPolynom();
//    cout << "It's private field, accessed via getter: (" << p.a << ", " << p.b << ", " << p.c << ", " << p.d << ")" << endl;
//    cout << "It's derivative if x = 2: " << sum.GetDerivative(2) << endl << endl;
//    
//    cout << "Assigning to custom value of 'my' - 'custom' fields" << endl;
//    custom = my - custom;
//    p = custom.GetPolynom();
//    cout << "It's private field, accessed via getter: (" << p.a << ", " << p.b << ", " << p.c << ", " << p.d << ")" << endl;
//    cout << "It's integral if x1 = 0, x2 = 1: " << custom.GetIntegral(0, 1) << endl << endl;
//
//    cout << "Trying to find roots for 'custom' via standard function: " << endl;
//    SResult res = custom.GetRoots();
//    if (res.num) {
//        cout << "Result: ";
//        for (int i = res.num; i > 0; i--)
//            cout << res.roots[i - 1] << "\t";
//        cout << endl << endl;
//    }
//
//
//    cout << "Trying to find roots for 'custom' setting own borders ([-15; 20]): " << endl;
//    res = custom.GetRoots(-15, 20);
//    if (res.num) {
//        cout << "Result: ";
//        for (int i = res.num; i > 0; i--)
//            cout << res.roots[i - 1] << "\t";
//        cout << endl << endl;
//    }
//
//    cout << "Trying to find roots for 'custom' setting own borders ([-15; 20]) and epsilon (0.01): " << endl;
//    res = custom.GetRoots(-15, 20, 0.01);
//    if (res.num) {
//        cout << "Result: ";
//        for (int i = res.num; i > 0; i--)
//            cout << res.roots[i - 1] << "\t";
//        cout << endl << endl;
//    }
//
//
//	return 0;
//}