#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;

int mp[N];
int Rank[N];
int p[N];


int main()
{  
    int n;
    cin >> n;

    for(int a = 0; a < n; a ++)
    {
        int b;
        cin >> b;
        mp[a] = b;
        p[b] = 1;
    }

    int root = 0;
    while(p[root] == 1) root ++;

    int cnt = 0;

    while(root != -1)
    {   
        Rank[root] = ++cnt;
        int j = mp[root];
        root = j;
    }
    // cout << endl;

    for(int i = 0; i < cnt; i ++)
    {
        if(i != 0) cout << " ";
        cout << Rank[i];
    }
}

//解法2
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;

int Rank[N];
int p[N];
int e[N], ne[N], h[N], idx;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u, int k)
{   
    if(u == -1) return ;
    Rank[u] = k;
    
    for(int i = h[u]; ~i; i = ne[i])
    {
        dfs(e[i], k + 1);
        
    }
}

int main()
{  
    int n;
    cin >> n;
    memset(h, -1, sizeof h);
    for(int a = 0; a < n; a ++)
    {
        int b;
        cin >> b;
        add(a, b);
        p[b] = 1;
    }

    int root = 0;
    while(p[root] == 1) root ++;

    int cnt = 0;

    dfs(root, 1);
    // cout << endl;

    for(int i = 0; i < n; i ++)
    {
        if(i != 0) cout << " ";
        cout << Rank[i];
    }
}