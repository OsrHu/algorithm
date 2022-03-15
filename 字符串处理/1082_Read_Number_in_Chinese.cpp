#include<iostream>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

string num1[] = {
    "ling", "yi", "er", "san", "si", "wu",
    "liu", "qi", "ba", "jiu"
};

string work(int t)
{   
    string res;
    vector<int> nums;
    while(t) nums.push_back(t % 10), t /= 10;
    string num2[] = {"", "Shi", "Bai", "Qian"};

    if(nums.size() < 4)
    {
        nums.push_back(0);
    }
    for(int i = nums.size() - 1; i >= 0; i --)
    {       
        int t = nums[i];
        res += num1[t] + " ";
        if(t && i) res += num2[i] + " "; 
    }
    // cout << res << endl;
    while(res.size() >= 5 && res.substr(res.size() - 5) == "ling ") 
    {
        res = res.substr(0, res.size() - 5);
    }
    


    return res;
}

int main()
{
    int n;
    cin >> n;
    
    if(!n) cout << "ling" << endl;
    else
    {
        if(n < 0) cout << "Fu " , n = -n;

        vector<int>nums;
        
        string num3[] = {"", "Wan", "Yi"};
        while(n) nums.push_back(n % 10000), n = n / 10000;

        string res ;
        for(int i = nums.size() - 1; i >= 0; i --)
        {
            int t = nums[i];
            res += work(t);
            if (t && i) res += num3[i] + ' ';
        }
        
        // while(res.size() > 5 && res.substr(res.size() - 5) == "ling ") res = res.substr(0, res.size() - 5);
        while(res.size() >= 5 && res.substr(0, 5) == "ling ") res = res.substr(5);
        res.pop_back();
        cout << res << endl;
    }

    return 0;
}