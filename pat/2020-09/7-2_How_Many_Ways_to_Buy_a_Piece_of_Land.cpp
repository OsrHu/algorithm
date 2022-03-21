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

int n, m;
int a[N];

int main()
{   
    int res = 0;

    cin >> n >> m;

    for(int i = 0; i < n; i ++)
    {
        cin >> a[i];
        if(m >= a[i]) res ++;
    }

    for(int i = 0; i < n; i ++)
    {   
        int tmp = a[i];
        int j = i + 1;
        while(j < n && tmp + a[j] <= m) tmp += a[j ++];
        // cout << i << " " << j << endl;
        res += j - i - 1;
    }

    cout << res << endl;

    return 0;
    

}