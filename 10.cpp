#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    uint32_t front_half_size = 0, back_half_size = 0, n;
    cin >> n;

    deque<uint32_t> front_half, back_half;

    for (uint32_t i = 0; i < n; i++) {
        string input;
        cin >> input;
        switch (input[0]) {
            case '+':
                cin >> input;
                back_half.push_back(stol(input));
                back_half_size++;
                break;
            case '*':
                cin >> input;
                back_half.push_front(stol(input));
                back_half_size++;
                break;
            default: 
                cout << front_half.front() << endl;
                front_half.pop_front();
                front_half_size--;
        }
        if (back_half_size > front_half_size) {
            front_half.push_back(back_half.front());
            back_half.pop_front();
            front_half_size++;
            back_half_size--;
        }
    }
}