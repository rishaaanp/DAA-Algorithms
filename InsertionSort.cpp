#include <iostream>
using namespace std;
void insertion_Sort(int arr[], int n) {
for (int i = 1; i < n; i++) {
int temp = arr[i];
int j = i - 1;
while (j >= 0 && arr[j] > temp) {
arr[j + 1] = arr[j];
j--;
}
arr[j + 1] = temp;
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
    insertion_Sort(arr, n);
    cout << "SORTED ARRAY \n";
    for (int i = 0; i < n; i++) {
    cout << arr[i] <<" ";
    }
    cout << endl;
    return 0;
    }