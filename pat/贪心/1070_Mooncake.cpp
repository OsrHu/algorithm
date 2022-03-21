#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010;

int n, d;
struct Mooncake
{
    double tons;
    double totalprice;
    double price;

    bool operator< (const Mooncake&t) const
    {
        return price > t.price;
    }
}mooncake[N];

int main()
{
    cin >> n >> d;
    for(int i = 0; i < n; i ++)
    {
        double tons;
        cin >> tons;
        mooncake[i].tons = tons;
    }

    for(int i = 0; i < n; i ++)
    {
        double totalprice;
        cin >> totalprice;
        mooncake[i].totalprice = totalprice;
        mooncake[i].price = totalprice / mooncake[i].tons;
    }


    sort(mooncake, mooncake + n);

    double res = 0;
    for(int i = 0; i < n; i ++)
    {
        if(d == 0) break;
        
        if(mooncake[i].tons < d)
        {
            res += mooncake[i].tons * mooncake[i].price;
            d -= mooncake[i].tons;
        }
        else
        {
            res += d * mooncake[i].price;
            d -= d;
        }
    }

    printf("%.2lf", res);

    return 0;
}