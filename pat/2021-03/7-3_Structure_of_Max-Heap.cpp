#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<unordered_map>

using namespace std;

const int N = 1010, M = 20;

int n, m;
// int h[N];// idx从1开始
unordered_map<int, int>h ;
void up(int u)
{
    while(u > 1)
    {
        if(h[u] > h[u / 2])
        {
            swap(h[u], h[u / 2]);
            u = u / 2;
        }
        else 
        {
            break;
        }
        
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
    {
        cin >> h[i];
        up(i);
    }
    unordered_map<int, int> pos;
    for(int i = 1; i <= n; i ++)
    {
        pos[h[i]] = i;
    }

    getchar();
    while(m--)
    {       
        string s;

        getline(cin, s); 

        int x, y;
        if(s.find("root") != -1)
        {   
            sscanf(s.c_str(), "%d is the root", &x);
            if(h[1] == x) cout << "1";
            else cout << "0";
        }
        else if(s.find("siblings") != -1)
        {   
            sscanf(s.c_str(), "%d and %d are siblings", &x, &y);

            if(pos[x] / 2 == pos[y] / 2) cout << "1";
            else cout << "0";
            
        }
        else if(s.find("parent") != -1)
        {
            sscanf(s.c_str(), "%d is the parent of %d", &x, &y);
            if(h[pos[y] / 2] == x) cout << "1";
            else cout << "0";
        }
        else if(s.find("left") != -1)
        {
            sscanf(s.c_str(), "%d is the left child of %d", &x, &y);
            if(h[pos[y] * 2] == x) cout << "1";
            else cout << "0";
        }
        else
        {
            sscanf(s.c_str(), "%d is the right child of %d", &x, &y);
            if(h[pos[y] * 2 + 1] == x) cout << "1";
            else cout << "0";
        }
    }

    return 0;


}