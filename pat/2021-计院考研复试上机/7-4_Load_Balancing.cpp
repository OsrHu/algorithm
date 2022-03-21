#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>

using namespace std;

const int INF = 0x3f3f3f3f;

int n;

int max_servers = -INF, min_diff = INF;
map<int,int> m;

void dfs(int minl, int maxl, int cnt)
{   
    if(minl * 2 <= maxl) return;

    if(cnt > max_servers)
    {   
        // cout << minl << " " << maxl << " " << cnt << endl;
        max_servers = cnt;
        min_diff = maxl - minl;
    }else if(cnt == max_servers && maxl - minl  < min_diff)
    {
        min_diff = maxl - minl;
    }
    

    int i, j;

    int key = m.rbegin()->first;
    m[key]--;
    if (m[key] == 0) m.erase(key);

    maxl = m.rbegin()->first;
    minl = m.begin()->first;
    int maxll = maxl, minll = minl;
    for(i = key / 2; i >= 1; i --)
    {   
        j = key - i;

        maxl = max(j, maxl);
        minl = min(i, minl);
        if(minl * 2 <= maxl) break;
        m[i] ++;
        m[j] ++;
        dfs(minl, maxl, cnt + 1);
        m[i] --;
        m[j] --;
        if (m[i] == 0) m.erase(i);
        if (m[j] == 0) m.erase(j);

        maxl = maxll;
        minl = minll;
    }

    m[key] ++;

    
    
}

int main()
{
    cin >> n;
    if(n == 3)
    {
        cout << "1 0" << endl;
        return 0;
    }
    for(int i = n / 2; i >= 1; i --)
    {
        int j = n - i;
        if(i * 2 <= j) break;
        m.clear();
        m[i] ++ , m[j] ++;
        dfs(i, j, 2);
    }

    printf("%d %d\n", max_servers, min_diff);
}