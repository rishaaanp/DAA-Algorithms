#include<iostream>
using namespace std;
void Bubble_Sort(int arr[], int n) {
for (int i = 0; i < n - 1; i++) {
for (int j = 0; j < n - i - 1; j++) {
if (arr[j] > arr[j + 1]) {
swap(arr[j], arr[j + 1]);
}
}
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
Bubble_Sort(arr, n);
cout << "SORTED ARRAY \n";
for (int i = 0; i < n; i++) {
cout << arr[i] << " ";
}
cout << endl;
return 0;
}