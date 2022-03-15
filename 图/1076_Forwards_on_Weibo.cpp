#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

const int N = 1010, M = 100010;

int n, l, q;
int h[N], e[M], ne[M], idx;
bool st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void bfs(int u)
{   
    int res = 0;
    queue<int> q;
    q.push(u);
    st[u] = true;
    
    for(int level = 0 ; level < l; level ++)
    {      
        int qs = q.size();
        for(int i = 0; i < qs; i ++)
        {
            int t = q.front();
            q.pop();
            for(int j = h[t]; ~j; j = ne[j])
            {   
                int k = e[j];
                if(!st[k])
                {   
                    q.push(k);
                    res ++;
                    st[k] = true;
                }
            }
        }
    }

    cout << res << endl;
}

int main()
{
    cin >> n >> l;
    memset(h, -1, sizeof h);
    for(int i = 1; i <= n ; i ++)
    {
        int k;
        cin >> k;
        while(k --)
        {
            int a;
            cin >> a;
            add(a, i);
        }
    }


    cin >> q;
    while(q --)
    {
        int u;
        cin >> u;
        memset(st, 0, sizeof st);
        bfs(u);
    }
}