#include <iostream>
#include <ctime>

using std::cout;
using std::endl;
using std::swap;

template <typename T>
void Array_Init(T arr[], int size);

template <typename T>
void Array_Print(T arr[], int size);

template <typename T>
void Array_Init(T arr[], int size);

template <typename T>
void Merge(T arr[], int left, int mid, int right);

template <typename T>
void mergeSort(T arr[], int left, int right);

int main() {
	srand(time(NULL));

	const int SIZE_1 = 5;
	const int SIZE_2 = 21;

	int arr1[SIZE_1];
	float arr2[SIZE_2];

	Array_Init(arr1, SIZE_1);
	Array_Init(arr2, SIZE_2);

	cout << "Unsorted array 1: " << endl;
	Array_Print(arr1, SIZE_1);
    cout << endl;

	cout << "Unsorted array 2: " << endl;
	Array_Print(arr2, SIZE_2);

	mergeSort(arr1, 0, SIZE_1 - 1);
    mergeSort(arr2, 0, SIZE_2 - 1);

	cout << "Sorted array 1: " << endl;
	Array_Print(arr1, SIZE_1);

	cout << "Sorted array 2: " << endl;
	Array_Print(arr2, SIZE_2);

	return 0;

}

template <typename T>
void Array_Init(T arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = (rand() % 100) / 10.0f;
	}
}

template <typename T>
void Array_Print(T arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

template <typename T>
void Merge(T arr[], int left, int mid, int right) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    T* leftArr = new T[n1];
    T* rightArr = new T[n2];


    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    cout << "Left array: ";
    Array_Print(leftArr, n1);
    cout << "Right array: ";
    Array_Print(rightArr, n2);

    int i = 0, j = 0, k = left;
    while (i < n1 and j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    cout << "Merged: ";
    Array_Print(arr + left, right - left + 1);
    cout << endl;
   
    delete [] leftArr;
    delete [] rightArr;
}



template <typename T>
void mergeSort(T arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        Merge(arr, left, mid, right);
    }
}