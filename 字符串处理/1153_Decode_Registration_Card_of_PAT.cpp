#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

const int N = 1e4 + 10, M = 110;

int n, m;

struct Card
{
    string number;
    int score;
}cards[N];

bool cmp(Card& a, Card& b)
{
    if(a.score != b.score) return a.score > b.score;
    return a.number < b.number;
}

int main()
{   

    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
    {
        string number;
        char s[20];
        int score;
        scanf("%s %d", s, &score);
        number = s;
        cards[i] = {number, score};
    }

    for(int i = 1; i <= m; i ++)
    {
        int type;
        string term;
        char s[20];
        // cin >> type >> term;
        scanf("%d %s", &type, s);
        term = s;
        vector<Card> ans;
        int sum = 0;
        int num = 0;
        
        printf("Case %d: %d %s\n", i, type, term.c_str());

        if(type == 1)
        {
            for(int j = 1; j <= n; j ++)
            {
                if(cards[j].number[0] == term[0])
                {
                    ans.push_back(cards[j]);
                }
            }
        }
        else if(type == 2)
        {
            for(int j = 1; j <= n; j ++)
            {
                string t = cards[j].number.substr(1,3);
                if(t == term)
                {
                    num ++;
                    sum += cards[j].score;
                }
            }
            if(num) printf("%d %d\n", num, sum);
        }
        else
        {   
            unordered_map<string, int> um;
            for(int j = 1; j <= n; j ++)
            {
                string t = cards[j].number.substr(4,6);
            
                if(t == term)
                {
                    um[cards[j].number.substr(1,3)] ++; 
                }
            }
            for(auto it: um) ans.push_back({it.first, it.second});
        }
        sort(ans.begin(), ans.end(), cmp);
        for(auto item: ans)
        {
            printf("%s %d\n", item.number.c_str(), item.score);
        }

        if((type == 1 || type == 3 ) && ans.size() == 0) cout << "NA\n";
        if(type == 2 && num == 0) cout << "NA\n";
    }

    return 0;
}