#include<iostream>
using namespace std;
void Binary_search(int arr[], int LB, int UB, int key) {
while (LB <= UB) {
int mid = LB + (UB - LB) / 2;
if (arr[mid] == key) {
cout << "Element found at index: " << mid << endl;
return;
} else if (arr[mid] < key) {
LB = mid + 1;
} else {
UB = mid - 1;
}
}
cout << "Element not found" << endl;
}
int main() {
int n;
cout << "Enter the number of elements you want to enter: ";
cin >> n;
int arr[n];
cout << "Enter the elements one by one in sorted order:" << endl;
for (int i = 0; i < n; i++) {
cin >> arr[i];
}
int el;
cout << "Enter the element to search: ";
cin >> el;
Binary_search(arr, 0, n - 1, el);
return 0;
}