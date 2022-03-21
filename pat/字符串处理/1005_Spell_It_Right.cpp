#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;



int main()
{   
    string numbers[] = {"zero", "one", "two", "three", "four", "five",
                      "six", "seven", "eight", "nine", "ten"};

    string s;
    cin >> s;
    int sum = 0;
    for(int i = 0; i < s.size(); i ++)
    {   
        sum += (s[i] - '0');
    }


    string ans = to_string(sum);

    for(int i = 0; i < ans.size(); i ++)
    {
        cout << numbers[ans[i] - '0'] << (i == ans.size() - 1 ? "" : " ");
    }
}