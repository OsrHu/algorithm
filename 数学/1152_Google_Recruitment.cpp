#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

int n, k;

bool isprime(int x)
{
    if(x < 2) return false;
    for(int i = 2; i * i <= x; i ++)
    {
        if(x % i == 0) return false;
    }
    return true;
}

int main()
{
    cin >> n >> k;
    string s;
    cin >> s;
    for(int i = 0; i + k <= s.size(); i ++)
    {
        string number = s.substr(i, k);
        int num = stoi(number);
        if(isprime(num))
        {
            cout << number << endl;
            return 0;
        }
    }
    cout<<"404"<<endl;
	return 0;
}