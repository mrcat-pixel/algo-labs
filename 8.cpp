#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    uint32_t n, k;
    cin >> n >> k;

    vector<uint32_t> prices;
    for (uint32_t i = 0; i < n; i++) {
        uint32_t t;
        cin >> t;
        prices.push_back(t);
    }

    sort(prices.rbegin(), prices.rend());

    uint32_t total = 0;
    for (uint32_t i = 0; i < n; i++)
        if ((i+1) % k != 0) total += prices[i];

    cout << total;
}