#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(const string& a, const string& b) {
    return a + b > b + a;
}

int main() {
    string temp;
    vector<string> stor;

    while (true) {
        cin >> temp;
        if (cin.eof()) break;
        stor.push_back(temp);
    }

    sort(stor.begin(), stor.end(), compare);

    temp = "";
    for (auto i : stor) temp += i;
    temp.erase(0, min(temp.find_first_not_of('0'), temp.size()-1));

    cout << temp;
}