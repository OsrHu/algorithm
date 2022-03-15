#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

const int N = 30;

int n;
int l[N], r[N], v[N], h[N], idx;
int pos[N];
queue<int> q;
vector<int> ans;

void update(int u)
{
    h[u] = max(h[l[u]], h[r[u]]) + 1;
}

void R(int& u)
{
    int p = l[u];
    l[u] = r[p], r[p] = u;
    update(u), update(p);
    u = p;
}

void L(int& u)
{
    int p = r[u];
    r[u] = l[p], l[p] = u;
    update(u), update(p);
    u = p;
}

int get_balance(int u)
{
    return h[l[u]] - h[r[u]];
}

void insert(int& u, int w)
{
    if(!u) u = ++idx, v[u] = w;
    else if(w < v[u])
    {
        insert(l[u], w);
        if(get_balance(u) == 2)
        {
            if(get_balance(l[u]) == 1) R(u);
            else L(l[u]), R(u);
        }
    }
    else
    {
        insert(r[u], w);
        if(get_balance(u) == -2)
        {
            if(get_balance(r[u]) == -1) L(u);
            else R(r[u]), L(u);
        }
    }
    update(u);
}

bool flag = true;
void bfs(int root)
{
    q.push(root);
    pos[root] = 1;

    while(!q.empty())
    {
        int t = q.front();
        ans.push_back(v[t]);
        if(pos[t] > n) flag = false;
        q.pop();

        if(l[t] != 0)
        {
            q.push(l[t]);  
            pos[l[t]] = pos[t] * 2; 
        }

        if(r[t] != 0)
        {
            q.push(r[t]);
            pos[r[t]] = pos[t] * 2 + 1; 
        }
    }

    for(int i = 0; i < ans.size(); i ++)
    {
        if(i != 0) cout << " ";
        cout << ans[i]; 
    }

    cout << endl;

    if(flag) cout << "YES\n";
    else cout << "NO\n";

}

int main()
{
    cin >> n;
    int root = 0;
    for(int i = 0; i < n; i ++)
    {   
        int w;
        cin >> w;
        insert(root, w);
    }

    bfs(root);

    return 0;
}