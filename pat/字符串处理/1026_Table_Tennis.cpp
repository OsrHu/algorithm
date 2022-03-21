/**
 人员来的时候，有空桌子按序号从小分配
 如果所有桌子被占满，排队
 如果有vip桌子，队列中的VIP能优先获得

 这份代码只能在PTA上通过， 不能在ACWING，ACWING把数组N2时间卡掉了，可以使用优先队列存储；

 **/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;

const int N = 10010, M = 110, INF = 0x3f3f3f3f;

int n, k, m;
struct People
{
    int arrive_time, service_time;
    int wating_time, start_time;
    bool is_vip;
    bool operator<(const People& t) const
    {
        return arrive_time < t.arrive_time;
    }  
}peoples[N];

bool flag[N] = {false};
bool cmp(People a, People b) {
    if(a.start_time != b.start_time) return a.start_time < b.start_time;
    return a.arrive_time < b.arrive_time;
}
struct Table
{   
    int end_time;
    bool is_vip;
    int num;
}tables[M];


int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        int hh, mm, ss, service_time;
        int t;
        bool is_vip = false;

        scanf("%d:%d:%d %d %d",&hh, &mm, &ss, &service_time, &t);
        if(t) is_vip = true;

        peoples[i].arrive_time = hh * 3600 + mm * 60 + ss;
        peoples[i].service_time = min(service_time * 60, 120 * 60);
        peoples[i].is_vip = is_vip;
    }

    cin >> k >> m;

    for(int i = 0; i < m; i ++)
    {
        int id;
        cin >> id;
        tables[id].is_vip = true;
    }

    for(int i = 1; i <= k; i ++)
    {
        tables[i].end_time = 8 * 3600;
    }

    sort(peoples, peoples + n);

    int i = 0;
    vector<People> ans;
    while(i < n)
    {   

        while(flag[i] == true && i < n) i ++;
        if(i >= n) break;
        int person_id = i; // 0 ~ n - 1

        //到来之前全是忙碌状态
        bool is_free = true;
        for(int j = 1; j <= k; j ++)
        {
            if(peoples[person_id].arrive_time <= tables[j].end_time )
            {
                is_free = false;
            }
        }
        if(is_free)
        {
            for(int j = 1; j <= k; j ++)
            {
                tables[j].end_time = peoples[person_id].arrive_time;
            }
        }


        int idx = -1, minend_time = INF;

        for(int j = 1; j <= k; j ++)
        {
            if(tables[j].end_time < minend_time)
            {
                minend_time = tables[j].end_time;
                idx = j;
            }
        }
        if(tables[idx].end_time >= 21 * 3600) break;
        

  

        if(tables[idx].is_vip)
        {
            for(int j = 0; j < n; j ++)
            {
                if(flag[j] == false && peoples[j].is_vip && peoples[j].arrive_time <= tables[idx].end_time)
                {
                    person_id = j;
                    break;
                }
            }
        }
        else if(peoples[person_id].is_vip)
        {
            for(int j = 1; j <= k; j ++)
            {
                if(tables[j].end_time == minend_time && tables[j].is_vip)
                {
                    idx = j;
                    break;
                }
            }
        }  


        if(peoples[person_id].arrive_time >= 21 * 3600) break;


        flag[person_id] = true;

        peoples[person_id].start_time = max(peoples[person_id].arrive_time, tables[idx].end_time);
        peoples[person_id].wating_time = round((peoples[person_id].start_time - peoples[person_id].arrive_time) / 60.0);


        tables[idx].end_time = max(peoples[person_id].arrive_time, tables[idx].end_time) + peoples[person_id].service_time;

        // cout << i << " "  << person_id << " " << idx <<" " << tables[idx].end_time << " " << peoples[person_id].arrive_time << endl;

        tables[idx].num ++; 

        auto person = peoples[person_id];
        ans.push_back(person);


        
        
        
    }

    sort(ans.begin(), ans.end(), cmp);

 
    for(int i = 0; i < ans.size(); i ++)
    {   

        auto people = ans[i];
        printf("%02d:%02d:%02d ", people.arrive_time / 3600, people.arrive_time % 3600 / 60, people.arrive_time % 60);
        printf("%02d:%02d:%02d ", people.start_time / 3600, people.start_time % 3600 / 60, people.start_time % 60);
        printf("%d\n", people.wating_time);
    }

    cout << tables[1].num;
    for(int i = 2; i <= k; i ++)
    {
        cout << " " << tables[i].num;
    }

    return 0;
    
    
}
