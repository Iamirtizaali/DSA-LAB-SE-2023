#include <iostream>
#include "Array.h"
using namespace std;

//
//void printArray(int* arr, int size) {
//	for (int i = 0; i < size; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}
//
//void insertStart(int*& arr, int& size, int num) {
//	int newSize = size + 1;
//	int* newArr = new int[newSize];
//	newArr[0] = num;
//	int j = 1;
//	for (int i = 0; i < size; i++)
//	{
//		newArr[j] = arr[i];
//		j++;
//	}
//	delete[] arr;
//	arr = newArr;
//	size = newSize;
//}
//
//void insertEnd(int*& arr, int& size, int num) {
//	int newSize = size + 1;
//	int* newArr = new int[newSize];
//	for (int i = 0; i < size; i++)
//	{
//		newArr[i] = arr[i];
//	}
//	newArr[size] = num;
//	delete[] arr;
//	arr = newArr;
//	size = newSize;
//}
//
//void removeElement(int*& arr, int& size, int num) {
//	int newSize = size - 1;
//	int* newArr = new int[newSize];
//	int j = 0;
//	for (int i = 0; i < size; i++)
//	{
//		if (arr[i]==num)
//		{
//			continue;
//		}
//		else
//		{
//			newArr[j] = arr[i];
//			j++;
//		}
//	}
//	delete[]arr;
//	arr = newArr;
//	size = newSize;
//}
//
//void updateValue(int*& arr, const int size, int newValue, int idx) {
//	if (idx<size && idx>=0)
//	{
//		arr[idx] = newValue;
//	}
//	else
//	{
//		cout << "Wrong Index"<<endl;
//	}
//}
//
//int searchValueLinear(int*& arr, int size, int value) {
//	for (int i = 0; i < size; i++)
//	{
//		if (arr[i] == value) {
//			cout << "value found" << endl;
//			return i;
//		}
//	}
//	cout << "value not found" << endl;
//	return -1;
//}
//
//int searchValueBinary(int*& arr, int size, int value) {
//	int s = 0, e = size - 1;
//	int mid = s + ((e - s) / 2);
//	while (s<=e)
//	{
//		if (arr[mid] == value) {
//			cout << "value found" << endl;
//			return mid;
//		}
//		else if (arr[mid]>value)
//		{
//			s = mid + 1;
//		}
//		else
//		{
//			e = mid - 1;
//		}
//		mid = s + ((e - s) / 2);
//	}
//	cout << "value not found" << endl;
//	return -1;
//}
//
//bool back(int start, int idx) {
//	if (idx<start)
//	{
//		return false;
//	}
//	return true;
//}
//bool front(int size, int idx) {
//	if (idx>size)
//	{
//		return false;
//	}
//	return true;
//}
//
//int index_at(int*& arr, int size, int value) {
//	for (int i = 0; i < size; i++)
//	{
//		if (arr[i] == value) {
//			cout << value << " is present at index " << i << endl;
//			return i;
//		}
//	}
//	cout << "value not found" << endl;
//	return -1;
//}


int main() {
	int size = 5;
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = i * 2;
	}
	/*printArray(arr, size);
	insertStart(arr, size, 20);
	printArray(arr, size);
	insertEnd(arr, size, -12);
	printArray(arr, size);
	removeElement(arr, size, 4);
	printArray(arr, size);*/
	ArrayFunctions obj(arr, size);
	do
	{
		cout << "Enter 1 to print Array"<<endl;
		cout << "Enter 2 to insert value at Start"<<endl;
		cout << "Enter 3 to insert value at end"<<endl;
		cout << "Enter 4 to remove specific value"<<endl;
		cout << "Enter 5 to update value in Array"<<endl;
		cout << "Enter 6 to search value in array"<<endl;
		cout << "Enter 7 to check value is not less than first location"<<endl;
		cout << "Enter 8 to check value is not greater than size of array"<<endl;
		cout << "Enter 9 to find index of specific value in array"<<endl;
		cout << "Enter 10 to break" << endl;
		cout << "Enter your choice: ";
		int n;
		int val;
		int idx;
		cin >> n;
		switch (n)
		{
		case 1:
		{
			obj.printArray();
		}
		break;
		case 2: {
			cout << "Enter the value you want to add: ";
			cin >> val;
			obj.insertStart(val);
		}
			  break;
		case 3:
		{
			cout << "Enter the value you want to add at end: ";
			cin >> val;
			obj.insertEnd(val);
		}
		break;
		case 4:
		{
			cout << "Enter the value you want to remove: ";
			cin >> val;
			obj.removeElement(val);
		}
		break;
		case 5: {
			cout << "Enter the index at which you want to update: ";
			cin >> idx;
			cout << "Enter the new value: ";
			cin >> val;
			obj.updateValue(val, idx);
		}
			  break;
		case 6:
		{
			cout << "Enter the value you want to search: ";
			cin >> val;
			obj.searchValueLinear(val);
		}
		break;
		case 7:
		{
			cout << "Enter index to check if it is less than first location or not: ";
			cin >> idx;
			cout << (obj.back(0, idx) ? "It is not less than start index" : "It is less than start index") << endl;
		}
		break;
		case 8:
		{
			cout << "Enter index to check if it is greater than last location or not: ";
			cin >> idx;
			cout << (obj.front(idx) ? "It is not greater than start index" : "It is greater than start index") << endl;

		}
		break;
		case 9:
		{
			cout << "Enter value to check its index in Array";
			cin >> idx;
			obj.index_at(idx);
		}
		break;
		case 10:
			exit(0);
			break;
		default:
			cout << "Wrong input" << endl;
			break;
		}
	} while (true);
	return 0;
}
