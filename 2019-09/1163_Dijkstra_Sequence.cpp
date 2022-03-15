#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 1010;

int n, m, q;
int d[N][N];
int dist[N];
vector<int> path;
bool st[N];

bool dijkstra(int S)
{
    memset(dist, 0x3f, sizeof dist);
    dist[S] = 0;
    
    for(int i = 0; i < n; i ++)
    {
        int t = -1;
        for(int j = 1; j <= n; j ++)
        {
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }

        st[t] = true;

        if(dist[t] != dist[path[i]])
        {
            return false;
        }

        for(int j = 1; j <= n; j ++)
        {
            if(dist[j] > dist[t] + d[t][j])
            {
                dist[j] = dist[t] + d[t][j];
            }
        }
    }
    return true;
}

int main()
{
    cin >> n >> m;
    memset(d, 0x3f, sizeof d);
    while(m --)
    {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = d[b][a] = c;
    }

    cin >> q;
    while(q --)
    {
        path.clear();
        memset(st, 0, sizeof st);
        for(int i = 0; i < n; i ++)
        {
            int x;
            cin >> x;
            path.push_back(x);
        }
        
        if(dijkstra(path[0])) cout << "Yes\n";
        else cout << "No\n"; 
    }
}