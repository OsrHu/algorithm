#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_set>
#include<vector>
// #pragma GCC optimize(2)

using namespace std;

const int N = 20, M = 1e3 + 10;

int x, y;
int n, m;
int a[N][M];
unordered_set<int>s;
// int exist[MAXX];
vector<int>e;

bool st[N];

bool find(int t)
{
    for(auto x: s)
    {   
        if(s.find(x + t) != s.end()) return true;
    }

    return false;
}

int main()
{
    cin >> x >> y;
    s.insert(x);
    s.insert(y);
    // diff.insert(abs(x - y));

    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= m; j ++)
        {
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= m; i ++)
    {   
        vector<int>ans;
        for(int j = 1; j <= n; j ++)
        {
            int t = a[j][i];
            if(!st[j])
            {
                if(!s.count(t) && find(t))
                {
                    s.insert(t);             
                }
                else
                {
                    ans.push_back(j);
                    st[j] = true;
                }
            }
            else continue;
        }
        if(ans.size())
        {
            for(int j = 0; j < ans.size(); j ++)
            {
                printf("Round #%d: %d is out.\n", i, ans[j]);
            }
        }
    }

    vector<int>ans;
    for(int i = 1; i <= n; i ++)
    {
        if(!st[i])
        {
            ans.push_back(i);
        }
    }

    if(ans.size())
    {   
        cout << "Winner(s):";
        for(int i = 0; i < ans.size(); i ++)
        {
            cout << " " << ans[i];
        }
    }
    else
    {
        cout << "No winner.\n";
    }
}