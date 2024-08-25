#include<bits/stdc++.h>
using namespace std;

/*

•	Algorithm Module
11)	Last Index / First Index
*/

//search 
bool isSorted(vector<int> arr){
	for(int i=1;i<arr.size();i++){
		if(arr[i-1] > arr[i])
			return false;
	}
	return true;
}

int linearSearch(vector<int> arr,int target){
	for(int i=0;i<arr.size();i++)
		if(arr[i] == target)
			return i;
	return -1;
}

int binarySearch(vector<int> arr,int target){
	int i = 0,j=arr.size()-1,mid;
	while(i <= j){
		mid = i + (j - i)/2;
		if(arr[mid] == target)
			return mid;
		else if(arr[mid] > target)
			j = mid - 1;
		else
			i = mid + 1; 
	}
	return -1;
}

int search(vector<int> arr,int target){
	return isSorted(arr) ? binarySearch(arr,target) : linearSearch(arr,target);
}

int findMaximum(vector<int> arr){
	int maxEl = INT_MIN;
	for(auto x : arr)
		maxEl = max(maxEl,x);
	return maxEl;
}

int findMinimum(vector<int> arr){
	int minEl = INT_MAX;
	for(auto x : arr)
		minEl = min(minEl,x);
	return minEl;
}

int sum(vector<int> arr){
	int sum = 0;
	for(auto x : arr)
		sum += x;
	return sum;
}

int findFrequencyCount(vector<int> v,int x){
	int count = 0;
	for(auto i : v)
		if(i == x)
			count++;
	return count;
}

//SORTING
void bubbleSort(vector<int> &arr){
	int n = arr.size();
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i] > arr[j])
				swap(arr[i],arr[j]);
		}
	}
}

void insertionSort(vector<int> &arr){
	int n = arr.size();
	for(int i=0;i<n;i++){
		int key = arr[i];
		int j = i-1;
		while(j >= 0 && arr[j] > key){
			arr[j+1] = arr[j];
			j--;
		}
		arr[++j] = key;
	}
}

void selectionSort(vector<int> &arr){
	int n = arr.size();
	for(int i=0;i<n;i++){
		int minIndex = i;
		for(int j=i+1;j<n;j++){
			if(arr[minIndex] > arr[j])
				minIndex = j;
		}

		swap(arr[i],arr[minIndex]);
	}
}


//QUICK SORT
int partition(vector<int> &arr,int low,int high){
	int pivot = arr[low];
	int i = low;
	for(int j=low+1;j<=high;j++){
		if(arr[j] < pivot){
			swap(arr[++i],arr[j]);
		}
	}

	swap(arr[i],arr[low]);

	return i;
}

void quickHelper(vector<int> &arr,int low,int high){
	if(low >= high)
		return;

	int p = partition(arr,low,high);
	quickHelper(arr,low,p-1);
	quickHelper(arr,p+1,high);
}

void quickSort(vector<int> &arr){
	quickHelper(arr,0,arr.size()-1);
} 

//MERGE SORT
void merge(vector<int> &arr,int low,int mid,int high){
	int i = low;
	int j = mid + 1;

	vector<int> temp;
	while(i<=mid && j<=high){
		if(arr[i] <= arr[j])
			temp.push_back(arr[i++]);
		else
			temp.push_back(arr[j++]);
	}

	while(i<=mid)
		temp.push_back(arr[i++]);
	while(j<=high)
		temp.push_back(arr[j++]);

	for(int i=low;i<=high;i++)
		arr[i] = temp[i-low];
}

void mergeSortHelper(vector<int> &arr,int low,int high){
	if(low >= high)
		return;

	int mid = low + (high - low)/2;
	mergeSortHelper(arr,low,mid);
	mergeSortHelper(arr,mid+1,high);
	merge(arr,low,mid,high);
}

void mergeSort(vector<int> &arr){
	mergeSortHelper(arr,0,arr.size()-1);
}