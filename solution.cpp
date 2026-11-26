#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 1005;
int grid[MAXN][MAXN];
int distStart[MAXN][MAXN];
int distHome[MAXN][MAXN];
int n, m;

struct Point {
    int r, c;
};

int main() {
    if (scanf("%d %d", &n, &m) != 2) return 1;
    
    int sr = 0, sc = 0; // start position (value 2)
    int tr = 0, tc = 0; // home position (value 3)
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            if (scanf("%d", &val) != 1) return 1;
            grid[i][j] = val;
            if (val == 2) {
                sr = i; sc = j;
            } else if (val == 3) {
                tr = i; tc = j;
            }
        }
    }
    
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    
    // BFS from start
    memset(distStart, -1, sizeof(distStart));
    queue<Point> q;
    distStart[sr][sc] = 0;
    q.push({sr, sc});
    
    while (!q.empty()) {
        Point cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && 
                distStart[nr][nc] == -1 && grid[nr][nc] != 1) {
                distStart[nr][nc] = distStart[cur.r][cur.c] + 1;
                q.push({nr, nc});
            }
        }
    }
    
    // BFS from home
    memset(distHome, -1, sizeof(distHome));
    distHome[tr][tc] = 0;
    q.push({tr, tc});
    
    while (!q.empty()) {
        Point cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && 
                distHome[nr][nc] == -1 && grid[nr][nc] != 1) {
                distHome[nr][nc] = distHome[cur.r][cur.c] + 1;
                q.push({nr, nc});
            }
        }
    }
    
    // Find minimum dist(start->shop) + dist(shop->home) over all shops
    int ans = 2e9;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 4 && distStart[i][j] >= 0 && distHome[i][j] >= 0) {
                ans = min(ans, distStart[i][j] + distHome[i][j]);
            }
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}
