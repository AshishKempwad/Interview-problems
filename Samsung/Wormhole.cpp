
//WORMHOLE

/*
https://www.careercup.com/question?id=5677905146281984
https://github.com/arjunsk/samsung_interview/blob/master/wormhole.cpp
https://gist.github.com/gunpreet34/b58c38b3556271059182244676ba06a1
https://hack.codingblocks.com/contests/c/782/870
https://discuss.codingblocks.com/t/test-case-of-minimum-time-traversal-problem/12944
http://ideone.com/Sbx7MA
*/

/*
There is one spaceship. X and Y co-odinate of source of spaceship and destination spaceship is given.
There are N number of warmholes; each warmhole has 5 values. First 2 values are starting co-ordinate
of warmhole and after that value no. 3 and 4 represents ending co-ordinate of warmhole and last 5th 
value is represents cost to pass through this warmhole. Now these warmholes are bi-directional. Now 
the to go from (x1,y1) to (x2,y2) is abs(x1-x2)+abs(y1-y2). The main problem here is to find minimum 
distance to reach spaceship from source to destination co-ordinate using any number of warm-hole. 
It is ok if you wont use any warmhole.
*/


#include<iostream>
using namespace std;

int no_of_wormholes;
int check[35];
int w[35][5];
int res = INT8_MAX;
int temp=0;



int min(int a,int b)
{
    return a<=b ? a:b;
}

int ans(int x)
{
    return (x >=0) ? x : (-1)*x;
}

int dist(int sx,int sy,int dx,int dy)
{
    return abs(sx-dx) + abs(sy-dy);
}

void wormhole(int sx,int sy,int dx,int dy,int value)
{
    res = min(res, dist(sx,sy,dx,dy)+value);

    for(int i=0;i<no_of_wormholes;i++)
    {
        if(check[i]==0)
        {
            check[i]=1;

            //choose lower end of wormhole
            temp = dist(sx,sy,w[i][0],w[i][1]) + w[i][4] + value;
            wormhole(w[i][2],w[i][3],dx,dy,temp);


            //choose upper end of wormhole
            temp = dist(sx,sy,w[i][2],w[i][3]) + w[i][4] + value;
            wormhole(w[i][0],w[i][1],dx,dy,temp);

            check[i]=0;
        }
    }
}



int main()
{
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        cin >> no_of_wormholes;
        int sx,sy,dx,dy;

        cin>>sx>>sy>>dx>>dy;
        for(int i=0;i<no_of_wormholes;i++)
        {
            for(int j=0;j<5;j++)
            {
                cin>>w[i][j];  //fill in wormholes
            }
        }

        wormhole(sx,sy,dx,dy,0);
        cout<<res<<endl;
    }

    return 0;
}
