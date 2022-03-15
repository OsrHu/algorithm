/*
这道题有2个注意的点
首先就是hobby存人的序号，这样可以直接遍历hobby中的序号可以得到
另外，人的序号是1-1000
*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 1010;
int n;
int p[N], cnt[N];
vector<int> hobby[N];

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n;

    for(int i = 1; i <= n; i ++ )
    {
        int cnt;char ch;
        cin >> cnt >> ch;
        while(cnt --)
        {
            int h;
            cin >> h;
            hobby[h].push_back(i);
        }
    }

    for (int i = 1; i <= n; i ++ ) p[i] = i;

    for(int i = 1; i <= 1000; i ++)
    {
        for(int j = 1; j < hobby[i].size(); j ++ )
        {
            int a = hobby[i][0], b = hobby[i][j];
            p[find(a)] = find(b);
            // cnt[find(b)] += cnt[find(a)];
        }
    }

    for(int i = 1; i <= n; i ++) cnt[find(i)] ++;

    sort(cnt + 1, cnt + n + 1, greater<int>() );
    
    int k = 1;
    while(cnt[k]) k ++;

    cout << k - 1<< endl;
    cout << cnt[1];
    for(int i = 2; i < k; i ++)
    {
        cout << " " << cnt[i];
    }
    cout << endl;

    return 0;
}


///  版本2： 我更喜欢这个版本
/*
这道题有2个注意的点
首先就是hobby存人的序号，这样可以直接遍历hobby中的序号可以得到
另外，人的序号是1-1000
*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 1010;
int n;
int p[N], cnt[N];
vector<int> hobby[N];

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n;

    for(int i = 1; i <= n; i ++ )
    {
        int cnt;char ch;
        cin >> cnt >> ch;
        while(cnt --)
        {
            int h;
            cin >> h;
            hobby[h].push_back(i);
        }
    }

    for (int i = 1; i <= n; i ++ ) p[i] = i, cnt[i] = 1;

    for(int i = 1; i <= 1000; i ++)
    {
        for(int j = 1; j < hobby[i].size(); j ++ )
        {
            int a = hobby[i][0], b = hobby[i][j];
            int pa = find(a) , pb = find(b);
            if(pa != pb)
            {
                cnt[pb] += cnt[pa];
                p[pa] = pb;
            }
        }
    }

    int k = 0;
    vector<int> root;
    for(int i = 1; i <= n; i ++)    if(i == p[i]) k++, root.push_back(i);
    cout << k << endl;   

    vector<int> ans;
    for(int i = 0; i < k; i ++) ans.push_back(cnt[root[i]]);

    sort(ans.begin(), ans.end(), greater<int> ());
    
    
    cout << ans[0];
    for(int i = 1;i < k; i ++)
    {
        cout << ' ' << ans[i];
    }

    return 0;
}

