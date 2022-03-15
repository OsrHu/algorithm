#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

const int N = 1e4 + 10, M = 2 * N;

int h[N], e[M], ne[M], idx;
int n;
bool st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u)
{
    st[u] = true;
    int height = 0;
    for(int i = h[u]; ~i ; i = ne[i])
    {   
        int j = e[i];
        if(!st[j]) height = max(height  , dfs(j) + 1);
    }
    return height;
}

int main()
{   
    memset(h, -1, sizeof h);
    cin >> n;
    int m = n - 1;
    while(m --)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    vector<int> ans;
    int d = -1;
    int cnt = 0;
    for(int i = 1; i <= n; i ++)
    {
        if(!st[i])
        {
            dfs(i);
            cnt ++;
        }
    }

    if(cnt != 1)
    {
        printf("Error: %d components", cnt);
        return 0;
    }


    for(int i = 1; i <= n ; i ++)
    {      
        memset(st, 0, sizeof st);
        d = max(d, dfs(i));    

    }
    
    
    for(int i = 1; i <= n; i ++)
    {   
        memset(st, 0, sizeof st);
        if(dfs(i) == d) ans.push_back(i);
    }

    for(int i = 0; i < ans.size(); i ++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}
