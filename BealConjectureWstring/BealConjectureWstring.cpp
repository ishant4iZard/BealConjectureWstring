#include <numeric>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <iomanip> 
#include <thread>
#include "LargeNumber.h"



using namespace std;

ofstream myfile;
vector<vector<int>>  soln;
vector<vector<int>>  soln3;
vector<vector<Large<int>>>  _powr;

void printNum(Large<int> x) {
    myfile << x.V[0];
    for (int i = 1; i < x.V.size(); i++) {
        for (int digits = countDigit(x.V[i]); 4 - digits > 0; digits++)
            myfile << "0";

        myfile << x.V[i];
    }
}

unsigned long long int _pow(unsigned long long int base, unsigned long long int exponent) {
    if (base == 0)
        return 0;
    if (exponent == 0 || base == 1)
        return 1;

    else if (exponent % 2 == 0) {
        unsigned long long int half__pow = _pow(base, exponent / 2);
        return half__pow * half__pow;
    }
    else
        return base * _pow(base, exponent - 1);
}

bool sortcol(const vector<int>& v1, const vector<int>& v2)
{
    return v1 < v2;
}

int GCD(int a, int b) {
    if (a == 0 || b == 0)
    {
        return (a + b);
    }
    return GCD(b, a % b);
}

int CheckBeal(vector<int> set) {
    Large<int> a = _powr[set[0]][set[1]] + _powr[set[2]][set[3]];
    vector<Large<int>> helper = (*(_powr.begin() + set[4]));
    auto it = find(helper.begin(), helper.end(), a);
    if (it != helper.end()) {
        return it - helper.begin();
    }
    return 0;
}

int calcBNT(vector<int> set) {
    int a = 0;
    for (auto i : set) {
        a += i;
    }
    return a;
}

void createSet(int low, int high) {


    vector<int> temp;
    for (int itrA = low; itrA <= high; itrA ++) {
        for (int itrB = 2; itrB <= itrA; itrB++) {
            if (GCD(itrA, itrB) > 1) {
                for (int itrC = 2; itrC <= 40; itrC++) {
                    if (GCD(itrA, GCD(itrB, itrC)) > 1) {
                        for (int itrX = 3; itrX <= 30; itrX++) {
                            for (int itrY = 3; itrY <= itrX; itrY++) {
                                vector<int> a;
                                a.insert(a.end(), { itrA, itrY, itrB, itrX, itrC });
                                int Z = CheckBeal(a);
                                if (Z > 2 && Z <= 30) {
                                    a.push_back(Z);
                                    a.insert(a.begin(), calcBNT(a));
                                    soln.push_back(a);
                                    if (itrA > 2 && itrC > 2 && itrB > 2 &&
                                        itrA < 21 && itrC < 21 && itrB < 21 &&
                                        itrX < 16 && itrY < 16 && Z < 16)
                                        soln3.push_back(a);
                                    break;
                                }

                            }
                        }
                    }
                }
            }
        }
    }

}

void HighestBNT() {
    Large<int> BNT;
    Large<int> power;
    Large<int> Z;
    power = Power(10000, 20000);
    Z = ((power * 2) + 1) / 3;
    BNT = (Z + (power * 2)) + 16;
    myfile << "BNT = ";
    printNum(BNT);
    myfile << "\nA = 4\nX = ";
    printNum(power);
    myfile << "\nB = 4\nY = ";
    printNum(power);
    myfile << "\nC = 8\nZ = ";
    printNum(Z);

}

bool CheckPrime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}

namespace output {
    void printVect(vector<int> V) {
        for (auto j = 0; j < V.size(); j++) {
            if (j == 0)
                myfile << setw(7) << V[j] << ":";
            else if (j == V.size() - 1)
                myfile << setw(7) << V[j];
            else
                myfile << setw(7) << V[j] << ",";
        }
        myfile << endl;

    }

    void Q1() {
        myfile << "Answer to Q1:5 distinct, lowest BNTs\n\n";
        for (int i = 0; i < 5; i++) {
            printVect(soln[i]);
        }
        myfile << "--------------------------------------------------------------------" << endl;

    }

    void Q2() {
        myfile << "Answer to Q2:5 distinct, lowest BNTs that are prime\n";
        int k = 0;
        for (int j = 0; j < soln.size(); j++)
        {
            while (j < soln.size() - 1 && soln[j][0] == soln[j + 1][0])
                j++;
            if (CheckPrime(soln[j][0])) {
                printVect(soln[j]);
                k++;
                if (k == 5)
                    break;
            }
        }
        myfile << "--------------------------------------------------------------------" << endl;

    }

    void Q3() {
        myfile << "Answer to Q3:BNTs for which A, B, C are within the range of 3 to 20, and x, y, and z are within the scope of 3 to 15\n";
        for (int i = 0; i < soln3.size(); i++) {
            printVect(soln3[i]);
        }
        myfile << "--------------------------------------------------------------------" << endl;

    }

    void Q4() {
        myfile << "Answer to Q4:10 distinct, lowest BNTs that are composite\n";
        int k = 0;
        for (int j = 0; j < soln.size(); j++)
        {
            while (j < soln.size() - 1 && soln[j][0] == soln[j + 1][0])
                j++;
            if (!CheckPrime(soln[j][0])) {
                printVect(soln[j]);
                k++;
                if (k == 10)
                    break;
            }
        }        
        myfile << "--------------------------------------------------------------------" << endl;

    }

    void Q5() {
        myfile << "Answer to Q5:BNTs that are square numbers between 1000 and 100000\n";
        for (int i = 32; i < 317; i++) {
            int powa = pow(i, 2);
            if ((powa - 7) % 3 == 0) {
                int a, x;
                vector<int> print;
                a = 2;
                x = (powa - 7) / 3;
                print.insert(print.end(), { powa,a,x,a,x,a,x + 1 });
                printVect(print);
            }
            else if ((powa - 16) % 5 == 0)
            {
                int a, x;
                vector<int> print;
                a = 2;
                x = (2 * powa - 17) / 2;
                print.insert(print.end(), { powa,a,x,a,x,2 * a,(x + 1) / 2 });
                printVect(print);
            }
            else if ((powa - 23) % 4 == 0 || (powa - 24) % 5 == 0) {
                int a, x;
                vector<int> print;
                a = 2;
                x = (powa - 11) / 4;
                print.insert(print.end(), { powa,2 * a,x,2 * a,x, a,2 * x + 1 });
                printVect(print);
            }
            else if ((powa - 24) % 5 == 0) {
                int a, x;
                vector<int> print;
                a = 2;
                x = (powa - 9) / 5;
                print.insert(print.end(), { powa,2 * a,x, a,2 * x, a,2 * x + 1 });
                printVect(print);
            }

        }
        myfile <<"--------------------------------------------------------------------" << endl;
    }

    void Q6() {
        myfile << "Answer to Q6:ASCII represented histogram of BNT occurrences between a minimum and a maximum value\n";
        cout << "enter range for the BNT";
        int min, max;
        cin >> min>> max;
        if (max <= (*(soln.end() - 1))[0]) {
            for (int itr = 0; itr < soln.size(); itr++) {
                if (soln[itr][0] >= min) {
                    if (soln[itr][0] > max) {
                        break;
                    }
                    
                    myfile << setw(7) << soln[itr][0] << " | "<<"#";
                    while (itr < soln.size() - 1 && soln[itr][0] == soln[itr + 1][0]) {
                        myfile << "#";
                        itr++;
                    }
                    myfile << endl;
                }
            }
        }
        else
        {
            myfile << "out of calculation range";
        }
        myfile << endl << "--------------------------------------------------------------------" << endl;

    }

    void Q7() {
        myfile << "Answer to Q7:Highest BNT\n";
        HighestBNT();
        myfile << "--------------------------------------------------------------------" << endl;

    }
}

void HandleOutput() {
    cout << "Input the number for which you want the solution?\n"
        << "1: 5 distinct, lowest BNTs\n"
        << "2: 5 distinct, lowest BNTs that are prime\n"
        << "3: BNTs for which A, B, C are within the range of 3 to 20, and x, y, and z are within the scope of 3 to 15\n"
        << "4: 10 distinct, lowest BNTs that are composite\n"
        << "5: BNTs that are square numbers between 1000 and 100000\n"
        << "6: ASCII represented histogram of BNT occurrences between a minimum and a maximum value\n"
        << "7: Highest BNT\n"
        << "8: All the solutions\n"
        << "\nyou can input multiple numbers one after the other when prompted or input 0 to exit the program\n";

    bool switchcase = true;
    int output;
    while (switchcase) {
        cin >> output;
        switch (output)
        {
        case 1:
            output::Q1();
            break;
        case 2:
            output::Q2();
            break;
        case 3:
            output::Q3();
            break;
        case 4:
            output::Q4();
            break;
        case 5:
            output::Q5();
            break;
        case 6:
            output::Q6();
            break;
        case 7:
            output::Q7();
            break;
        case 8:
        {
            output::Q1();
            output::Q2();
            output::Q3();
            output::Q4();
            output::Q5();
            output::Q6();
            output::Q7();

            switchcase = false;
            break;
        }
        case 0:
            switchcase = false;
            break;
        default:
            cout << "Error : Wrong input please try again";
            continue;
        }
    }

}


void HandleSquare() {
    for (int i = 0; i <= 40; i++) {
        vector<Large<int>> temp;
        for (int j = 0; j <= 30; j++) {
            Large<int> temp1 = Power(i, j);
            temp.push_back(temp1);
        }
        _powr.push_back(temp);
    }
}


int main()
{
    clock_t start = clock();
    myfile.open("solution.txt");

    HandleSquare();
    thread worker1(createSet, 2, 27);
    thread worker2(createSet, 28, 40);


    worker1.join();
    worker2.join();
    sort(soln.begin(), soln.end(), sortcol);


    HandleOutput();


    clock_t end = clock();
    double elapsed_time = double(end - start) / CLOCKS_PER_SEC;
    myfile << "Elapsed time: " << elapsed_time << " seconds" << endl;
    myfile.close();


}

