#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010;

int n;
int w[N], tr[N];

void dfs(int u, int &k)
{
    if(u * 2 <= n) dfs(u * 2, k);
    tr[u] = w[k ++];
    if(u * 2 + 1 <= n) dfs(u * 2 + 1, k );
}

int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i ++ )
    {
        cin >> w[i];
    }

    sort(w, w + n);

    int k = 0;
    dfs(1,k);

    for(int i = 1; i <= n; i ++)
    {
        if(i!=1) cout << " ";
        cout << tr[i];
    }

    return 0;
}