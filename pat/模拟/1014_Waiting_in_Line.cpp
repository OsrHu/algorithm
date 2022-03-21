/*
核心关键：用队列去模拟，装入这个窗口服务完当前新入队的最后一人的时间
然后一个时间属性由finish维护
 */
#include<iostream>
#include<cstring>
#include<algorithm>
#include <queue>
#include<unordered_map>

using namespace std;


const int N = 25;

int n, m, k, Q;
queue<int> q[N];
int finish[N];

int main()
{
    cin >> n >> m >> k >> Q;

    unordered_map<int, int> hash;    
    for(int i = 1; i<= k; i ++)
    {
        int s;
        cin >> s;
        int t = 0;
        for(int j = 0; j < n; j ++)
        {
            if(i <= n * m)
            {
                if(q[j].size() < q[t].size()) t = j;
            }
            else
            {
                if(q[j].front() < q[t].front()) t = j;
            }
        }
        finish[t] += s;
        if(i > n * m) q[t].pop();
        q[t].push(finish[t]);

        if(finish[t] - s < 540) hash[i] = finish[t];

    }

    while(Q --)
    {
        int id;
        cin >> id;
        if(hash.count(id)) printf("%02d:%02d\n",hash[id] / 60 + 8,hash[id] % 60);
        else cout << "Sorry" << endl;
    }

    return 0;
}



