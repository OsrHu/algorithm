#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 12;

int ans[N];

int main()
{
    int n;
    cin >> n;
    vector<int>tmp(n);
    for(int i = 0; i < n; i ++) cin >> tmp[i];

    ans[0] = -tmp[0];
    ans[1] = 1;
    int s = 1;
    for(int i = 1; i < n;i ++)
    {
        int a[2] = {0};
        int back[N] = {0};

        a[0] = -tmp[i];
        a[1] = 1;
        
        for(int j = 0; j <= 1; j ++)
        {
            for(int k = 0; k <= s; k ++)
            {
                back[j + k] += ans[k] * a[j];
                // cout << "S " << j + k << " " << ans[k] << " " << a[j] << endl;
            }
        }    
        s += 1;

        memcpy(ans, back, sizeof back);
        // for(int i = 10; i >= 0; i --)
        //     ans[i] = back[i];

        // cout << endl;
    }

    int t = -1;
    bool is_first = true;
    for(int i = s - 1; i >= 0; i --)
    {   
        if(i != s - 1) cout << " ";
        cout << ans[i];
    }



    
}