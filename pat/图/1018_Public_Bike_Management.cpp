// 我觉得dfs把所有前缀树路径找出来比较好，再用dfs遍历z
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int cmax, n, S, m;

int c[N];
int g[N][N];
int dist[N];
bool st[N];
vector<int> path, ans;
int send = INF, bring = INF;

void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[S] = 0;
    for(int i = 0; i < n; i ++)
    {
        int t = -1;
        for(int j = 0; j <= n; j ++)
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        st[t] = true;

        for(int j = 0; j <= n; j ++)
            if(dist[j] > dist[t] + g[t][j])
                dist[j] = dist[t] + g[t][j];
    }
}

void dfs(int u, int s, int mins)
{
    if(u)
    {
        s -= cmax / 2 - c[u];
        mins = min(mins, s);
    }

    if(u == S)
    {
        int sd = abs(min(mins, 0));
        int bg = sd + s;

        if(sd < send) ans = path, send = sd, bring = bg;
        else if(sd == send && bg < bring) ans = path, bring = bg;

        return ;
    }

    for(int i = 1; i <= n; i ++)
    {   

        if(dist[u] == dist[i] + g[u][i])
        {
            path.push_back(i);
            dfs(i, s, mins);
            path.pop_back();
        }
    }


}

int main()
{   
    cin >> cmax >> n >> S >> m;

    for(int i = 1; i <= n; i ++)
    {
        cin >> c[i];
    }

    memset(g, 0x3f, sizeof g);
    while(m--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        g[a][b] = g[b][a] = c;
    }

    dijkstra();

    path.push_back(0);
    
    dfs(0, 0, 0);

    cout << send << " 0";

    for(int i = 1; i < ans.size(); i ++)
    {
        cout << "->" << ans[i];
    }

    cout << " " << bring << endl;

    return 0;
}