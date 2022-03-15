#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 60;

int start[N], Next[N], End[N];

int main()
{
    string s[5] = {"S", "H", "C", "D", "J"};

    int k;
    cin >> k;

    for(int i = 1; i <= 54; i ++)
    {
        start[i] = i;
    }

    for(int i = 1; i <= 54; i ++)
    {
        cin >> Next[i];
    }

    while(k --)
    {
        for(int i = 1; i <= 54; i ++)
        {
            End[Next[i]] = start[i];
        }

        for(int i = 1; i <= 54; i ++)
        {
            start[i] = End[i];
        }

    }

    for(int i = 1; i <= 54; i ++)
    {   
        if(i != 1) cout << " ";
        cout << s[(start[i] - 1) / 13] << (start[i] - 1) % 13 + 1;
    }

}