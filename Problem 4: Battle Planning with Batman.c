#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ int r,c;
    cin>>r >>c;
    int JL[r][c], V[r][c];
    int js=0,v=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>JL[i][j];
        }
    }


    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>V[i][j];
        }
    }



    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(JL[i][j]>V[i][j])
                {js+=1;}
            else if(JL[i][j]<V[i][j])
            {v+=1;}
        }
    }
    if(js>v)
            {cout<<"Justice League";}
    else if(js<v)
             {cout<<"Villains";}
    else {cout<<"Tie";}  
    return 0;
}
