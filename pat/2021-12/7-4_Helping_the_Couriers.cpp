#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_set>
#include<vector>

using namespace std;

const int N = 1010, INF = 0x3f3f3f3f;

int n, m;
int g[N][N];

struct Package
{
    int dealine, y, p;
}packages[N];

void init()
{
    for(int i = 0; i <= n; i ++)
        for(int j = 0; j <= n; j ++)
        {
            if(i == j) g[i][j] = 0;
            else g[i][j] = INF;
        }
}

void floyd()
{
    for(int k = 0; k <= n; k ++)
    {
        for(int i = 0; i <= n; i ++)
        {
            for(int j = 0; j <= n; j ++)
            {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}

int main()
{
    int hh, mm;
    int S = 0;
    scanf("%d %d %d:%d", &n, &m, &hh, &mm);
    S = hh * 3600 + mm * 60;

    for(int i = 1; i <= n; i ++)
    {   
        int y, p;
        scanf("%d:%d %d %d", &hh, &mm, &y, &p);
        int t = hh * 3600 + mm * 60;
        packages[i] = {t, y, p};
    }

    init();
    while(m --)
    {
        int a, b, c;
        cin >> a >> b >> c;
        c = c * 60;
        g[a][b] = g[b][a] = c;
    }

    floyd();

    int k;
    cin >> k;
    
    int total_pay = -1, total_time = INF;
    for(int i = 1; i <= k; i ++)
    {       
        int p;
        unordered_set<int> s;
        vector<int> root(1, 0);

        for(int j = 0; j < n; j ++)
        {     
            cin >> p;
            root.push_back(p);
            s.insert(p);
        }
        if(s.size() != n) continue;
        int tmp_pay = 0, tmp_time = S;
        for(int i = 0; i + 1 < root.size(); i ++)
        {   
            int a = root[i], b = root[i + 1];
            if(g[a][b] == INF) continue;
            tmp_time += g[a][b];
    
            if(packages[b].dealine >= tmp_time) tmp_pay += packages[b].y;
            else tmp_pay += packages[b].y - packages[b].p;
        }
        tmp_time += g[root[root.size() - 1]][0];
        if(total_pay < tmp_pay)
        {
            total_pay = tmp_pay;
            total_time = tmp_time;
        }else if(total_pay == tmp_pay && total_time > tmp_time)
        {
            total_time = tmp_time;
        }    
       
    }
    hh = total_time / 3600 % 24 ;
    mm = total_time % 3600 / 60;
    printf("%d %02d:%02d\n", total_pay, hh, mm);

    return 0;
}