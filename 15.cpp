#include <iostream>
#include <list>
#include <vector>

using namespace std;

bool ans = true;

struct GraphNode {
    list<int> connections;
    bool processed = false;
    int category = 0;
};

vector<GraphNode> graph;

void look_through_graph(int id) {
    graph[id].processed = true;
    for (auto a : graph[id].connections) {
        if (!graph[a].processed) {
            graph[a].category = -graph[id].category;
            look_through_graph(a);
        }
        else if (graph[a].category == graph[id].category)
            ans = false;
    }
}

int main() {
    int count, pair_count;
    cin >> count >> pair_count;
    graph.resize(count);

    for (int id = 0; id < pair_count; id++) {
        int input1, input2;
        cin >> input1 >> input2;
        input1--; input2--;

        graph[input1].connections.push_back(input2);
        graph[input2].connections.push_back(input1);
    }

    for (int id = 0; id < count; id++) 
        if (!graph[id].processed) {
            graph[id].category = 1;
            look_through_graph(id);
        }

    if (ans) cout << "YES";
    else cout << "NO";
}