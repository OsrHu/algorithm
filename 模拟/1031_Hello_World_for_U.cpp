#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n1, n2, n3;

    string s;
    cin >> s;
    int N = s.size();
    n1 = (N + 2) / 3;

    n3 = n1;
    n2 = N + 2 - n1 - n3;

    for(int i = 0 ; i < n1 - 1; i ++)
    {
        cout << s[i];
        for(int j = 1; j < n2 - 1; j ++) cout << " ";
        cout << s[N - 1 - i] << endl;
    }

    for(int i = n1 - 1; i < n1 + n2 - 1; i ++)
    {
        cout << s[i];
    }

    return 0;



}