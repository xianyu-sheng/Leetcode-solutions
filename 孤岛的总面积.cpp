#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

// BFS 遍历一个岛屿，返回其面积（如果它是孤岛）
int bfs(const vector<vector<int>>& table, vector<vector<bool>>& visited, int x, int y) {
    int area = 0;
    queue<pair<int, int>> que;
    que.push({x, y});
    visited[x][y] = true;
    area++;

    // 标记这个岛屿是否接触到边缘
    bool isIsolated = true;  // 假设是孤岛，直到发现有格子在边缘

    while (!que.empty()) {
        auto cur = que.front(); que.pop();
        int cx = cur.first, cy = cur.second;

        // 如果当前点在边缘，那么这个岛屿不是孤岛
        if (cx == 0 || cx == table.size() - 1 || cy == 0 || cy == table[0].size() - 1) {
            isIsolated = false;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cx + dir[i][0];
            int ny = cy + dir[i][1];

            if (nx < 0 || nx >= table.size() || ny < 0 || ny >= table[0].size()) continue;
            if (visited[nx][ny] || table[nx][ny] != 1) continue;

            visited[nx][ny] = true;
            que.push({nx, ny});
            area++;
        }
    }

    // 只有当所有格子都不在边缘时，才返回面积
    return isIsolated ? area : 0;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> table(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> table[i][j];
        }
    }

    vector<vector<bool>> visited(N, vector<bool>(M, false));
    int totalArea = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j] && table[i][j] == 1) {
                totalArea += bfs(table, visited, i, j);
            }
        }
    }

    cout << totalArea << endl;
    return 0;
}