// 算法设计：短的绳子被折次数越多损失越小
//  哈夫曼树


#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1e4 + 10;

int n;
double a[N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i ++ ) cin >> a[i];

    sort(a, a + n);

    double sum = 0;
    for(int i = 1; i < n; i ++)
    {
        if(i == 1) sum += (a[0] + a[i]) / 2.0;
        else sum =  (sum + a[i]) / 2.0;
    }

    cout << (int)sum << endl;
}