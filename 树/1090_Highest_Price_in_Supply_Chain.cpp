#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

const int N = 1e5 + 10, INF = 0x3f3f3f3f;

int n;
double P,r;
int h[N], e[N], ne[N], idx;
int root;
int maxdepth;
int cnt[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u, int depth)
{
    if(h[u] == -1)
    {   
        cnt[depth] ++ ;
        maxdepth = max(depth, maxdepth);
        return ;
    }

    for(int i = h[u];~i;i = ne[i])
    {
        dfs(e[i], depth + 1);
    }
}

int main()
{   
    memset(h, -1, sizeof h); 
    cin >> n >> P >> r;
    for(int i = 0; i < n; i ++ )
    {   
        int father;
        cin >> father;
        if(father == -1)
        {
            root = i;
        }
        else add(father, i);
    }
    dfs(root, 0);

    printf("%.2f %d", P * pow(1 + r / 100, maxdepth), cnt[maxdepth] );
}