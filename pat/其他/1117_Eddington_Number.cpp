#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;

int n;
int riding[N];

int main()
{   
    cin >> n;
    for(int i = 1; i <= n ; i ++)
    {
        cin >> riding[i];
    }

    sort(riding + 1, riding + 1 + n, greater<int>());

    int i;
    for(i = 1; i <= n ; i ++)
    {
       if(riding[i] <= i) break;
    }
    cout << (i - 1) << endl;

}