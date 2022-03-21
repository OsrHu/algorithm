#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int n;  
    
    cin >> n;
    vector<int> ans;
    for(int i = 0; i < n; i ++)
    {
        int t;
        cin >> t;
        ans.push_back(t);
    }

    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        int t;
        cin >> t;
        ans.push_back(t);
    }

    sort(ans.begin(), ans.end());

    cout << ans[(ans.size() - 1) / 2];


}