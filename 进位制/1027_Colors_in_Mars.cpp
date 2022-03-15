#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

char radix[13] = {'0','1','2','3','4','5','6','7','8','9','A','B','C'};


int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    cout << "#";
    cout << radix[a / 13] << radix[a % 13] << radix[b / 13] << radix[b % 13] << radix[c / 13] << radix[c % 13];

    return 0;
}