#include <iostream>
#include <string>
#include "heap_sort.cpp"
#include "insertion_sort.cpp"
#include "quick_sort.cpp"
#include "selection_sort.cpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int arr[10];
    int chosenSortVariant;

    cout << "Выберите метод сортировки: 1 - пирамидальная сортировка, 2 - сортировка вставками, 3 - быстрая сортировка, 4 - сортировка выбором";
    cin >> chosenSortVariant;

    // Заполняем массив с клавиатуры
    for (int i = 0; i < 10; i++) {
        cout << "[" << i + 1 << "]" << ": ";
        cin >> arr[i];
    }

    // И выводим заполненный массив.
    int n = sizeof(arr) / sizeof(arr[0]);

    if (chosenSortVariant == 1) heap_sorting(arr, n);
    else if (chosenSortVariant == 2) insertion_sort(arr, n);
    else if (chosenSortVariant == 3) quick_sort(arr, 0, n - 1);
    else if (chosenSortVariant == 4) selection_sort(arr, n);
    else cout << "Неверный ввод";

    cout << "\nВаш массив: ";

    for (int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }

    cout << "\n";

    cout << endl;

    return 0;
}