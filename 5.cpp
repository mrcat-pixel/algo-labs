#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check_cow(vector<uint32_t>* spaces, uint32_t cow, uint32_t n) {
    uint32_t cow_res = 1;
    uint32_t last_cow_coord = spaces->at(0);
    for (auto a : *spaces) {
        if (a - last_cow_coord >= n) {
            last_cow_coord = a;
            cow_res++;
        }
    }
    return (cow_res >= cow);
}

int main() {
    uint32_t sz;
    uint32_t cow;
    cin >> sz >> cow;

    vector<uint32_t> spaces;

    for (uint32_t i = 0; i < sz; i++) {
        uint32_t tmp;
        cin >> tmp;
        spaces.push_back(tmp);
    }
    sort(spaces.begin(), spaces.end());
    
    //binary search
    uint32_t left = 0;
    uint32_t right = spaces.back() - spaces.front() + 1;
    while (right - left > 1) {
        uint32_t mid = (left+right)/2;
        if (check_cow(&spaces, cow, mid)) left = mid;
        else right = mid;
    }
    cout << left;
}

/*
На прямой расположены стойла, в которые необходимо расставить коров так, чтобы минимальное расcтояние между коровами было как можно больше.
Формат ввода

В первой строке вводятся числа N (2 < N ≤ 105) – количество стойл и K (1 < K < N ) – количество коров. Во второй строке задаются N натуральных чисел в порядке возрастания – координаты стойл (координаты не превосходят 109).
Формат вывода

Выведите одно число – наибольшее возможное допустимое расстояние.
*/