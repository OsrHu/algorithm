#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<vector>

using namespace std;

const int N = 1e4 + 10;

int n, m;
struct Record
{
    int time, status;

    bool operator<(const Record t)const
    {
        return time < t.time;
    }
};

unordered_map<string, vector<Record>> Cars;

int get(vector<Record>& record)
{
    int t = 0;
    for(int i = 0; i < record.size(); i +=2)
    {
        t += record[i + 1].time - record[i].time;
    }
    return t;
}

int main()
{
    cin >> n >> m;

    char id[10], status[10];
    for(int i = 0; i < n; i ++)
    {
        int hh, mm, ss;
        scanf("%s %d:%d:%d %s",id, &hh, &mm, &ss, status);
        int t = hh * 3600 + mm * 60 + ss;
        int s = 0;
        if (status[0] == 'o') s = 1;
        Cars[id].push_back({t, s});
    }

    vector<Record> v;
    unordered_map<string, vector<Record>> vv;

    for(auto item: Cars)
    {   
        auto id = item.first;
        auto records = item.second;
        sort(records.begin(), records.end());
        vector<Record> tmp;
        
        for(int i = 0; i + 1 < records.size(); i ++)
        {
            auto a = records[i], b = records[i + 1];
            if(a.status == 0 && b.status == 1)
            {
                tmp.push_back(a);
                tmp.push_back(b);
                v.push_back(a);
                v.push_back(b);
                i ++;
            }
        }
        vv[id] = tmp;
    }

    sort(v.begin(), v.end());

    int k = 0, sum = 0;
    while(m --)
    {
        int hh, mm, ss;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int t = hh * 3600 + mm * 60 + ss;

        while(k < v.size() && v[k].time <= t)
        {   
            if (v[k].status == 0) sum ++ ;
            else sum -- ;
            k ++;
        }

        cout << sum << endl;
    }

    int maxt = 0;
    for(auto item: vv) maxt = max(maxt, get(item.second));

    vector<string> res;
    for(auto item: vv)
    {
        if (get(item.second) == maxt)
            res.push_back(item.first);
    }
    
    sort(res.begin(), res.end());//字典序排序

    for (int i = 0; i < res.size(); i ++ ) printf("%s ", res[i].c_str());

    printf("%02d:%02d:%02d\n", maxt / 3600, maxt % 3600 / 60, maxt % 60);

    return 0;

}