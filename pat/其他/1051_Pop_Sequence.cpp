#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>

using namespace std;

const int M = 1010, N = 1010, K = 1010;

int m, n, k;
stack<int> sk;
int seq[N];
int flag;

int main()
{
    cin >> m >> n >> k;
    
    while(k --)
    {   
        while(!sk.empty())
        {
            sk.pop();
        }
        flag = false;

        for(int i = 1; i <= n; i ++) cin >> seq[i];
        for(int i = 1, j = 1; i <= n; i ++ )
        {   
        
            sk.push(i); // 按题目要求压栈

            if(sk.size() > m)
            {   
                cout << "NO" << endl;
                flag = true;
                break;
            }    
            
            while( !sk.empty() && seq[j] == sk.top())
            {   
                sk.pop();
                j ++; 
            }
        }

        if(flag == false)
        {
            if(sk.empty())
            {
                cout << "YES" << endl;
            }
            else cout << "NO" << endl;
        }
       
        
    }
}