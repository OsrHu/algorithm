#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>

using namespace std;

const int N = 1e4 + 10;

int n, m;
int cnt[N];


int main()
{
    cin >> n >> m;

    while(m--)
    {   
        unordered_map<int, int> hs;
        int diff[N], opinion[N];
        for(int i = 1; i <= n; i ++)
        {   
            cin >> opinion[i];
            hs[opinion[i]] ++;
        }

        int maxx = -1;
        for(int i = 1; i <= n; i ++)
        {
            diff[i] = n - hs[opinion[i]];
            maxx = max(maxx, diff[i]);
        }

        for(int i = 1; i <= n ; i ++)
        {
            if(diff[i] == maxx) cnt[i] ++;
        }
    }

    int t;
    for(int i = 1; i <= n; i ++)
    {
        if(i == 1 || cnt[t] < cnt[i]) t = i;
    }
    cout << t << endl;

    return 0;
}