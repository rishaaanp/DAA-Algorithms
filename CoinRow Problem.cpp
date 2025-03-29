#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b) {
return (a > b) ? a : b;
}
// Function to print the selected coins that make up the maximum sum
void printCoins(const vector<int>& coins, const vector<int>& sum) {
cout << "Coins chosen: ";
int i = sum.size() - 1;
while (i > 0) {
// If the current value in sum includes the current coin, it’s part of the solution
if (i >= 2 && sum[i] == coins[i] + sum[i - 2]) {
cout << coins[i] << " ";
i -= 2; // Skip to the next non-adjacent coin
} else {
i--; // Move back by 1 if this coin was not included
}
}
cout << endl;
}
void CRP(const vector<int>& coins) {
int n = coins.size();
vector<int> sum(n, 0); 
sum[1] = coins[1]; 
// Fill the sum vector for maximum sums without picking consecutive coins
for (int i = 2; i < n; i++) {
sum[i] = max(coins[i] + sum[i - 2], sum[i - 1]);
}
cout << "Largest value = " << sum[n - 1] << endl;
printCoins(coins, sum); 
}
int main() {
int n;
cout << "Enter number of coins: ";
cin >> n;
vector<int> coins(n + 1); 
cout << "Enter values of coins:" << endl;
for (int i = 1; i <= n; i++) {
cin >> coins[i];
}
CRP(coins); 
return 0;}