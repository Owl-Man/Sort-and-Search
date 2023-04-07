#include <iostream>
#include <algorithm>
using namespace std;

void static selection_sort(int arr[], int n)
{
    int i, j, min_idx;

    // move boundary of unsorted sub-array
    for (i = 0; i < n - 1; ++i)
    {
        //find min element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        //swap found min element with the boundary element
        swap(arr[min_idx], arr[i]);
    }
}