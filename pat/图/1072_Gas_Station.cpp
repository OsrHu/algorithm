#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>

using namespace std;

const int N = 1050, INF = 0x3f3f3f3f;

int n, m, k, D;
int g[N][N];
int dist[N];
bool st[N];

int get(string s)
{
    if(s[0] == 'G') return n + stoi(s.substr(1));
    return stoi(s);
}

void dijkstra(int S, int& mind, int& sumd)
{
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    dist[S] = 0;

    for(int i = 0; i < n + m; i ++)
    {
        int t = -1;
        for(int j = 1; j <= n + m; j ++)
        {
            if(!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        }

        st[t] = true;

        for(int j = 1; j <= n + m; j ++)
        {
            if(dist[j] > dist[t] + g[t][j])
                dist[j] = dist[t] + g[t][j];
        }
    }


    for(int i = 1; i <= n; i ++)
    {   
        if(dist[i] > D)
        {
            mind = -INF;
            return ;
        }
    }

    mind = INF, sumd = 0;
    for(int i = 1; i <= n; i ++)
    {
        mind = min(mind, dist[i]);
        sumd += dist[i];
    }
}

int main()
{
    cin >> n >> m >> k >> D;
    memset(g, 0x3f, sizeof g);
    while(k --)
    {
        string a, b;
        int c;
        cin >> a >> b >> c;
        int x = get(a), y = get(b);
        g[x][y] = g[y][x] = c;
    }

    int res = -1, mind = 0, sumd = INF;
    for(int i = n + 1; i <= n + m; i ++)
    {
        int d1, d2;
        dijkstra(i, d1, d2);

        if(d1 > mind) res = i, mind = d1, sumd = d2;
        else if(d1 == mind && d2 < sumd) res = i, sumd = d2;
    }

    if (res == -1) cout << "No Solution" << endl;
    else printf("G%d\n%.1lf %.1lf\n", res - n, (double)mind, (double) sumd / n + 1e-8 );


}