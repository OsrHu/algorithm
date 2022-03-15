#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 10010;

int n, m, q;
struct Egde
{
    int a, b;
}e[N];
bool st[N];

// void add(int a, int b)
// {
//     e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
// }

// int dfs(int u)
// {
//     st[u] = true;

//     int cnt = 0;
//     for(int i = h[u]; ~i; i = ne[i])
//     {   
//         int j = e[i];
//         if(!st[j]) cnt += dfs(j) + 1;
//     }
    
//     return cnt ;
// }

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        cin >> e[i].a >> e[i].b;
    }

    cin >> q;
    while(q --)
    {
        memset(st, 0, sizeof st);
        int k;
        cin >> k;
        int cnt = 0;
        for(int i = 0; i < k; i ++)
        {
            int u;
            cin >> u;
            st[u] = true;
        }


        for(int i = 0; i < m; i ++)
        {
            if(st[e[i].a] == false && st[e[i].b] == false)
            {
                break;
            }
            cnt ++;
        }

        cout << (cnt == m ? "Yes" : "No") << endl;
    }

}