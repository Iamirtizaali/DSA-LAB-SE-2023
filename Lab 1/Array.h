#pragma once
#include <iostream>
using namespace std;
class ArrayFunctions
{
private:
	int size;
	int* arr;
public:
	ArrayFunctions() {
		size = 0;
		arr = nullptr;
	}
	ArrayFunctions(int*& arr, int size) {
		this->arr = arr;
		this->size = size;
	}
	void printArray() {
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	void insertStart( int num) {
		int newSize = size + 1;
		int* newArr = new int[newSize];
		newArr[0] = num;
		int j = 1;
		for (int i = 0; i < size; i++)
		{
			newArr[j] = arr[i];
			j++;
		}
		delete[] arr;
		arr = newArr;
		size = newSize;
	}

	void insertEnd( int num) {
		int newSize = size + 1;
		int* newArr = new int[newSize];
		for (int i = 0; i < size; i++)
		{
			newArr[i] = arr[i];
		}
		newArr[newSize-1] = num;
		delete[] arr;
		arr = newArr;
		size = newSize;
	}

	void removeElement( int num) {
		int newSize = size - 1;
		int* newArr = new int[newSize];
		int j = 0;
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == num)
			{
				continue;
			}
			else
			{
				newArr[j] = arr[i];
				j++;
			}
		}
		delete[]arr;
		arr = newArr;
		size = newSize;
	}

	void updateValue( int newValue, int idx) {
		if (back(0,idx) && front(idx))
		{
			arr[idx] = newValue;
		}
		else
		{
			cout << "Wrong Index" << endl;
		}
	}

	int searchValueLinear( int value) {
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == value) {
				cout << "value found" << endl;
				return i;
			}
		}
		cout << "value not found" << endl;
		return -1;
	}

	int searchValueBinary( int value) {
		int s = 0, e = size - 1;
		int mid = s + ((e - s) / 2);
		while (s <= e)
		{
			if (arr[mid] == value) {
				cout << "value found" << endl;
				return mid;
			}
			else if (arr[mid] > value)
			{
				s = mid + 1;
			}
			else
			{
				e = mid - 1;
			}
			mid = s + ((e - s) / 2);
		}
		cout << "value not found" << endl;
		return -1;
	}

	bool back(int start, int idx) {
		if (idx < start)
		{
			return false;
		}
		return true;
	}
	bool front( int idx) {
		if (idx > size)
		{
			return false;
		}
		return true;
	}

	int index_at( int value) {
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == value) {
				cout << value << " is present at index " << i << endl;
				return i;
			}
		}
		cout << "value not found" << endl;
		return -1;
	}

};

