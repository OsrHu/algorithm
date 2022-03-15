#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

const int N = 1010, M = 10010;

int n,m,k;
int h[N], e[M], ne[M],idx;
int d[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool topsort(int degree[], int a[])
{      

    for(int i = 0; i < n ; i ++)
    {   
        if(degree[a[i]]) return false;
        for(int j = h[a[i]]; ~j ; j = ne[j])
        {
            degree[e[j]] -- ;
        }
    }

    return true;
}

int main()
{   
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while(m -- )
    {
        int a, b;
        cin >> a >> b;
        add(a,b);
        d[b] ++;
    }
    
    cin >> k;
    vector<int>ans;
    int a[N];
    for(int i = 0; i < k; i ++)
    {   
        for(int j = 0; j < n; j ++) cin >> a[j];
        int degree[N];
        for(int i = 1; i <= n; i ++) degree[i] = d[i];

        if(!topsort(degree, a))
        {
            ans.push_back(i);
        }
    }

    for(int i = 0; i < ans.size(); i ++)
    {
        cout << ans[i] << (i == (ans.size() - 1) ? "" : " ") ;
    }
    
}