#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> graph;
int discovery[1010], finish[1010], curtime;
bool visited[1010];

void dfs(int v) {
    discovery[v] = curtime++;
    visited[v] = true;
    
    for (auto next: graph[v]) {
        if (!visited[next]) {
            dfs(next);
        }
    }

    finish[v] = curtime++;
}

int main() {
    int t, n, m, v;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &m, &v);
        graph.clear();
        graph.resize(n);

        int l, r;
        while (m--) {
            scanf("%d%d", &l, &r);
            graph[l].push_back(r);
            graph[r].push_back(l);
        }
        for (auto& vec: graph) {
            sort(vec.begin(), vec.end());
        }

        for (int i = 0; i < n; ++i) {
            discovery[i] = finish[i] = -1;
        }
        memset(visited, 0, sizeof(bool) * 1010);
        curtime = 0;
        dfs(v);
        
        for (int i = 0; i < n; ++i) {
            printf("%d ", discovery[i]);
        }
        printf("\n");
        
        for (int i = 0; i < n; ++i) {
            printf("%d ", finish[i]);
        }
        printf("\n");
        
        // print the graph
//        for (int i = 0; i < n; ++i) {
//            printf("%d: ", i);
//            for (int j: graph[i]) printf("%d ", j);
//            printf("\n");
//        }
        
    }
    return 0;
}
