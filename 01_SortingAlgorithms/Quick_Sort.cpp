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
void Quick_Sort(T arr[], int left_Element, int right_Element);

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

	Quick_Sort(arr1, 0, SIZE_1 - 1);
	Quick_Sort(arr2, 0, SIZE_2 - 1);

	cout << "Sorted array 1: " << endl;
	Array_Print(arr1, SIZE_1);
	cout << endl;

	cout << "Sorted array 2: " << endl;
	Array_Print(arr2, SIZE_2);

	return 0;

} 

template <typename T>
void Array_Init(T arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = (rand() % 100)/10.0f;
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
void Quick_Sort(T arr[], int left_Element, int right_Element) {

	T middle_Element = arr[(right_Element + left_Element) / 2];

	int i = left_Element;
	int j = right_Element;

	cout << "Partitioning around pivot " << middle_Element << ": ";
	Array_Print(arr + left_Element, right_Element - left_Element + 1);
	cout << endl;

	do {
		while (arr[i] < middle_Element) {
			i++;
		}
		while (arr[j] > middle_Element) {
			j--;
		}
		if (i <= j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}

	} while (i <= j);

	if (j > left_Element) {
		Quick_Sort(arr, left_Element, j);
	}
	if (i < right_Element) {
		Quick_Sort(arr, i, right_Element);
	}

	

}