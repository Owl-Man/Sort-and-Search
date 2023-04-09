#include <iostream>
#include "head.h"
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

int main() {
    vector<int> array_int;
    vector<double> array_double;
    size_t array_size;
    bool is_array_double, is_sort_quick, is_search_func;
    int xInt;
    double xDouble;

    cout << "����� ������ �������?\n"
        "0 - int\n"
        "1 - double" << endl;
    cout << " => ";
    cin >> is_array_double;
    cout << "���������� ���������� ��� �����?\n"
        "0 - ����������\n"
        "1 - �����\n";
    cin >> is_search_func;

    if (!is_search_func)
    {
        cout << "����� ��� ���������� ������������?\n"
            "0 - ����������� (bubble)\n"
            "1 - ������� (quick)\n";
        cout << " => ";
        cin >> is_sort_quick;
    }

    cout << "������� ����� �������: ";
    cin >> array_size;
    cout << "������� �������� ��������� ����� [x, y]:" << endl;

    if (!is_array_double) {
        int x, y;
        cout << "x => "; cin >> x;
        cout << "y => "; cin >> y;
        ini_ar(array_size, x, y, array_int);
        print_ar(is_array_double, array_int);
    }
    else {
        double x, y;
        cout << "x => "; cin >> x;
        cout << "y => "; cin >> y;
        ini_ar(array_size, x, y, array_double);
        print_ar(is_array_double, array_double);
    }

    int cnt{};

    if (is_search_func)
    {
        cout << "����� ����� �����?";

        if (!is_array_double) 
        {
            auto start = system_clock::now();
            cin >> xInt;
            cout << myBinSearch(array_int, cnt, xInt);
            auto end = system_clock::now();

            auto elapsed = end - start;
            cout << "�������� ����������: "
                << duration_cast<microseconds>(elapsed).count()
                << " ���"
                << endl;
        }
        else
        {
            cin >> xDouble;
            cout << myBinSearch(array_double, cnt, xDouble);
        }

        return 0;
    }

    if (!is_array_double) {
        auto start = system_clock::now();
        if (!is_sort_quick) mySortBubble(array_int, cnt);
        else myQsort(array_int, 0, array_size - 1, cnt);
        auto end = system_clock::now();

        cout << "���������� ��������: "
            << cnt << endl;
        print_ar(is_array_double, array_int);
        auto elapsed = end - start;
        cout << "�������� ����������: "
            << duration_cast<microseconds>(elapsed).count()
            << " ���"
            << endl;
    }
    else {
        if (!is_sort_quick) mySortBubble(array_double, cnt);
        else myQsort(array_double, 0, array_size - 1, cnt);
        cout << "���������� ��������: "
            << cnt << endl;
        print_ar(is_array_double, array_double);
    }
    return 0;
}