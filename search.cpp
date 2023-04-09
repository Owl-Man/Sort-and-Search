#include "head.h"
#include <vector>

using namespace std;

size_t myBinSearch(vector<int>& mas, int& r, int x) {
    size_t L = 0, R = mas.size(), q;
    do {
        q = (R + L) / 2;
        if (mas[q] > x)
            R = q;
        else
            L = q;
        r++;
    } while (L < R - 1);
    return L;
}

size_t myBinSearch(vector<double>& mas, int& r, double x) {
    size_t L = 0, R = mas.size(), q;
    do {
        q = (R + L) / 2;
        if (mas[q] > x)
            R = q;
        else
            L = q;
        r++;
    } while (L < R - 1);
    return L;
}