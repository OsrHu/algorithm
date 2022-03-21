#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

int calc(int n)
{
    vector<int> nums;
    while(n) nums.push_back(n % 10), n /= 10;

    int res = 0;
    for(int i = nums.size() - 1; i >= 0; i --)
    {
        int d = nums[i];
        int left = 0, right = 0, power = 1;
        for(int j = nums.size() - 1 ; j > i; j --) left = left * 10 + nums[j];
        for(int j = i - 1; j >= 0; j --)
        {
            right = right * 10 + nums[j];
            power *= 10;
        }

        if(d == 0) res += left * power;
        else if(d == 1) res += left * power + right + 1;
        else res += (left + 1) * power;
    }

    return res;
}

int main()
{
    int n;
    cin >> n;

    cout << calc(n) << endl;
    
    return 0;
}