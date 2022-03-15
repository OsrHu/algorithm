#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

const int N = 210, INF = 0x3f3f3f3f;

int n, m;
int g[N][N];
bool st[N];
vector<int> ans;
int total = 0;

void init()
{
    for(int i = 0; i <= n; i ++)
    {
        for(int j = 0; j <= n; j ++)
        {
            if(i == j) g[i][j] = 0;
            else g[i][j] = INF;
        }
    }
}

void floyd()
{
    for(int k = 0; k <= n; k ++)
    {
        for(int i = 0; i <= n; i ++)
        {
            for(int j = 0; j <= n; j ++)
            {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}

void dfs(int u)
{
    st[u] = true;
    ans.push_back(u);

    int minn = INF;
    int next = -1;
    for(int i = 0; i <= n; i ++)
    {   
        if(!st[i] && g[u][i] != INF)
        {   
            if(minn > g[u][i])
            {
                minn = g[u][i];
                next = i;
            }
        }
    }
    if(next != -1)
    {   
        total += g[u][next];
        dfs(next);
    }

    
    
        
        
    
}

int main()
{
    cin >> n >> m;
    init();
    while(m --)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = c;
    }

    floyd();

    dfs(0);

    for(int i = 0; i < ans.size(); i ++)
    {
        if(i != 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;

    vector<int> res;
    if(ans.size() == n + 1) cout << total << endl;
    else
    {
        for(int i = 1; i <= n; i ++)
        {
            if(!st[i])
            {
                res.push_back(i);
            }
        }

        for(int i = 0; i < res.size(); i ++)
        {
            if(i != 0) cout << " "; 
            cout << res[i];
        }
    }
    
    return 0;
}