#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int32_t n, k;
    cin >> n >> k;

    vector<int32_t> thing;
    thing.resize(n);
    for (int32_t i = 0; i < n; i++) cin >> thing[i];

    multiset<int32_t> window;
    for (int32_t i = 0; i < k; i++)
        window.insert(thing[i]);
    cout << *window.begin() << " ";

    for (int32_t i = k; i < n; i++) {
        window.erase(window.find(thing[i - k]));
        window.insert(thing[i]);
        cout << *window.begin() << " ";
    }
}