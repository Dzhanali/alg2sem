#include <iostream>
#include <vector>
using namespace std;
vector<vector<pair<int, int>>> G;
vector<bool> visited;


void dfs(int v) {
    visited[v] = true;
    for (auto [u, w] : G[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
}


int main(int argc, char* argv[]) {
    char* f_in = "input.txt";
    char* f_out = "output.txt";
    if (argc >= 2) {
        f_in = argv[1];
        if (argc >= 3) {
            f_out = argv[2];
        }
    }
    freopen(f_in, "r", stdin);
    freopen(f_out, "w", stdout);
    int s, f;
    cin >> s >> f;
    int n, m, type;
    cin >> n >> m >> type;
    G.resize(n + 1);
    visited.assign(n + 1, false);
    for (int i = 0; i < m; ++i) {
        int a, b, w = 1;
        cin >> a >> b;
        if (type == 2 || type == 4) {
            cin >> w;
        }
        G[a].emplace_back(b, w);
        if (type == 3 || type == 4) {
            G[b].emplace_back(a, w);
        }
    }
    dfs(s);
    cout << (int)visited[f] << "\n";
    return 0;
}
