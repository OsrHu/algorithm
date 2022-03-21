#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 501 , M = 2* N;

int n, m;
int h[N], e[M], ne[M], idx;
// int g[N][N];
int outdegree[N];
int cnt;
bool st[N];
int p[N];

void add(int a,int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

// void dfs(int u)
// {
//     if(st[u]) return;

//     st[u] = true;
//     // cnt ++;

//     for(int i = 1;i <= n;i ++)
//     {
//         if(!st[i] && g[u][i])
//             dfs(i);
//     }
// }

int main()
{   
    ios::sync_with_stdio(false),cin.tie(0);
    // memset(h, -1, sizeof h);
    cin >> n >> m;
    for(int i = 1;i <= n; i ++) p[i] = i;

    for(int i = 0; i < m; i ++)
    {
        int a,b;
        cin >> a >> b;
        // g[a][b] = g[b][a] = 1;
        // add(a,b), add(b, a);
        p[find(a)] = find(b); //合并集合，如果已经是同一个集合会自动忽略
        outdegree[a] ++;
        outdegree[b] ++;
    }

    for(int i = 1; i <= n; i ++)
    {
        cout << outdegree[i] << (i == n ? "" : " ") ;
    }
    
    for(int i = 1; i <= n; i ++)
    {
        if(p[i] == i) cnt ++;
    }

    // for(int i = 1;i <=n; i ++)
    // {
    //     if(!st[i]) {cnt++ , dfs(i);}
    // }
    // dfs(1);
    int odd  = 0;
    cout << endl;
    if(cnt == 1)
    {
        for(int i = 1; i <= n;i ++)
        {
            if(outdegree[i] % 2)
                odd  ++;
        }


        if(odd  == 0) cout << "Eulerian";
        else if(odd  == 2) cout << "Semi-Eulerian";
        else cout << "Non-Eulerian";
    }
    else cout << "Non-Eulerian";

    return 0;
}