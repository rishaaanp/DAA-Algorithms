#include <iostream>
using namespace std;
int Partition(int arr[], int low, int high) {
int PivotVal = arr[high];
int i = low - 1;
for (int j = low; j <= high - 1; j++) {
    if (arr[j] <= PivotVal) {
    i++;
    swap(arr[i], arr[j]);
    }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);}
    void Quick_sort(int arr[], int low, int high) {
    if (low < high) {
    int PivotIndex = Partition(arr, low, high);
    Quick_sort(arr, low, PivotIndex - 1);
    Quick_sort(arr, PivotIndex + 1, high);
    }}
    int main() {
    int n;
    cout << "Enter the number of elements you want to enter: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements one by one:" << endl;
    for (int i = 0; i < n; i++) {
    cin >> arr[i];}
    Quick_sort(arr, 0, n - 1);
    cout << "SORTED ARRAY \n";
    for (int i = 0; i < n; i++) {
    cout << arr[i] <<" "; }
    cout << endl;
    return 0;
    }