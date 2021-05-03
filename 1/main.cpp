#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int inf = 1e9 + 7;
vector<vector<pair<int, int>>> G;


// расстояния от s до f
int bfs(int s, int f) {
    vector<int> D(G.size(), inf);
    D[s] = 0;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (auto [u, w] : G[v]) {
            if (D[u] == inf) {
                D[u] = D[v] + 1;
                Q.push(u);
            }
        }
    }
    return D[f];
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
    cout << bfs(s, f) << "\n";
    return 0;
}
