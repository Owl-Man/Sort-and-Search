#ifndef SORTTEXT_H
#define SORTTEXT_H

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int Rnd(int, int);
double Rnd(double, double);

void mySortBubble(std::vector<int>&, int&);
void mySortBubble(std::vector<double>&, int&);
void myQsort(std::vector<int>&, size_t, size_t, int&);
void myQsort(std::vector<double>&, size_t, size_t, int&);

size_t myBinSearch(vector<int>& mas, int& r, int x);
size_t myBinSearch(vector<double>& mas, int& r, double x);

template <typename T, typename Arg>
void ini_ar(size_t s, T a, T b, Arg& arg) {
    if (!arg.empty()) arg.clear();
    arg.reserve(s);
    for (size_t i = 0; i < s; i++) {
        arg.push_back(Rnd(a, b));
    }
}

template <typename Arg>
void print_ar(bool flag, Arg& arg) {
    if (flag) {
        cout.precision(2);
        for (auto r : arg)
            cout << r << setw(4);
        cout << endl;
    }
    else {
        for (auto r : arg)
            cout << r << setw(3);
        cout << endl;
    }
}

#endif