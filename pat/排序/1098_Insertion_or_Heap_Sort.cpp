/*
思路：插入排序前idx数从小到大，后面一样
heapsort分不排序区和排序区，如果要做从小到大的排序顺序，需要注意的是做大根堆
细节： 从小到大 <= 要考虑到
*/
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 110;

int n;
int a[N],b[N];

void down(int u,int size)
{
    int t = u;
    if(u * 2 <= size && b[t] < b[u * 2]) t = u * 2;
    if(u * 2 + 1 <= size && b[t] < b[u * 2 + 1]) t = u * 2  + 1;
    if(t != u)
    {
        swap(b[t], b[u]);
        down(t, size);
    } 
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++) cin >> b[i];

    int p = 2;
    while(p <= n && b[p - 1] <= b[p]) p ++; // 测试点4的细节之处
    
    int k = p;
    while(p <= n && a[p] == b[p]) p ++;

    if(p == n + 1)
    {
        cout << "Insertion Sort" << endl;
        sort(b,b + k + 1);
    }
    else
    {
        cout << "Heap Sort" << endl;
        p = n;
        while(b[1] <= b[p]) p --;
        swap(b[1],b[p]);
        down(1, p-1);
    }

    cout << b[1];
    for(int i = 2; i <= n ; i ++)
    {
        cout << " " << b[i];
    }
    cout << endl;

    return 0;
}