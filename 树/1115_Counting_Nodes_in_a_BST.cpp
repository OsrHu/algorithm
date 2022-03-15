#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010;

int n,w;
int l[N],r[N],v[N],idx;
int cnt[N],maxdepth;

void insert(int& u, int w)
{
    if(!u)
    {
        u = ++ idx, 
        v[u] = w;
    }
    else if(w <= v[u])
    {
        insert(l[u], w);
    }
    else
    {
        insert(r[u], w);
    }
}

void dfs(int u, int depth)
{
    if(u == 0) return;

    cnt[depth] ++;
    maxdepth = max(depth, maxdepth);

    dfs(l[u], depth + 1);
    dfs(r[u], depth + 1);

}

int main()
{
    cin >> n;
    int root = 0;
    for(int i = 0; i < n; i ++ )
    {
        int w;
        cin >> w;
        insert(root, w);
    }

    dfs(root, 0);

    cout << cnt[maxdepth] << " + " << cnt[maxdepth - 1]  << " = " << cnt[maxdepth - 1] + cnt[maxdepth];

    return 0;

}