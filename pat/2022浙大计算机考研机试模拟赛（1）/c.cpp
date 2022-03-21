#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

const int N = 1010;

int n,w;
int l[N],r[N],v[N],idx;

void insert(int& u, int w)
{
    if(!u)
    {
        u = ++ idx, 
        v[u] = w;
    }
    else if(w <= v[u])
    {
        insert(l[u], w);
    }
    else
    {
        insert(r[u], w);
    }
}

vector<int>ans, tmp;
vector<int>aa;
vector<int>in, intmp;
void dfs(int u)
{
    if(u == 0) return;

    dfs(l[u]);
    in.push_back(v[u]);
    dfs(r[u]);
    ans.push_back(v[u]);
}

queue<int>q;
void bfs(int u)
{
    q.push(u);
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        aa.push_back(v[t]);
        if(l[t] != 0) q.push(l[t]);
        if(r[t] != 0) q.push(r[t]);
    }
    
}



int main()
{
    cin >> n;
    int root = 0;
    for(int i = 0; i < n; i ++ )
    {
        int w;
        cin >> w;
        insert(root, w);
    }
    dfs(root);
    bfs(root);
    tmp = ans;
    intmp = in;
    in.clear();
    ans.clear();

    int root2 = 0;
    memset(l, 0, sizeof l);
    memset(r, 0, sizeof r);
    memset(v, 0, sizeof v);
    idx = 0;
    for(int i = 0; i < n; i ++ )
    {
        int w;
        cin >> w;
        insert(root2, w);
    }


    dfs(root2);
    if(ans == tmp && in == intmp)
    {
        cout << "YES\n";
    }
    else cout <<"NO\n";
    for(int i = 0; i < tmp.size(); i ++)
    {
        if(i != 0) cout << " ";
        cout << tmp[i];
    }
    cout << endl;
    for(int i = 0; i < aa.size(); i ++)
    {
        if(i != 0) cout << " ";
        cout << aa[i];
    }
   
    return 0;

}