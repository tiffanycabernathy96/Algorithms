//Tiffany Abernathy - Merge Sort Implementation
#include "MergeSort.h"

void merge(int arr[], int l, int m, int r) {
    //Determine length of left and right array
    int sizeLArr = m - l + 1;
    int sizeRArr = r - m;

    //Create temp arrays for left and right
    int *lArr = new int[sizeLArr];
    int *rArr = new int[sizeRArr];

    //Copy data into the temp arrays
    for (int i = 0; i < sizeLArr; i++) {
        lArr[i] = arr[l + i];
    }
    for (int i = 0; i < sizeRArr; i++) {
        rArr[i] = arr[m + i + 1];
    }

    //ints to keep track of the current indexes in each of the arrays
    int lArrIndex = 0;
    int rArrIndex = 0;
    int mArrIndex = l;

    //Merge the two arrays back into original array sorted
    while (lArrIndex < sizeLArr && rArrIndex < sizeRArr) {
        if (lArr[lArrIndex] <= rArr[rArrIndex]) {
            arr[mArrIndex] = lArr[lArrIndex];
            lArrIndex++;
        }
        else {
            arr[mArrIndex] = rArr[rArrIndex];
            rArrIndex++;
        }
        mArrIndex++;
    }

    //Copy the remaining items from left into original array
    while (lArrIndex < sizeLArr) {
        arr[mArrIndex] = lArr[lArrIndex];
        mArrIndex++;
        lArrIndex++;
    }

    //Copy the remaining items from right into original array
    while (rArrIndex < sizeRArr) {
        arr[mArrIndex] = rArr[rArrIndex];
        mArrIndex++;
        rArrIndex++;
    }
}
void mergeSort(int arr[], int l, int r) {
    //Determine if merged as far as possible
    if (l >= r)
        return;
    
    //Determine midpoint
    int m = l + (r - l)/2;
    //Call self on left half
    mergeSort(arr, l, m);
    //Call self on right half
    mergeSort(arr, m + 1, r);
    //Merge
    merge(arr, l, m, r);
}

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int test[] = { 30, 1, 9, 0, 100, 3, 4 };
    int sizeA = sizeof(test) / sizeof(test[0]);

    cout << "Original Array: ";
    print(test, sizeA);

    cout << "Sorted Array: ";
    mergeSort(test, 0, sizeA - 1);
    print(test, sizeA);

    return 0;
}
