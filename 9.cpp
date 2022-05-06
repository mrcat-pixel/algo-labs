#include <iostream>
#include <vector>
#include <unordered_set>
#include <list>
#include <queue>

using namespace std;

int main() {
    uint32_t n, k, p, ret = 0, dist = 0, i = 0;
    cin >> n >> k >> p;

    uint32_t arr[p];
    list<uint32_t> lst[n];
    for (uint32_t i = 0; i < p; i++) {
        cin >> arr[i];
        arr[i]--;
        lst[arr[i]].push_back(i);
    }

    unordered_set<uint32_t> floor;
    priority_queue< pair<uint32_t, uint32_t> > choice; // 1st -- coord, 2nd -- id

    for (; i < p && floor.size() != k; i++) {
        lst[arr[i]].pop_front();

        if (floor.find(arr[i]) == floor.end()) {
            ret++;
            floor.insert(arr[i]);  
        }
        
        if (lst[arr[i]].empty()) dist = UINT32_MAX;
        else dist = lst[arr[i]].front();

        choice.push({dist, arr[i]});
    }

    for (; i < p; i++) {
        lst[arr[i]].pop_front();

        if (floor.find(arr[i]) == floor.end()) {
            ret++;
            floor.insert(arr[i]);

            floor.erase(choice.top().second);
            choice.pop();
        }
        
        if (lst[arr[i]].empty()) dist = UINT32_MAX;
        else dist = lst[arr[i]].front();

        choice.push({dist, arr[i]});
    }

    cout << ret;
}