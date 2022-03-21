#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<queue>
#include<cctype>
#include<cmath>
#include<sstream>

using namespace std;

int n;

int work(int t)
{
    int res = 0;
    while(t)
    {   
        res += pow((t % 10), 2);
        t = t / 10;
    }

    return res;
}

int main()
{
    cin >> n;
    while(n --)
    {
        set<int> s;
        int t;
        cin >> t;
        int cnt = 0;
        bool flag = true;
        while(t != 1)
        {   
            if(s.count(t))
            {
                flag = false;
                break;
            }
            s.insert(t);
            t = work(t);
            cnt ++;
        }

        if(!flag) cout << t << endl;
        else cout << cnt << endl;
    }
}