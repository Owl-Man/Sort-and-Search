#include <iostream>
#include <algorithm>
using namespace std;

int partition(int arr[], int low, int high)
{
    //take the last element as pivot
    int pivot = arr[high];
    int i = (low - 1);

    //place pivot at its correct position and place all elements
    //smaller then the pivot to the left and all greater to the right
    for (int j = low; j <= high - 1; ++j)
    {
        if (arr[j] <= pivot)
        {
            i++; //increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); //place the pivot in the correct position

    return (i + 1);
}

void static quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        //pi is now at the correct place
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}