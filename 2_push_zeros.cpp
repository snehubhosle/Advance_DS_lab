#include <iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    int k = 0;

    int temp[end - start + 1];

    while (i <= mid && j <= end)
    {
        if (arr[i] == 0 && arr[j] != 0)
        {   
            temp[k++] = arr[j++];
        }
        else if (arr[i] != 0 && arr[j] == 0)
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= end)
        temp[k++] = arr[j++];

    for (int p = 0; p < k; p++)
        arr[start + p] = temp[p];
}

void mergeSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        merge(arr, start, mid, end);
    }
}

int main()
{
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    int arr[size];
    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Original array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, 0, size - 1);

    cout << "Array after pushing zeros to the end: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
