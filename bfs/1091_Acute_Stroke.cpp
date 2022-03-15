#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

const int M = 1300, N = 130, L = 70;

int n, m, l, T;
int g[L][M][N];
bool st[L][M][N];
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
struct Node
{
    int x, y, z;
};

int bfs(int x,int y, int z)
{   
    int res = 0;
    Node node = {x, y, z};

    queue<Node> q;
    q.push(node);
    st[x][y][z] = true;
    res ++;

    while(q.size())
    {
        auto t = q.front();
        q.pop();

        for(int i = 0; i < 6; i ++)
        {
            int a = t.x + dx[i], b = t.y + dy[i], c = t.z + dz[i];
            if(a < 0 || a >= l || b < 0 || b >= m || c < 0 || c >= n) continue;
            if(st[a][b][c]) continue;
            if(!g[a][b][c]) continue;
            st[a][b][c] = true;
            q.push({a, b, c});
            res ++;
        }
    }

    return res;
}
int main()
{
    cin >> m >> n >> l >> T;
    for(int i = 0; i < l; i ++)
    {
        for(int j = 0; j < m; j ++)
        {
            for(int k = 0; k < n; k ++)
            {
                cin >> g[i][j][k];
            }
        }
    }

    int res = 0;
    for(int i = 0; i < l; i ++)
    {
        for(int j = 0; j < m; j ++)
        {
            for(int k = 0; k < n; k ++)
            {
                if(!st[i][j][k] && g[i][j][k])
                {
                    int t = bfs(i, j, k);
                    if(t >= T)
                    {
                        res += t;
                    }
                }
            }
        }
    }

    cout << res << endl;
}