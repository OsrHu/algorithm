#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 30;

int n;
int l[N], r[N];
string w[N];
bool has_father[N];
bool f = true;

string dfs(int u)
{
    string res;

    if(u == -1)
    {
        return "";
    }
    res = "(" + res;
    if(l[u] == -1 && r[u] != -1)
    {
        res += w[u];
        res += dfs(r[u]);
        res = res + ")";
        return res;
    }

    res += dfs(l[u]);
    res += dfs(r[u]);
    res += w[u];
    res = res + ")";

    return res;
}

int main()
{
    cin >> n;
    memset(l, -1, sizeof l);
    memset(r, -1, sizeof r);
    for(int i = 1; i <= n; i ++)
    {
        cin >> w[i] >> l[i] >> r[i];
        if(l[i] != -1) has_father[l[i]] = true;
        if(r[i] != -1) has_father[r[i]] = true;
    }

    int root = 1;
    while(has_father[root]) root ++;

    string res = dfs(root);

    cout << res << endl;
    
    
}