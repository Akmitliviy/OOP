#include <iostream>
using namespace std;

class CTriangle {
public:
    CTriangle() {

        m_first_side = 0;
        m_second_side = 0;
        m_third_side = 0;
        m_square = 0;
        m_radius = 0;
    }
    CTriangle(double square) {
        m_square = square;
        m_first_side = 0;
        m_second_side = 0;
        m_third_side = 0;
        m_radius = 0;
    }
    CTriangle(double first_side, double second_side, double third_side) {
        m_first_side = first_side;
        m_second_side = second_side;
        m_third_side = third_side;
        m_radius = 0;

        double p = (first_side + second_side + third_side) / 2;
        m_square = sqrt(p * (p - first_side) * (p - second_side) * (p - third_side));
    }
    CTriangle(const CTriangle& other) {
        this->m_first_side = other.m_first_side;
        this->m_second_side = other.m_second_side;
        this->m_third_side = other.m_third_side;
        this->m_square = other.m_square;
        this->m_radius = other.m_radius;
    }

    double FindRadiusOfInnerCircle(double closer_to_base, double closer_to_same, double square) {
        m_square = square;

        double x = pow(pow(m_square, 2) / (pow(closer_to_base, 2) * (pow(closer_to_base + closer_to_same, 2) - pow(closer_to_base, 2))), 0.25);

        m_first_side = m_second_side = x * (closer_to_base + closer_to_same);
        m_third_side = 2 * closer_to_base * x;

        double p = (m_first_side + m_second_side + m_third_side) / 2;
        double radius = square / p;

        m_radius = radius;
        return radius;
    }

    bool operator<(const CTriangle& other) {
        if (this->m_radius < other.m_radius)
            return true;
        return false;
    }
    bool operator<=(const CTriangle& other) {
        if (this->m_radius <= other.m_radius)
            return true;
        return false;
    }
    bool operator>(const CTriangle& other) {
        if (this->m_radius > other.m_radius)
            return true;
        return false;
    }
    bool operator>=(const CTriangle& other) {
        if (this->m_radius >= other.m_radius)
            return true;
        return false;
    }
    bool operator==(const CTriangle& other) {
        if (this->m_radius == other.m_radius)
            return true;
        return false;
    }
    bool operator!=(const CTriangle& other) {
        if (this->m_radius == other.m_radius)
            return true;
        return false;
    }

    double GetRadius() { return m_radius; }
    double GetSquare() { return m_square; }

private:

    //Тут немає що виділяти динамічно)
    double m_first_side;
    double m_second_side;
    double m_third_side;
    double m_square;
    double m_radius;
};

int main()
{
    CTriangle tr_1, tr_2, tr_3;

    tr_1.FindRadiusOfInnerCircle(12, 25, 1680);
    tr_2.FindRadiusOfInnerCircle(17, 22, 1680);
    tr_3.FindRadiusOfInnerCircle(22, 17, 1680);

    CTriangle tr_4(tr_3);
    cout << "Relation 12/25";

    if (tr_1 > tr_2)
        cout << " > ";
    else
        cout << " < ";
    cout << "17/22\n\n";

    cout << "Relation 12/25 ";

    if (tr_1 > tr_4)
        cout << " > ";
    else
        cout << " < ";
    cout << "22/17\n\n";
}
