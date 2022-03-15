//dfs思路错误，因为为了获得最大购买数量，只需要维护一个价格最低买就行
//另外无需暴搜的原因是沿着每次最低价格买入的话，其实是最优解
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10, INF = 0x3f3f3f3f;

int n, total;
int a[N], b[N];
// unordered_map<int, unordered_map<int,bool>> st;

struct Node
{
    int idx, cidx, price;
    Node(int _idx, int _cidx) : idx(_idx), cidx(_cidx), price(a[idx] - b[cidx]){}
    bool operator>(const Node& t) const
    {
        return price > t.price;
    }
};
priority_queue<Node, vector<Node>, greater<Node>>q;


// void dfs(int idx,int left, int num)
// {
//     if(left < a[0] - b[0]) return;

//     max_num = max(max_num, num);

//     for(int i = idx; i < n; i ++ )
//     {
//         for(int j = 0; j < n; j ++)
//         {
//             if(st[i][j]) continue;

//             st[i][j] = true;
//             dfs(i, total - (a[i] - b[j]), num + 1);
//             st[i][j] = false;
            
//             dfs(i, total - a[i], num + 1);
//         }

//         dfs(i + 1, total, num);


//     }

// }

int main()
{
    cin >> n >> total;
    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 0; i < n; i ++) cin >> b[i];
    sort(a, a + n);
    sort(b, b + n, greater<int>());

    for(int i = 0;i < n; i ++)
    {
        q.push(Node(i, 0));
    }

    // for(int i = 0; i < 1000000; i ++)
    // {
    //     for(int j = 0; j < 1000000; j ++)
    //     {
    //         int t  = a[i] - b[j];
    //         q.push(t);
    //     }
    // }
    int max_num = 0;
    while(!q.empty())
    {   
        auto t = q.top();
        // cout << t.price << endl;
        q.pop();
        if(total - t.price < 0) break;
        total -= t.price;
        max_num ++;
        if(t.cidx < n - 1) q.push(Node(t.idx, t.cidx + 1));
    }

    cout << max_num << " " << total << endl;
    
    
}