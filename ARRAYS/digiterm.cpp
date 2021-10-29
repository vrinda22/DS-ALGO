
#include <bits/stdc++.h>
#include<cmath>
#include<string.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, d, temp , c=0 ,rem=0 , ans=0;
        cin >> n >> d;
        temp = n;
        while(n>0)
        {
            rem = n%10;
            n/=10;
            c++;
            if(rem==d)
            {
                n = n*pow(10,c) + (rem+1)*pow(10,c-1);
                ans=n-temp;
                c=0;
            }
        }
        cout<<ans<<endl;
        // temp = n;
        // string str;
        // // cout << str;
        // for (int i = str.length() - 1; i >= 0; i--)
        // {
        //     // if (i == str.length() - 1)
        //     // {
        //     //     if (str[i] == d)
        //     //         temp += (10 - (str[i]));
        //     // }
        //     // else
        //     {
        //         if (str[i] == d)
        //             temp += ((10 - str[i+1]) * pow(10, str.length()-i-1));
        //     }
        // }
        // cout << temp - n << endl;
    }
    return 0;
}
