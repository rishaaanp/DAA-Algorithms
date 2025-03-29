#include <iostream>
using namespace std;
void Selection_Sort(int arr[], int n) {
for (int i = 0; i < n - 1; i++) {
int MinIndex = i;
for (int j = i + 1; j < n; j++) {
if (arr[j] < arr[MinIndex]) {
MinIndex = j;
}
}
swap(arr[i], arr[MinIndex]);
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
    Selection_Sort(arr, n);
    cout << "SORTED ARRAY \n";
    for (int i = 0; i < n; i++) {
    cout << arr[i] <<" ";
    }
    cout << endl;
    return 0;
    }