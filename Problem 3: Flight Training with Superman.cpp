#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
         int n,mxm;
    cin >>n;
    int num[n];
    for(int i=0;i<n;i++)
    {
        cin>>num[i];

    }
    mxm=num[0];

        for(int j=1;j<n;j++)
        {
            if(num[j]>mxm){mxm=num[j];}
        }
    cout<<mxm;
    return 0;
}
