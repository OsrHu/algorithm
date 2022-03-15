#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 1e4 + 10;

int n, k;
struct People
{
    string name;
    int height;

    bool operator<(const People& t) const
    {
        if(height != t.height) return height > t.height;
        return name < t.name;
    }
}peoples[N];



int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i ++)
    {
        string name;
        int height;
        cin >> name >> height;
        peoples[i] = {name, height};
    }

    sort(peoples, peoples + n);

    int m;
    int cnt = 0;
    for(int i = k - 1; i >= 0; i --)
    {
        if(i == k - 1) m = n - n / k * (k - 1);
        else m = n / k;

        vector<People> v(m);

        v[m / 2] = peoples[cnt];
        int j = m / 2 - 1;
        for(int t = cnt + 1; t < cnt + m; t +=2)
        {
            v[j--] = peoples[t];
        }
        j = m / 2 + 1;
        for(int t = cnt + 2; t < cnt + m; t +=2)
        {
            v[j ++] = peoples[t];
        }

        cout << v[0].name;
        for(int t = 1; t < m; t ++)
        {
            cout << " " << v[t].name ;
        }

        cout << endl;
        cnt = cnt + m;
    }

    return 0;

}