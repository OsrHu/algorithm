#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;

int m, n;
unordered_map<int, int> um;

int main()
{
    cin >> m >> n;

    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < m; j ++)
        {
            int tmp;
            cin >> tmp;
            um[tmp] ++;
        }
    }
    
    int num = -1, max = -1;
    for(auto x: um)
    {
        if(x.second  > max)
        {
            num = x.first;
            max = x.second;
        }
    }

    cout << num << endl;
}