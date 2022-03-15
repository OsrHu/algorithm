#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>

using namespace std;

int a,b;

int main()
{
    cin >> a >> b;
    int sum = a + b;
    if(sum < 0) 
    {
        cout << "-";
        sum = -sum;
    }

    string ans = to_string(sum);
    string res;
    for(int i = ans.size() - 1, cnt = 1; i >= 0; i --, cnt++)
    {
        res = ans[i] + res;
        if(cnt % 3 == 0 && i != 0) res = ',' + res;
    }

    cout << res << endl;

    return 0;
   

}