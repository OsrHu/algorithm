#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

const int N = 110;

int n;
int leger[N];

int main()
{
    cin >> n;
    double ans = 0;
    int cnt = 0;
    for(int i = 0 ; i < n; i ++)
    {
        string s;
        cin >> s;
        int j = 0;
        for(; j < s.size(); j ++)
        {
            if(isalpha(s[j]) || (s[j] == '-' && s.size() == 1))
            {
                printf("ERROR: %s is not a legal number\n", s.c_str());
				break;
            }
        }

        if(j == s.size())
        {   
            if(s.find('.') != s.find_last_of('.') || (s.find('.') != -1 && s.size() - s.find('.') > 3))
            {
                printf("ERROR: %s is not a legal number\n", s.c_str());
            }
            else
            {   
                double num = stod(s);
                if(num >= - 1000 && num <= 1000)
                {
                    cnt ++;
                    ans += num;
                }
                else printf("ERROR: %s is not a legal number\n", s.c_str());
            }
        }
    }

    if(cnt == 0)    printf("The average of 0 numbers is Undefined");
    else if(cnt == 1) printf("The average of %d number is %.2lf", cnt, ans/cnt);
    else printf("The average of %d numbers is %.2lf", cnt, ans / cnt);

    return 0;
}