#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
        int n;
    int srch;
    cin >>n;
    int num[n];
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    cin>>srch;
     int j=0;
    for(int i=0;i<n;i++)
    {
        if(num[i]==srch)
        {
            cout<<i;
            j+=1;
        }

    }
    if (j==0) cout<<-1;

    return 0;
}
