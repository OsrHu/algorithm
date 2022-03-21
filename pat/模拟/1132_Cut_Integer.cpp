#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>

using namespace std;

int n;

int main()
{
    cin >> n;
    while(n --)
    {
        string num;
        cin >> num;

        int k = num.size() / 2;
        int left = stoi(num.substr(0, k));
        int right = stoi(num.substr(k));

        if(left * right != 0 && (stoi(num) % (left * right) == 0) )
            cout << "Yes\n";
        else cout << "No\n";

    }
}