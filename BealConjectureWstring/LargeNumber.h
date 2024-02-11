#pragma once
#include <vector>
#include <iostream>



using namespace std;

int maxNumber = 10000;



vector<int> Add(vector<int> x, vector<int> y) {
    vector<int> z;
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    int carry = 0;
    int min_len = min(x.size(), y.size());
    int max_len = max(x.size(), y.size());

    for (int i = 0; i < min_len; i++)
    {
        int Psum = x[i] + y[i] + carry;
        carry = Psum / maxNumber;
        z.push_back(Psum % maxNumber);
    }

    if (x.size() > y.size())
    {
        for (int i = min_len; i < x.size(); i++)
        {
            int Psum = x[i] + carry;
            carry = Psum / maxNumber;
            z.push_back(Psum % maxNumber);
        }
    }

    if (x.size() < y.size())
    {
        for (int i = min_len; i < y.size(); i++)
        {
            int Psum = y[i] + carry;
            carry = Psum / maxNumber;
            z.push_back(Psum % maxNumber);
        }
    }

    while (carry)
    {
        z.push_back(carry % maxNumber);
        carry = carry / maxNumber;
    }

    while (z[z.size() - 1] == 0)
    {
        z.pop_back();
    }

    reverse(z.begin(), z.end());
    return z;
}

vector<int> Add(vector<int> x, int y) {
    vector<int> z;
    reverse(x.begin(), x.end());
    int carry = 0;

    for (int i = 0; i < x.size(); i++)
    {
        int Psum;
        if (i == 0)
            Psum = x[i] + y + carry;
        else
            Psum = x[i] + carry;
        carry = Psum / maxNumber;
        z.push_back(Psum % maxNumber);
    }

    while (carry)
    {
        z.push_back(carry % maxNumber);
        carry = carry / maxNumber;
    }

    while (z[z.size() - 1] == 0)
    {
        z.pop_back();
    }

    reverse(z.begin(), z.end());
    return z;
}

vector<int> Multiply(vector<int> x, vector<int> y) {
    vector<int> z;
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    int  max = -4;

    z.push_back(0);

    for (int i = 0; i < x.size(); i++) {
        for (int j = 0; j < y.size(); j++) {
            if (i + j > max) {
                z.push_back(0);
            }
            z[i + j] += x[i] * y[j];
            z[i + j + 1] = z[i + j + 1] + (z[i + j] / maxNumber);
            z[i + j] = z[i + j] % maxNumber;
            max = i + j;
        }
    }

    while (z[z.size() - 1] == 0)
    {
        z.pop_back();
    }

    reverse(z.begin(), z.end());



    return z;
}

vector<int> Multiply(vector<int> x, int y) {
    vector<int> z;
    int carry = 0, max = -4;
    reverse(x.begin(), x.end());
    z.push_back(0);

    for (int i = 0; i < x.size(); i++) {
        if (i > max) {
            z.push_back(0);
        }
        z[i] += x[i] * y;
        z[i + 1] = z[i + 1] + (z[i] / maxNumber);
        z[i] = z[i] % maxNumber;
        max = i;
    }

    while (carry)
    {
        z.push_back(carry % maxNumber);
        carry = carry / maxNumber;
    }

    while (z[z.size() - 1] == 0)
    {
        z.pop_back();
    }

    reverse(z.begin(), z.end());
    return z;
}

vector<int> Divide(vector<int> x, int y) {
    vector<int> z;
    int divident = 0, remainder = 0;

    for (int i = 0; i < x.size(); i++) {
        divident = remainder * maxNumber + x[i];
        z.push_back(divident / y);
        remainder = divident % y;
    }
    return z;
}

bool Greater(vector<int> x, vector<int> y) {
    if (y.size() > x.size())
        return false;
    else if (y.size() < x.size())
        return true;
    else {
        for (int i = 0; i < x.size(); i++) {
            if (x[i] > y[i])
                return true;
        }
        return false;
    }
}


template<typename T>
class Large {
public:
    vector<T> V;

    Large(long long A) {
        while (A > 0) {
            V.push_back(A % maxNumber);
            A = A / maxNumber;
            reverse(V.begin(), V.end());
            cout << A;

        }
    }



    Large<int> operator + (const Large<int>& v2) {
        Large<int> temp;
        temp.V = Add(this->V, v2.V);;
        return temp;
    }
    Large<int> operator + (const int& v2) {
        Large<int> temp;
        temp.V = Add(this->V, v2);;
        return temp;
    }
    Large<int> operator * (const Large<int>& v2) {
        Large<int> temp;
        temp.V = Multiply(this->V, v2.V);;
        return temp;
    }
    Large<int> operator * (const int& v2) {
        Large<int> temp;
        temp.V = Multiply(this->V, v2);;
        return temp;
    }

    Large<int> operator / (const int& v2) {
        Large<int> temp;
        temp.V = Divide(this->V, v2);
        return temp;
    }

    bool operator ==(const Large<int> v2) {
        if (this->V.size() != v2.V.size())
            return false;
        for (int i = 0; i < v2.V.size(); i++) {
            if (this->V[i] != v2.V[i])
                return false;
        }
        return true;
    }
    bool operator >(const Large<int> v2) {
        return Greater(this->V, v2.V);
    }


    Large() {

    }
    ~Large() {

    }

private:

};



int countDigit(int n) {
    if (n == 0) {
        return 1;
    }
    return floor(log10(n) + 1);
}








Large<int> Power(int base, int exponent) {
    Large<int> Po;
    vector<int> Number;
    if (base == 0) {
        Number.push_back(0);
        Po.V = Number;
        return Po;
    }
    if (exponent == 0 || base == 1) {
        Number.push_back(1);
        Po.V = Number;
        return Po;
    }

    else if (exponent % 2 == 0) {
        Large<int> half__pow = Power(base, exponent / 2);
        return half__pow * half__pow;
    }
    else {
        return Power(base, exponent - 1) * base;
    }
}


