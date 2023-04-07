#include <iostream>
#include <algorithm>
using namespace std;

//������������� ���������� � �������� ����������, ���������� � ������, � ������� � � ������ ������ �� O(n\log n) �������� ��� ���������� n ���������. 
//���������� ����������� ��������� ������ �� ������� �� ������� �������



void heapify(int arr[], int n, int i)
{
    //to heapify a tree rooted at i
    //where n is the size of the heap

    int largest = i; //root (0-based)
    int l = 2 * i + 1; //left child
    int r = 2 * i + 2; //right child

    //if left child is larger than root
    if (l < n && arr[l] > arr[largest]) { largest = l; }

    //if right child is larger than largest so far
    if (r < n && arr[r] > arr[largest]) { largest = r; }

    //if largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        //recursively heapify the affected subtree
        heapify(arr, n, largest);
    }

}

void static heap_sorting(int arr[], int n)
{
    // build heap (re-arrange array)
    for (int i = n / 2 - 1; i >= 0; --i)
    {
        heapify(arr, n, i);
    }

    // extract an element from heap one by one
    for (int i = n - 1; i >= 0; --i)
    {
        // move current root to end
        swap(arr[0], arr[i]);

        // call heapify on the reduced heap
        heapify(arr, i, 0);
    }

}