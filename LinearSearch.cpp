#include<iostream>
using namespace std;
int Linear_Search(int arr[], int target, int index, int size) {
if (index >= size) {
return -1; // Target not found
}
if (arr[index] == target) {
return index; // Target found
}
return Linear_Search(arr, target, index + 1, size);
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
int el;
cout << "Enter the element to search: ";
cin >> el;
int result = Linear_Search(arr, el, 0, n);
if (result != -1) {
cout << "Element found at index: " << result << endl;
} else {
cout << "Element not found..." << endl;
}
return 0;
}