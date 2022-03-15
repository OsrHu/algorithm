#include<iostream>
#include<cstring>
#include<algorithm>
// #pragma GCC optimize(2)

using namespace std;

const int N = 1e5 + 10;

int n;
int e[N], ne[N], h[N], idx;
int ans[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int dfs(int u)
{
    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        ans[u] += dfs(j);
    }

    return ans[u] = ans[u] + 1;
}

int main()
{   
    // ios::sync_with_stdio(0), cin.tie(0);
    scanf("%d", &n);
    memset(h, -1, sizeof h);
    for(int i = 0, b = 2; i < n - 1; i ++, b ++)
    {
        int a;
        scanf("%d", &a);
        add(a, b);
    }

    int m;
    scanf("%d", &m);

    dfs(1);

    while(m --)
    {   
        int t;
        cin >> t;
        cout << ans[t] << endl;
    }
}