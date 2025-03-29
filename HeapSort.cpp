#include <iostream>
using namespace std;
void Heapify(int arr[], int n, int i) {
int largest = i;
int left = 2 * i + 1;
int right = 2 * i + 2;
if (left < n && arr[left] > arr[largest]) {
largest = left;
}
if (right < n && arr[right] > arr[largest]) {
largest = right;
}
if (largest != i) {
swap(arr[i], arr[largest]);
Heapify(arr, n, largest);
}
}
void BuildHeap(int arr[], int n) {
for (int i = n / 2 - 1; i >= 0; i--) {
Heapify(arr, n, i);
}
}
void Heapsort(int arr[], int n) {
BuildHeap(arr, n);
for (int i = n - 1; i > 0; i--) {
swap(arr[0], arr[i]);
Heapify(arr, i, 0);
}
}
int main() {
int n;
cout << "Enter the number of elements you want to enter: ";
cin >> n;
int arr[n];
cout << "Enter the elements one by one:" << endl;
for (int i = 0; i < n; i++) {
cin >> arr[i];
}
Heapsort(arr, n);
cout << "SORTED ARRAY \n";
for (int i = 0; i < n; i++) {
cout << arr[i] <<" ";
}
cout << endl;
return 0;
}