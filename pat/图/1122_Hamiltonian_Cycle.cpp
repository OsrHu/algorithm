#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 210, INF = 0x3f3f3f3f ;

int g[N][N];
bool st[N];
int n, m, k;

int main()
{
    cin >> n >> m;
    while(m --)
    {
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = 1;
    }

    cin >> k;
    while(k --)
    {
        int cnt;
        cin >> cnt;
        vector<int> vers(cnt);
        memset(st, 0, sizeof st);
        for(int i = 0; i < cnt; i ++)
        {
            cin >> vers[i];
        }
        bool cycle = true;

        for(int i = 0; i + 1 < cnt ; i ++)
        {
            int a = vers[i], b = vers[i + 1];
            if(g[a][b] == 0)
            {
                cycle = false;
                break;
            }
            else
            {
                st[a] = true;
            }
        }
        for(int i = 1; i <= n; i ++)
        {
            if(!st[i]) 
            {
                cycle = false; 
                break;
            }
            
        }

        if(vers[0] != vers[cnt - 1])
        {   
            cycle = false; 
        }
        

        if(!cycle) cout << "NO\n";
        else
        {
            if(cnt == n + 1) cout << "YES\n";
            else cout << "NO\n";
        }    
        
    }

    return 0;
}