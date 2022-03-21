#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 10010, M = 2 * N, INF = 0x3f3f3f3f;

int n, m, q;
int S, T;
int minnum, mintcnt;
vector<int>path, tmp;
int h[N], e[M], ne[M], idx;
bool st[N];

unordered_map<int, int> um;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool check(int pre, int cur, int next)
{   
    if(pre == -1) return false;
    if(um[pre * 10000 + cur] != um[cur * 10000 + next]) return true; //T表示换乘
    return false;
}

void dfs(int u, int num, int tcnt, int pre)
{   

    if(u == T)
    {      
        if(num < minnum)
        {
            minnum = num;
            mintcnt = tcnt;
            path.clear();
            path = tmp;
        }
        else if(num == minnum)
        {
            if(tcnt < mintcnt)
            {   
                mintcnt = tcnt;
                path.clear();
                path = tmp;
            }
        }
        return ;
    }
    

    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if(!st[j])
        {
            bool flag = false;
            if(check(pre, u, j)) flag = true;

            if(!flag)
            {   
                tmp.push_back(j);
                st[j] = true;
                dfs(j, num + 1, tcnt, u);
                st[j] = false;
                tmp.pop_back();
            }
            else
            {       
                tmp.push_back(j);
                st[j] = true;
                dfs(j, num + 1, tcnt + 1, u);
                st[j] = false;
                tmp.pop_back();
            }

        }
        
    }


}

int main()
{
    cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 1; i <= n ; i ++)
    {
        cin >> m;
        int pre, cur;
        cin >> pre;
        // um[i].push_back(pre);
        for(int j = 1;  j < m; j ++)
        {
            cin >> cur;
            add(pre, cur), add(cur, pre);
            // PII p(pre, cur);
            // um[make_pair(pre, cur)] = i;
            um[pre * 10000 + cur] = um[cur * 10000 + pre] = i;
            // um[i].push_back(cur);
            pre = cur;
        }

    }

    cin >> q;
    while(q --)
    {
        cin >> S >> T;
        memset(st, 0, sizeof st);
        minnum = INF;
        mintcnt = INF;
        path.clear();
        tmp.clear();
        tmp.push_back(S);
        st[S] = true;
        dfs(S, 0, 0, -1);

        cout << path.size() - 1<< endl;
        int preline = um[path[0] * 10000 + path[1]], j = S;
        for(int i = 1; i< path.size(); i ++)
        {
            if(um[path[i - 1] * 10000 + path[i]] != preline)
            {
                printf("Take Line#%d from %04d to %04d.\n", preline, j, path[i - 1]);
                preline = um[path[i - 1] * 10000 + path[i]];
                j = path[i - 1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preline, j, T);
    }


    return 0;
}