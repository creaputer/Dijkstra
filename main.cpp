#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n; // node
int m; // road
const int INF = 0;

#define MAX_N 10000

int Distance[MAX_N + 1];
bool visited[MAX_N + 1] = { 0, };
vector<pair<int, int>> graph[MAX_N + 1];

void dijkstra(int start) {
    auto comp2 = [](pair<int, int>& a, pair<int, int>& b) {
        if (a.first == b.first) return a.second > b.second;
    
        return a.first > b.first;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp2)> q(comp2);

    Distance[1] = 0;
    q.push(make_pair(Distance[1], 1));
    visited[1] = true;

    while (!q.empty()) {
        pair<int, int> node = q.top();
        visited[node.second] = true;
        q.pop();

        for (int i = 0; i < graph[node.second].size(); i++) {
            pair<int, int> tNode = graph[node.second].at(i);
            if (visited[tNode.first] != false) continue;

            int tDistance = node.first + tNode.second;
            
            if ((Distance[tNode.first] == INF) || (tDistance < Distance[tNode.first])) {
                Distance[tNode.first] = tDistance;
                q.push(make_pair(Distance[tNode.first], tNode.first));
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
        cout << Distance[i] << endl;
    }

    return 0;
}