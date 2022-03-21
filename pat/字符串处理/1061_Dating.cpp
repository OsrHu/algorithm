#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    
    int k = 0;
    while(true)
    {
        if(s1[k] == s2[k] && s1[k] >= 'A' && s2[k] <= 'G')
        {
            break;
        }
        k ++;
    }

    string weekdays[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    cout << weekdays[s1[k] - 'A'] << " ";
    k ++;
    while(true)
    {
        if(s1[k] == s2[k] &&( (s1[k] >= '0' && s1[k] <= '9') || (s1[k] >= 'A' && s1[k] <= 'N')))
        {
            break;
        }
        k ++;
    }
    printf("%02d:", s1[k] <= '9' ? s1[k] - '0' : s1[k] - 'A' + 10);

    k = 0;
    while(true)
    {   
        if(s3[k] == s4[k] &&( (s3[k] >= 'a' && s3[k] <= 'z') || (s3[k] >= 'A' && s3[k] <= 'Z')))
        {   
            printf("%02d", k);
            break;
        }
        k++;
    }

    return 0;


}