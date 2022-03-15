#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];
unordered_map<int, bool> check;

int main()
{
    cin >> n;
    for(int i = 0 ; i < n; i ++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    for(int i = 0; i < n; i ++)
    {
        if(a[i] > 0 && check[a[i]] == false) check[a[i]] = true;
    }

    int num = 1;
    while(num)
    {   
        if(check[num] == false)
        {
            cout << num << endl;
            break;
        }
        num ++;
    }

    return 0;
}
