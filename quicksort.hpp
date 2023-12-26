#pragma once
#include<vector>

template<class T=int>
class Quick_Sort {
public:
	std::vector<int> quickSort(std::vector<T>& arr) {
		return quickSort(arr, 0, arr.size()-1);
	}

private:
	std::vector<int> quickSort(std::vector<T>& arr, int low, int high) {
		int pivot;
		if (low >= high)return {0};
		pivot = partition(arr, low, high);//一次划分，返回枢纽的位置
		quickSort(arr, low, pivot - 1);	//排序枢纽左半边
		quickSort(arr, pivot + 1, high);
		return arr;
	}

	int partition(std::vector<T>&arr,int low,int high) {

		T temp = arr[low];
		while (low != high) {
			while (low < high && arr[high] >= temp)high--;
			if (low < high) {
				arr[low] = arr[high];
				low++;
			}
			while (low < high && arr[low] <= temp)low++;
			if (low < high) {
				arr[high] = arr[low];
				high--;
			}
		}
		arr[low] = temp;
		return low;
	}

};
