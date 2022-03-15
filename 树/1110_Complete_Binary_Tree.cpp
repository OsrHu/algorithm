#include<iostream>
#include<cstring>
#include<algorithm>


using namespace std;

const int N = 30;

int n;
int l[N], r[N];
bool is_hasfaher[N];
// int tr[N];
// int cnt;
int maxid,maxk;

void dfs(int u, int k)
{
    if(u == -1) return ;

    if(k > maxk)
    {   
        maxk = k;
        maxid = u;
    }

    dfs(l[u], k * 2);
    // tr[cnt ++] = u;
    dfs(r[u], k * 2 + 1);
}

int main()
{   
    memset(l, -1, sizeof l);
    memset(r, -1, sizeof r);

    cin >> n;
    for(int i = 0; i < n; i ++ )
    {
        string lc, rc;
        cin >> lc >> rc;

        if(lc != "-")
        {
            l[i] = stoi(lc);
            is_hasfaher[l[i]] = true;
        }
        if(rc != "-")
        {   
            r[i] = stoi(rc);
            is_hasfaher[r[i]] = true;
        }
    }

    int root = 0;
    while(is_hasfaher[root]) root++;

    dfs(root, 1);

    
    if(maxk == n )
    {
        cout << "YES" << " " << maxid;
    }
    else
    {
        cout << "NO" << " " << root;
    }
    
    
}