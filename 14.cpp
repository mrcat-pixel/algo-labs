#include <iostream>
#include <list>
#include <unordered_set>
#include <vector>

using namespace std;

// list contains connections to other nodes
vector<list<int>> graph; 

unordered_set<int> processed_nodes;
unordered_set<int> excluded_nodes;

bool contains(unordered_set<int> set, int id) {
    return set.find(id) != set.end();
}

int look_through_graph(int id) {
    processed_nodes.insert(id);
    int ret = 0;

    for (auto a : graph[id]) {
        if (contains(excluded_nodes, a)) continue;

        if (contains(processed_nodes, a)) {
            ret++;
            continue;
        }

        ret += look_through_graph(a);
    }

    processed_nodes.erase(id);
    excluded_nodes.insert(id);
    return ret;
}

int main() {
    int count, ret = 0;
    cin >> count;
    graph.resize(count);

    for (int id = 0; id < count; id++) {
        int input;
        cin >> input;
        input--;
        graph[input].push_back(id);
    }

    for (int id = 0; id < count; id++) {
        if (!contains(excluded_nodes, id))
            ret += look_through_graph(id);
    }

    cout << ret;
}