#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

int n, b;

int main()
{
    cin >> n >> b;
    vector<int>rnum;
    while(n)
    {
        rnum.push_back(n % b);
        n /= b;
    }

    vector<int>num = rnum;
    reverse(num.begin(), num.end());

    if(num == rnum) cout << "Yes\n";
    else cout << "No\n";

    for(int i = 0; i < num.size(); i ++)
    {
        if(i != 0) cout << " ";
        cout << num[i];
    }

    return 0;

}