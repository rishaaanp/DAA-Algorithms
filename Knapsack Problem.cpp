#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int knapsack(const vector<int>& values, const vector<int>& weights, int capacity) {
int n = values.size();
vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

for (int i = 1; i <= n; i++) {
for (int w = 1; w <= capacity; w++) {
if (weights[i - 1] > w) {
dp[i][w] = dp[i - 1][w];
} else {
dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
}
}
}
vector<int> selectedItems;
int i = n;
int j = capacity;
while (i > 0 && j > 0) {
if (dp[i][j] != dp[i - 1][j]) {
selectedItems.push_back(i - 1); 
j -= weights[i - 1]; 
}
i--;
}
cout << "Selected weights: ";
for (int k = selectedItems.size() - 1; k >= 0; k--) {
cout << selectedItems[k] + 1 << " "; 
}
cout << endl;
return dp[n][capacity]; 
}
int main() {
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;
    vector<int> values(n), weights(n);
    cout << "Enter the values of items: ";
    for (int i = 0; i < n; i++) {
    cin >> values[i];
    }
    cout << "Enter the weights of items: ";
    for (int i = 0; i < n; i++) {
    cin >> weights[i];
    }
    cout << "Enter the maximum capacity of the knapsack: ";
    cin >> capacity;
    int maxValue = knapsack(values, weights, capacity);
    cout << "Maximum value that can be obtained: " << maxValue << endl;
    return 0;
    }