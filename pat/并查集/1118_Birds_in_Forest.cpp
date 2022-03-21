/*
处理过的不能再重复处理，pa!=pb
st的语句顺序要放对
*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 10010;

int n;
int p[N], cnt[N];
bool st[N];

int find(int x)
{
    if(p[x] != x)  p[x] = find(p[x]);
    return p[x];
}

int main()
{   
    for(int i = 1; i < N; i ++) p[i] = i, cnt[i] = 1;
    cin >> n;
    while(n --)
    {
        int k;
        cin >> k;
        vector<int>birds;
        while(k --)
        {
            int bird;
            cin >> bird;
            birds.push_back(bird);
            st[bird] = true;
        }

        for(int i = 1; i < birds.size(); i ++)
        {   
            int a = birds[0] , b = birds[i];
//             st[a] = st[b] = true;
            int pa = find(a), pb = find(b);
            if(pa!=pb)
            {
                cnt[pb] += cnt[pa];
                p[pa] = pb; 
            }
            // cout << pa << " " << pb << " cnt: " << cnt[pb] << endl;
        }
    }

    
    vector<int>root;
    for(int i = 1; i < N; i ++) if(st[i] == true &&  p[i] == i) root.push_back(i);

    int number = 0;
    for(int i = 0; i < root.size(); i ++)
    {   
        // cout << root[i] << " ";
        number += cnt[root[i]];
    }
    cout << root.size() << " " <<  number << endl;


    int q;
    cin >> q;
    while(q --)
    {
        int a, b;
        cin >> a >> b;
        if(find(a) == find(b)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;


}