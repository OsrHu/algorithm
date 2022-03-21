#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

const int N = 110;

int n;
int l[N], r[N], v[N];
int inorder[N];
int cnt;
queue<int> q;
// bool st[N];


void dfs(int u)
{   
    if(u == -1) return;

    dfs(l[u]);
    v[u] = inorder[cnt ++];
    dfs(r[u]);
}

void bfs(int u,int &k)
{
    q.push(u);
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        cout << v[t];

        if(++k != n) cout << " ";
        if(l[t] != -1) q.push(l[t]);
        if(r[t] != -1) q.push(r[t]);
    }
    
}


int main()
{   
    memset(l, -1, sizeof l);
    memset(r, -1, sizeof r);
    cin >> n;
    for(int i = 0; i < n; i ++ )
    {
        int ln,rn;
        cin >> ln >> rn;
        if(ln != -1) l[i] = ln;
        if(rn != -1) r[i] = rn;

    }

    for(int i = 0; i < n; i ++)
    {
        cin >> inorder[i];
    }

    sort(inorder, inorder + n);

    dfs(0);

    int k = 0;
    bfs(0, k);

    return 0;

}