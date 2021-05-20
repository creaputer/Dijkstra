#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N 100000
const int INF = 1e9;

int n; // node
int m; // road

int d[MAX_N + 1]; // shortest distance (cost)
vector<pair<int, int>> graph[MAX_N + 1];

void dijkstra(int start) {
    auto comp2 = [](pair<int, int>& a, pair<int, int>& b) {
        if (a.first == b.first) return a.second > b.second;
    
        return a.first > b.first;
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp2)> pq(comp2);

    fill_n(d, MAX_N + 1, INF);

    d[start] = 0;
    pq.push({d[start], start});

    while (!pq.empty()) {
        pair<int, int> node = pq.top();
        int dist = node.first;
        int now = node.second;

        pq.pop();

        if (d[now] < dist) continue;

        for (int i = 0; i < graph[now].size(); i++) {
            pair<int, int> node = graph[now].at(i);
            int cost = dist + node.second;
            
            if ((d[node.first] == INF) || (cost < d[node.first])) {
                d[node.first] = cost;
                pq.push({d[node.first], node.first});
            }
        }
    }
}

int main() {

    n = 6;
    m = 11;

    graph[1].push_back(make_pair(2, 2));
    graph[1].push_back(make_pair(3, 5));
    graph[1].push_back(make_pair(4, 1));
    graph[2].push_back(make_pair(3, 3));
    graph[2].push_back(make_pair(4, 2));
    graph[3].push_back(make_pair(2, 3));
    graph[3].push_back(make_pair(6, 5));
    graph[4].push_back(make_pair(3, 3));
    graph[4].push_back(make_pair(5, 1));
    graph[5].push_back(make_pair(3, 1));
    graph[5].push_back(make_pair(6, 2));

    dijkstra(1);

    for (int i = 1; i <= n; i++) {
        cout << d[i] << endl;
    }

    return 0;
}