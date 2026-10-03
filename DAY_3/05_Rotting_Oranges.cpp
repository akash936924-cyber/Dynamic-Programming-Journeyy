#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int orangesRotting(vector<vector<int>>& grid) {

    int rows = grid.size();
    int cols = grid[0].size();

    queue<pair<int, int>> q;

    int fresh = 0;

    // Rotten oranges queue mein daalo
    // Fresh oranges count karo
    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {

            if (grid[i][j] == 2) {
                q.push({i, j});
            }
            else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    int minutes = 0;

    // 4 directions
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while (!q.empty() && fresh > 0) {

        int size = q.size();

        // Ek level = 1 minute
        for (int i = 0; i < size; i++) {

            pair<int, int> current = q.front();
            q.pop();

            int r = current.first;
            int c = current.second;

            // 4 neighbours check karo
            for (int d = 0; d < 4; d++) {

                int nr = r + dx[d];
                int nc = c + dy[d];

                // Boundary check
                if (nr < 0 || nr >= rows ||
                    nc < 0 || nc >= cols) {

                    continue;
                }

                // Fresh orange mila
                if (grid[nr][nc] == 1) {

                    grid[nr][nc] = 2;

                    fresh--;

                    q.push({nr, nc});
                }
            }
        }

        minutes++;
    }

    // Fresh orange bach gaya
    if (fresh > 0) {
        return -1;
    }

    return minutes;
}

int main() {

    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    int answer = orangesRotting(grid);

    cout << answer << endl;

    return 0;
}