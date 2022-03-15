//窗口之间无区别，
//模拟题想着怎么存

#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>


using namespace std;

const int N = 1e4 + 10;

int n, k;
struct People
{
    int arrive_time;
    int service_time;

    bool operator<(const People& t) const
    {
        return arrive_time < t.arrive_time;
    }
}people[N];

int main()
{
    cin >> n >> k;

    for(int i = 0; i < n; i ++) 
    {
        int hh, mm, ss, service_time;
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &service_time);
        int arrive_time = hh * 3600 + mm * 60 + ss;
        people[i] = {arrive_time, service_time * 60};
    }

    sort(people, people + n);

    priority_queue<int, vector<int>, greater<int>> windows; 
    
    for(int i = 0; i < k; i ++)
    {
        windows.push(8 * 3600);
    }

    double sum = 0;
    int cnt = 0;


    for(int i = 0; i < n; i ++)
    {
        if(people[i].arrive_time > 17 * 3600) break;

        int start_time = max(windows.top(), people[i].arrive_time);
        windows.pop();

        int wait_time = start_time - people[i].arrive_time;
        sum += wait_time;
        cout << sum << endl;
        cnt ++;
        windows.push(start_time + people[i].service_time);
    
    }

    printf("%.1lf", sum / cnt / 60);

    return 0;

}