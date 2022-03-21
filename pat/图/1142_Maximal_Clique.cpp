#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 210;

int n, m, q;
int g[N][N];
bool st[N];
int vers[N];

bool isClique(int k)
{
    for(int i = 0; i < k; i ++)
    {
        for(int j = i + 1; j < k; j ++)
        {
            if(!g[vers[i]][vers[j]]) return false;
        }
    }
    return true;
}

bool isMaxClicue(int k)
{
    memset(st, 0, sizeof st);
    for(int i = 0; i < k; i ++) st[vers[i]] = true;

    for(int i = 1; i <= n; i ++)
    {
        if(!st[i])
        {   
            bool success = true; //是否这个点能和里面的点都相连，默认都是
            for(int j = 0; j < k; j ++)
            {
                if(g[i][vers[j]] == 0) // 只要有两个顶点不是相邻的
                {
                    success = false;
                    break;
                }
            }
            if(success) return false;
        }
    }
    return true;
}


int main()
{
    cin >> n >> m;

    for(int i = 0; i < m; i ++)
    {
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = 1;
    }
    cin >> q;

    while(q --)
    {
        int k; cin >> k;
        for(int i = 0; i < k; i ++) cin >> vers[i];
        if(isClique(k))
        {
            if(isMaxClicue(k))
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "Not Maximal" << endl;
            }
        }
        else
        {
            cout << "Not a Clique" << endl;
        }
    }
}