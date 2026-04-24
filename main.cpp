#include <bits/stdc++.h>
using namespace std;

// Problem: Max fish collectible starting from any water cell (>0), moving only through adjacent water cells.
// Approach: Treat each connected component of positive cells as a region; sum values in each component, take maximum.
// Use DFS/BFS over grid with 4-direction adjacency. Complexity O(m*n).

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    if (!(cin >> m >> n)) {
        return 0;
    }
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    vector<vector<char>> vis(m, vector<char>(n, 0));
    long long best = 0;
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] > 0 && !vis[i][j]) {
                long long sum = 0;
                deque<pair<int,int>> dq;
                dq.emplace_back(i, j);
                vis[i][j] = 1;
                while (!dq.empty()) {
                    auto [x, y] = dq.front(); dq.pop_front();
                    sum += a[x][y];
                    for (int dir = 0; dir < 4; ++dir) {
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];
                        if (nx >= 0 && nx < m && ny >= 0 && ny < n && a[nx][ny] > 0 && !vis[nx][ny]) {
                            vis[nx][ny] = 1;
                            dq.emplace_back(nx, ny);
                        }
                    }
                }
                best = max(best, sum);
            }
        }
    }

    cout << best << "\n";
    return 0;
}

