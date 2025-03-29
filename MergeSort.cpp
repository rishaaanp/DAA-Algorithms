#include <iostream>
using namespace std;
void Merge(int arr[], int left, int mid, int right) {
int n1 = mid - left + 1;
int n2 = right - mid;
int L[n1], R[n2];
for (int i = 0; i < n1; i++) {
L[i] = arr[left + i];
}
for (int j = 0; j < n2; j++) {
R[j] = arr[mid + 1 + j];
}
int i = 0, j = 0, k = left;
while (i < n1 && j < n2) {
if (L[i] <= R[j]) {
arr[k] = L[i];
i++;
} else {
arr[k] = R[j];
j++; }
k++;
}
while (i < n1) {
arr[k] = L[i];
i++;
k++;
}
while (j < n2) {
arr[k] = R[j];
j++;
k++;
}}
void Merge_sort(int arr[], int left, int right) {
    if (left < right) {
    int mid = left + (right - left) / 2;
    Merge_sort(arr, left, mid);
    Merge_sort(arr, mid + 1, right);
    Merge(arr, left, mid, right);
    }}
    int main() {
    int n;
    cout << "Enter the number of elements you want to enter: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements one by one:" << endl;
    for (int i = 0; i < n; i++) {
    cin >> arr[i];}
    Merge_sort(arr, 0, n - 1);
    cout << "SORTED ARRAY \n";
    for (int i = 0; i < n; i++) {
    cout << arr[i] <<" ";
    }
    cout << endl;
    return 0;
    }