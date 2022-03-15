#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<string>

using namespace std;

const int N = 1010;

int n, m;
int postorder[N], inorder[N];
unordered_map<int, int> pos;
int l[N], r[N];
int d[N], p[N];
int root;
bool isfull = true;

int build(int il,int ir, int pl, int pr)
{
    int root = postorder[pr];

    int k = pos[root];

    if(il < k) l[root] = build(il, k-1, pl, pl + k - 1 - il);
    if(k < ir) r[root] = build(k+1, ir, pr - ir + k, pr-1);

    return root;
}

void dfs(int u, int depth)
{
    if(u == -1) return ;

    d[u] = depth;
    if((l[u] == -1 && r[u] != -1) || (l[u] == -1 && r[u] != -1)) isfull = false;
    dfs(l[u], depth + 1);
    dfs(r[u], depth + 1);
    p[l[u]] = u;
    p[r[u]] = u;

}

bool check(string s)
{
    int u, v;

    if(s.find("root") != -1)
    {   
        sscanf(s.c_str(), "%d is the root", &u);
        return root == u;
    }
    else if(s.find("siblings") != -1)
    {
        sscanf(s.c_str(), "%d and %d are siblings", &u, &v);
        return p[u] == p[v];
    }
    else if(s.find("parent") != -1)
    {
        sscanf(s.c_str(), "%d is the parent of %d", &u, &v);
        return l[u] == v || r[u] == v;
    }
    else if(s.find("left") != -1)
    {
        sscanf(s.c_str(), "%d is the left child of %d", &u, &v);
        return l[v] == u;

    }
    else if(s.find("right") != -1)
    {
        sscanf(s.c_str(), "%d is the right child of %d", &u, &v);
        return r[v] == u;

    }
    else if(s.find("same") != -1)
    {
        sscanf(s.c_str(), "%d and %d are on the same level", &u, &v);
        return d[u] == d[v];
    }
    else if(s.find("full") != -1)
    {
        return isfull;
    }
}

int main()
{
    cin >> n;
    memset(l, -1, sizeof l);
    memset(r, -1, sizeof r);
    for(int i = 0; i < n; i ++)
    {
        cin >> postorder[i];
    }

    for(int i = 0; i < n; i ++)
    {
        cin >> inorder[i];
        pos[inorder[i]] = i;
    }

    root = build(0, n-1, 0, n-1);
    dfs(root, 0);
    cin >> m;
    getchar();
    while(m --)
    {
        string setence;
        getline(cin, setence);
        if(check(setence))
        {
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }

}