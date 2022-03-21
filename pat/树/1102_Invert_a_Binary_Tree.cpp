#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

const int N = 20;

int n;
int l[N], r[N];
bool has_father[N];
queue<int>q;
// bool st[N];

void dfs_reverse(int u)
{   
    if(u == -1) return;

    dfs_reverse(l[u]);

    dfs_reverse(r[u]);

    swap(l[u], r[u]);
   
}

void dfs(int u,int &k)
{
    if(u == -1) return;

    dfs(l[u], k);
    cout << u;
    if( ++ k != n) cout << " ";
    dfs(r[u], k);
}

void bfs(int root)
{   
    int cnt = 0;
    q.push(root);
    // st[root] = true;
    while(!q.empty())
    {   

        int t = q.front();
        q.pop();
        cout << t;
        if(++cnt != n) cout << " ";
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
        char lc,rc;
        cin >> lc >> rc;
        if(lc != '-') 
        {
            l[i] = lc - '0';
            has_father[l[i]] = true;
        }
        if(rc != '-')
        {
            r[i] = rc - '0';
            has_father[r[i]] = true;
        }
    }

    int root = 0;
    while(has_father[root])
    {
        root ++;
    }

    dfs_reverse(root);


    bfs(root);
    cout << endl;
    int k = 0;

    dfs(root, k);

}