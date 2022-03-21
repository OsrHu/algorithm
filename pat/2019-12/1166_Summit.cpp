#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 210;

int n, m, head, l;
int a[N];
bool st[N];
int g[N][N];

int main()
{
    cin >> n >> m;
    while(m --)
    {
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = 1;
    }

    cin >> head;
    for(int i = 1; i <= head; i ++)
    {   
        cin >> l;
        memset(st, 0, sizeof st);
        for(int j = 0; j < l; j ++)
        {
            cin >> a[j];
            st[j] = true;
        }

        bool is_connect = true;
        for(int j = 0; j < l; j ++)
        {
            for(int k = 0; k < j; k ++)
            {
                if(g[a[j]][a[k]] == 0)
                {
                    is_connect = false;
                    break;
                }
            }
        }

        bool other_connect;
        int idx;
        for(int j = 1; j <= n; j ++)
        {   
            other_connect = true;
            if(!st[j])
            {
                for(int k = 0; k < l; k ++)
                {
                    if(!g[j][a[k]])
                    {
                        other_connect = false;
                        break;
                    }
                }

                if(other_connect == true)
                {
                    idx = j;
                    break;
                }
            }

            
        }

        if(is_connect && !other_connect) printf("Area %d is OK.\n", i);
        else if(is_connect && other_connect) printf("Area %d may invite more people, such as %d.\n", i, idx);
        else printf("Area %d needs help.\n", i);
    }

    return 0;
}