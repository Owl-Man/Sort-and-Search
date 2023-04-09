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

    cout << "Какой массив создать?\n"
        "0 - int\n"
        "1 - double" << endl;
    cout << " => ";
    cin >> is_array_double;
    cout << "Произвести сортировку или поиск?\n"
        "0 - сортировка\n"
        "1 - поиск\n";
    cin >> is_search_func;

    if (!is_search_func)
    {
        cout << "Какой тип сортировки использовать?\n"
            "0 - пузырьковый (bubble)\n"
            "1 - быстрый (quick)\n";
        cout << " => ";
        cin >> is_sort_quick;
    }

    cout << "Введите длину массива: ";
    cin >> array_size;
    cout << "Введите интервал случайных чисел [x, y]:" << endl;

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
        cout << "Какое число найти?";

        if (!is_array_double) 
        {
            auto start = system_clock::now();
            cin >> xInt;
            cout << myBinSearch(array_int, cnt, xInt);
            auto end = system_clock::now();

            auto elapsed = end - start;
            cout << "Скорость выполнения: "
                << duration_cast<microseconds>(elapsed).count()
                << " мкс"
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

        cout << "Количество итераций: "
            << cnt << endl;
        print_ar(is_array_double, array_int);
        auto elapsed = end - start;
        cout << "Скорость выполнения: "
            << duration_cast<microseconds>(elapsed).count()
            << " мкс"
            << endl;
    }
    else {
        if (!is_sort_quick) mySortBubble(array_double, cnt);
        else myQsort(array_double, 0, array_size - 1, cnt);
        cout << "Количество итераций: "
            << cnt << endl;
        print_ar(is_array_double, array_double);
    }
    return 0;
}