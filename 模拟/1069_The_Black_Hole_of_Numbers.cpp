#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int calc(string num)
{   
    vector<int> v;
    for(int i = 0; i < num.size(); i ++)
    {
        v.push_back(num[i]);
    }

    sort(v.begin(), v.end(), greater<int>());

    string res;
    for(int i = 0; i < v.size(); i ++)
    {
        res += v[i];
    }
    int max = stoi(res);
    reverse(res.begin(), res.end());
    int min = stoi(res);

    int ans = max - min;
    
    printf("%04d - %04d = %04d\n", max, min, ans);

    return ans;

}

int main()
{
    string num;
    cin >> num;

    while(true)
    {   
        num = string(4 - num.size(), '0') + num;
        int ans = calc(num);
        if(ans == 6174 || ans == 0) break;
        num = to_string(ans);
    }
}