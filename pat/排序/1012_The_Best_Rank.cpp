/*
一般用结构体存
但是这里学生第二维是等同的
二分第一次出现的位置

排序 + 二分
*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<cmath>

using namespace std;

unordered_map<string, vector<int>> grades;
vector<int> q[4];

int get_rank(vector<int> &a, int x)
{
    int l = 0, r = a.size() - 1;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(x >= a[mid]) r = mid;
        else l = mid + 1;
    }

    return l + 1;
}

int main()
{
    int n,m;
    cin >> n >> m;

    for(int i = 0; i < n; i ++)
    {
        string id;
        int t[4] = {0};
        cin >> id;
        for(int j = 1; j < 4; j ++)
        {
            cin >> t[j];
            t[0] += t[j];
        }
        t[0] = round(t[0] / 3);
        for(int j = 0; j < 4; j ++)
        {
            q[j].push_back(t[j]);
            grades[id].push_back(t[j]);
        }
    }

    for(int i = 0; i < 4; i ++ ) sort(q[i].begin(), q[i].end(), greater<int>());

    string names = "ACME";

    while(m --)
    {
        string id;
        cin >> id;
        if(grades.count(id) == 0) cout << "N/A" << endl;
        else
        {
            int res = n + 1;
            char c;
            for(int i = 0; i < 4;i ++)
            {
                int rank = get_rank(q[i], grades[id][i]);
                if(rank < res)
                {
                    res = rank;
                    c = names[i];
                }
            }
            cout << res << ' ' << c << endl;
        }
    }

    return 0;
}
