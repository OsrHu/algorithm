#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 110;

int n,m;
int h[N], e[N], ne[N], idx;
int d[N];
// bool st[N]; 如果根据题目，那不就用设置了
int maxdepth;

void add(int a,int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u, int depth)
{   
    // st[u] = true;

    if(h[u] == -1)
    {
        d[depth] += 1;
        maxdepth = max(maxdepth, depth);
        return;
    }

    for(int i = h[u];~i;i = ne[i])
    {   
        // if(!st[e[i]])
        // {
             dfs(e[i], depth + 1);
        // }
    }
}

int main()
{   

    memset(h, -1, sizeof h);
    cin >> n >> m;
    while(m --)
    {
        int id,k;
        cin >> id >> k;
        while(k --)
        {
            int b;
            cin >> b;
            add(id, b);
        }
    }

    dfs(1, 0);
    
    for(int i = 0; i <= maxdepth; i ++)
    {
        if(i) cout << " ";
        cout << d[i];
    }

}