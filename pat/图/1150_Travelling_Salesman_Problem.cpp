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
        int a, b, w;
        cin >> a >> b >> w;
        g[a][b] = g[b][a] = w;
    }
    cin >> k;
    int mindis = INF;
    int minid = 1;
    for(int P = 1; P <= k; P ++)
    {   
        bool flag = true;
        bool TScycle = true;
        int sum = 0;
        int cnt;
        cin >> cnt;
        vector<int> vers(cnt);
        memset(st, 0, sizeof st);
        for(int i = 0; i < cnt; i ++)
        {
            cin >> vers[i];
        }

        for(int i = 0; i + 1 < cnt; i ++)
        {
            int a = vers[i], b = vers[i + 1];
            if(g[a][b] == 0)
            {
                flag = false;
                break;
            }
            else
            {
                sum += g[a][b];
                st[a] = true;
            }
        }

        for(int i = 1; i <= n; i ++)
        {
            if(!st[i])
            {
                TScycle = false;
            }
        }

        if(vers[0] != vers[cnt - 1]) TScycle = false;
            


        if(!flag) printf("Path %d: NA (Not a TS cycle)\n", P);
        else
        {
            if(!TScycle) printf("Path %d: %d (Not a TS cycle)\n", P, sum);
            else
            {
                if(cnt == n + 1) printf("Path %d: %d (TS simple cycle)\n", P, sum);
                else printf("Path %d: %d (TS cycle)\n", P, sum);

                if(sum < mindis)
                {
                    mindis = sum;
                    minid = P;
                }
            }
        }
    }
    printf("Shortest Dist(%d) = %d", minid, mindis);

    return 0;
}