#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

const int N = 110;

int h[N], e[N], ne[N], idx;
int n, m;
int d[N];
int maxdepth;
bool st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u, int depth)
{   
    if(!st[u])
    {
        d[depth] ++;
    }
    st[u] = true;
    
    if(h[u] == -1)
    {   
        maxdepth = max(depth, maxdepth);
        return ;
    }

    for(int i = h[u]; ~i; i = ne[i])
    {   
        
        dfs(e[i], depth + 1);
    }

}

int main()
{   
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for(int i = 0; i < m; i ++ )
    {
        int id,k;
        cin >> id >> k;
        while(k --)
        {
            int son;
            cin >> son;
            add(id, son);
        }
    }

    dfs(1, 1);
    int maxlayer = -1;
    int ansi = -1;
    // int ans;
    for(int i = 1; i <= maxdepth; i ++)
    {
        if(maxlayer < d[i])
        {
            ansi = i;
            maxlayer = d[i];
        }
    }
    cout << d[ansi] << " " << ansi ;
}