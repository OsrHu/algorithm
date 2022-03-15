#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<vector>
#include<set>
#include<sstream>
#include<cctype>

using namespace std;

const int N = 1e4 + 10;

int n;
int w[N], milk[N];
int milk1[N];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> w[i];

    for(int i = 0, j; i < n; )
    {   
        j = i + 1;
        while(j < n && w[j] <= w[j - 1]) j ++;

        int t = j - 1;
        milk[t--] = 200;
        while(t >= i)
        {   
            if(w[t] == w[t + 1]) milk[t] = milk[t + 1];
            else milk[t] =  milk[t + 1] + 100; 
            t = t - 1;
        }
        
        i = j;
    }
    // for(int i = n - 1; i - 1>= 0; i --)
    // {
    //     if(w[i] - w[i - 1] >= 0 && milk[i] <= milk[i - 1]) milk[i] += 100;
    // }
    for(int i = n - 1, j; i >= 0; )
    {
        j = i - 1;
        while(j >= 0 && w[j] <= w[j + 1]) j --;
        // cout << j << " " << i << endl;
        int t = j + 1;
        milk1[t ++] = 200;
        while(t <= i)
        {
            if(w[t] == w[t - 1]) milk1[t] = milk1[t - 1];
            else milk1[t] =  milk1[t - 1] + 100; 
            t = t + 1;
        }

        i = j;
    }

    int ans = 0;
    for(int i = 0; i < n; i ++)
    {
        ans += max(milk[i], milk1[i]);
    }
    // cout << endl;

    // int ans = max(res, res1);

    cout << ans << endl;

    return 0;
}