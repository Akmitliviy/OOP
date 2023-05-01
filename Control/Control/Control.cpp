#include <iostream>

using namespace std;

class CVector;

int ReturnIntValue(const CVector& vector) {
    return vector.m_size;
}

class CVector {
public:
    CVector() = delete;
    CVector(const size_t size) {
        m_size = size;
        m_vector = new double[m_size];

        for (int i = 0; i < m_size; i++)
            m_vector[i] = 0;
    }
    CVector(const double* arr, const size_t size) {

        m_size = size;
        m_vector = new double[m_size];
        for (int i = 0; i < m_size; i++) {

            m_vector[i] = arr[i];
        }
    }
    CVector(const CVector& other) {

        this->m_size = other.m_size;
        this->m_vector = new double[this->m_size];
        for (int i = 0; i < m_size; i++) {
            this->m_vector[i] = other.m_vector[i];
        }
    }
    ~CVector() {

        m_size = 0;
        if (m_vector) {
            delete[] m_vector;
            m_vector = nullptr;
        }
    }

    CVector& operator=(const CVector& other) {

        this->m_size = other.m_size;
        
        if (this->m_vector) {
            delete[] this->m_vector;
            this->m_vector = nullptr;
        }

        this->m_vector = new double[this->m_size];
        for (int i = 0; i < m_size; i++) {
            this->m_vector[i] = other.m_vector[i];
        }

        return *this;
    }
    CVector operator+(const CVector& other) {
        const size_t size = this->m_size + other.m_size;

        double* temp_vec = new double[size];

        for (int i = 0; i < this->m_size; i++) {
            temp_vec[i] = this->m_vector[i];
        }

        for (int i = 0; i < other.m_size; i++) {
            temp_vec[this->m_size + i] = other.m_vector[i];
        }

        CVector temp(temp_vec, size);

        return temp;
    }
    operator double() {
        return m_size;
    }
    friend int ReturnIntValue(const CVector& vector);

    void PrintVector() {

        for (int i = 0; i < m_size; i++) {

            cout << m_vector[i] << "\t";
        }
        cout << endl << endl;
    }

private:
    size_t m_size;
    double* m_vector;
};

int main() {
    int a{ 0 }, b{ 8 }, c;

    c = a + b;
    

    cout << double(b);



    CVector vector(5);
    const size_t size = 8;
    double arr[size] = { 4,6,3,6,2,1,3,9 };

    CVector vector1(arr, size);
    for (int i = 0; i < 8; i++) {

        cout << "Exelent";
        CVector vector3(100000000);
    }
    CVector vector4(vector1);
    vector.PrintVector();
    vector1.PrintVector();
    return 0;
}