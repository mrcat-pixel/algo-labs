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

/*
У Васи есть n свинок-копилок, свинки занумерованы числами от 1 до n. Каждая копилка может быть открыта единственным соответствующим ей ключом или разбита.

Вася положил ключи в некоторые из копилок (он помнит, какой ключ лежит в какой из копилок). Теперь Вася собрался купить машину, а для этого ему нужно достать деньги из всех копилок. При этом он хочет разбить как можно меньшее количество копилок (ведь ему еще нужно копить деньги на квартиру, дачу, вертолет…). Помогите Васе определить, какое минимальное количество копилок нужно разбить.
Формат ввода

В первой строке содержится число n — количество свинок-копилок (1 ≤ n ≤ 100). Далее идет n строк с описанием того, где лежит ключ от какой копилки: в i-й из этих строк записан номер копилки, в которой находится ключ от i-й копилки.
Формат вывода

Выведите единственное число: минимальное количество копилок, которые необходимо разбить.
*/