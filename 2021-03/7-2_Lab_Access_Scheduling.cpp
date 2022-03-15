#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 2e3 + 10;

int n;
struct Person
{
    int start_time, end_time;

    bool operator<(const Person& t)const
    {
        if(end_time != t.end_time) return end_time < t.end_time;
        return start_time < t.start_time;
    }
}persons[N];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
    {   
        int ihh, imm, iss, ohh, omm, oss;
        scanf("%d:%d:%d %d:%d:%d", &ihh, &imm, &iss, &ohh, &omm, &oss);
        int enter = ihh * 3600 + imm * 60 + iss;
        int  exit = ohh * 3600 + omm * 60 + oss;

        persons[i] = {enter, exit};
    }

    sort(persons, persons + n);

    int ans_num = 0;
    // int start_time = persons[0].start_time;
    // cout << persons[4].start_time / 3600 << endl;
    // cout << persons[5].start_time / 3600 << endl;
    int last = -1;
    int cur_end = 0;
    // 区间合并
    // for(int i = 0; i < n; ++ i)
    // {
    //     if(persons[i].start_time >= cur_end)
    //     {
    //         ++ans_num;
    //         cur_end = persons[i].end_time;
    //     }
    // }

    for(int i = 0; i < n;)
    {   
        int more_person = 0;
        int j = i + 1;
        if(last != -1 && persons[i].start_time < persons[last].start_time)
        {   
            // cout << i << " " << last << endl;
            i++;
            continue;
        }
    //     ----->
    //         ----->
    //    ------------>
        while(j < n && persons[j].start_time < persons[i].end_time) j ++;

        // more_person = j - i - 1;
        
        // cout << i << " "  << j << " " << more_person << endl;

        // if(more_person > 1)
        // {
        //     i++;
        // }
        // else
        // {
        last = i;
        i = j;
        
        ans_num ++;
        
    }

    cout << ans_num << endl;

    return 0;
}