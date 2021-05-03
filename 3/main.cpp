#include <iostream>
#include <vector>
using namespace std;
const int inf = 1e9 + 7;
vector<vector<pair<int, int>>> G;


int FordBellman(int s, int f) {
    vector<int> D(G.size(), inf);
    D[s] = 0;
    for (int i = 1; i < G.size(); ++i) {
        for (int v = 1; v < G.size(); ++v) {
            for (auto [u, w] : G[v]) {
                D[u] = min(D[u], D[v] + w);
            }
        }
    }
    //
    for (int v = 1; v < G.size(); ++v) {
        for (auto [u, w] : G[v]) {
            if (D[v] + w < D[u]) {
                return -1; // достижимы отрицательные циклы
            }
        }
    }
    if (D[f] == inf) {
        return 0; // пути нет
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
    cout << FordBellman(s, f) << "\n";
    return 0;
}
