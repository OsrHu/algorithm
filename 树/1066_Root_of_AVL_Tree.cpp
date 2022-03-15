#include<iostream>

#include<cstring>

#include<algorithm>

using namespace std;

const int N = 30;

int l[N], r[N], v[N], h[N], idx;


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
    if(!u) u = ++ idx, v[u] = w;
    else if(w < v[u])
    {
        insert(l[u], w);
        if(get_balance(u) == 2)
        {
            if(get_balance(l[u]) == 1) R(u);
            else L(l[u]),R(u);
        }
    }
    else
    {
        insert(r[u], w);
        if(get_balance(u) == -2)
        {
            if(get_balance(r[u]) == -1) L(u);
            else R(r[u]),L(u);
        }
    }

    update(u);

}

int main()
{
    int n, root = 0;
    cin >> n;

    while (n -- )
    {
        int w;
        cin >> w;
        insert(root, w);
    }

    cout << v[root] << endl;

    return 0;
}