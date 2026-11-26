#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 1005

int grid[MAXN][MAXN];
int distStart[MAXN][MAXN];
int distHome[MAXN][MAXN];
int n, m;

typedef struct {
    int r, c;
} Point;

int main() {
    if (scanf("%d %d", &n, &m) != 2) return 1;
    
    int sr = 0, sc = 0;
    int tr = 0, tc = 0;
    
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
    Point q[MAXN * MAXN];
    int head = 0, tail = 0;
    
    distStart[sr][sc] = 0;
    q[tail++] = (Point){sr, sc};
    
    while (head < tail) {
        Point cur = q[head++];
        for (int i = 0; i < 4; i++) {
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && 
                distStart[nr][nc] == -1 && grid[nr][nc] != 1) {
                distStart[nr][nc] = distStart[cur.r][cur.c] + 1;
                q[tail++] = (Point){nr, nc};
            }
        }
    }
    
    // BFS from home
    memset(distHome, -1, sizeof(distHome));
    head = 0; tail = 0;
    
    distHome[tr][tc] = 0;
    q[tail++] = (Point){tr, tc};
    
    while (head < tail) {
        Point cur = q[head++];
        for (int i = 0; i < 4; i++) {
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && 
                distHome[nr][nc] == -1 && grid[nr][nc] != 1) {
                distHome[nr][nc] = distHome[cur.r][cur.c] + 1;
                q[tail++] = (Point){nr, nc};
            }
        }
    }
    
    // Find minimum dist(start->shop) + dist(shop->home) over all shops
    int ans = 2000000000;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 4 && distStart[i][j] >= 0 && distHome[i][j] >= 0) {
                int d = distStart[i][j] + distHome[i][j];
                if (d < ans) ans = d;
            }
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}
