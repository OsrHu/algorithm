#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010;


int n, m, k;
int d[N][N];
bool st[N];

void dfs(int u)
{
    st[u] = true;
    
    for(int i = 1; i <= n; i ++)
    {
        if(!st[i] && d[u][i]) dfs(i);
    }

}

int main()
{
    cin >> n >> m >> k;
    while(m --)
    {
        int a, b;
        cin >> a >> b;
        d[a][b] = d[b][a] = 1;
    }

    while(k --)
    {   
        memset(st, 0, sizeof st);
        int u;
        cin >> u;
        st[u] = true;
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            if(!st[i])
            {
                dfs(i);
                cnt ++;
            }
        }

        cout << cnt - 1 << endl;
    }
    return 0;
}