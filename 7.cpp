#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct w_entry {
    char letter;
    uint32_t value;
};

bool compare_w_entry(const w_entry& a, const w_entry& b) {
    return (a.value > b.value);
}

int main() {
    string s;
    vector<w_entry> c;

    cin >> s;
    for (char i = 'a'; i < 'z'+1; i++) {
        uint32_t temp;
        cin >> temp;
        c.push_back((w_entry) {i, temp});
    }
    sort(c.begin(), c.end(), compare_w_entry);

    string edges = "";
    string mid = "";

    for (auto a : c) {
        size_t cnt = count(s.begin(), s.end(), a.letter);
        if (cnt >= 2) {
            edges += a.letter;
            cnt -= 2;
        }
        while (cnt > 0) {
            mid += a.letter;
            cnt--;
        }
    }
    
    cout << edges << mid;
    reverse(edges.begin(), edges.end());
    cout << edges;
}