#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
struct Coin {
int denomination;
int count;
};
vector<Coin> changeMaking(const vector<int>& D, int n) {
vector<int> F(n + 1, INT_MAX);
F[0] = 0;
vector<int> lastCoin(n + 1, -1);
for (int i = 1; i <= n; i++) {
    int temp = INT_MAX;
int tempCoin = -1;
for (int j = 0; j < D.size() && i >= D[j]; j++) {
if (F[i - D[j]] != INT_MAX && F[i - D[j]] + 1 < temp) {
temp = F[i - D[j]] + 1;
tempCoin = D[j];
}
}
if (temp != INT_MAX) {
F[i] = temp;
lastCoin[i] = tempCoin;
}
}
vector<Coin> coinsUsed;
int remainingAmount = n;
while (remainingAmount > 0 && lastCoin[remainingAmount] != -1) {
Coin c;
c.denomination = lastCoin[remainingAmount];
c.count = 1;
coinsUsed.push_back(c);
remainingAmount -= lastCoin[remainingAmount];
while (remainingAmount > 0 && lastCoin[remainingAmount] == c.denomination) {
c.count++;
remainingAmount -= c.denomination;
}
}
return coinsUsed;
}
int main() {
int n;
cout << "Enter the amount: ";
cin >> n;
vector<int> D;
int m;
cout << "Enter the number of denominations: ";
cin >> m;
cout << "Enter the denominations (space-separated, in increasing order): ";
for (int i = 0; i < m; i++) {
int denomination;
cin >> denomination;
D.push_back(denomination);
}
vector<Coin> result = changeMaking(D, n);
if (!result.empty()) {
cout << "Minimum number of coins needed: " << result.size() << endl;
cout << "Coins used:" << endl;
for (const auto& coin : result) {
cout << "Denomination: " << coin.denomination << ", Count: " << coin.count << endl;
}
} else {
cout << "It is not possible to make the given amount with the available denominations.";
}
return 0;
}