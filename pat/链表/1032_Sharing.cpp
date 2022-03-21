#include<iostream>
#include<cstring>
#include<iostream>

using namespace std;

const int N = 100010;

int n;
int h1, h2, ne[N];
string e[N];
bool st[N];

int main()
{
    cin >> h1 >> h2 >> n;
    for(int i = 0; i < n; i ++)
    {
        int address,next;
        string data;
        cin >> address >> data >> next;
        e[address] = data, ne[address] = next;
    }

    for (int i = h1; i != -1; i = ne[i])
        st[i] = true;


    for(int i = h2; i != -1;  i = ne[i])
    {
        if(st[i] == true)
        {
            printf("%05d", i);
            return 0;
        }
    }

    cout << "-1" << endl;
    return 0;

}
