//Tiffany Abernathy - Implementation of Quick Sort
#include "QuickSort.h"

int partition(int arr[], int start, int end) {
    //Set partition to the array at start
    int pivot = arr[start];

    //Determine the number of elements in the array less than the partition
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    //Place the pivot in its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    //Sorting left and right parts of the pivot element
    int i = start; 
    int j = end;

    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < pivotIndex && j > pivotIndex) {
            cout << "Swapping " << arr[i] << " and " << arr[j] << endl;
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}
void quickSort(int arr[], int start, int end) {
    cout << "Start: " << start << " End: " << end << endl;
    //Check if finished
    if (start >= end)
        return;
    //Determine Partition Index
    int partI = partition(arr, start, end);
    cout << "Partition: " << partI << endl;
    //Call quick sort on left side
    quickSort(arr, start, partI - 1);
    //Call quick sort on right side
    quickSort(arr, partI + 1, end);
}
void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int test[] = { 8, 7, 6, 1, 0, 9, 2 };
    int sizeA = sizeof(test) / sizeof(test[0]);
    
    quickSort(test, 0, sizeA-1);

    print(test, sizeA);

    return 0;
}
