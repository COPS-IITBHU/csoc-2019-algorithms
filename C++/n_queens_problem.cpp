#include<bits/stdc++.h>
#define all(c) c.begin(), c.end()
using namespace std;
bool scan_nxt_Queen(int);
void show_board();
int n;
vector<int> vx;
vector<int> vy;
vector<int> vxmy;
vector<int> vxpy;

int main()
{
    int i=0,x=0,y=0;
    cin>>n;
    bool ret=0;
    for(x=0;x!=n;x++){
        vx.push_back(x),vy.push_back(y),vxmy.push_back(x-y),vxpy.push_back(x+y);
        ret=scan_nxt_Queen(1);
        if(ret==0)
            vx.pop_back(),vy.pop_back(),vxmy.pop_back(),vxpy.pop_back();
        else{
            show_board();break;}
    }
}
bool scan_nxt_Queen(int y)
{
    if(y==n)
        return 1;
    else{
        int x=0,i=0;
        bool ret=0;
        for(x=0;x!=n;x++){
            if((find(vx.begin(),vx.end(),x)==vx.end())&&(find(vxmy.begin(),vxmy.end(),(x-y))==vxmy.end())&&(find(vxpy.begin(),vxpy.end(),(x+y))==vxpy.end())){
                vx.push_back(x),vy.push_back(y),vxmy.push_back(x-y),vxpy.push_back(x+y);
                ret=scan_nxt_Queen(y+1);
                if(ret==1){
                    return 1;break;}
                else{
                    vx.pop_back(),vy.pop_back(),vxmy.pop_back(),vxpy.pop_back();
                }
            }
        }
        if(ret==0)
            return 0;
    }
}
void show_board()
{
    int i=0,j=0;
    for(j=0;j!=n;j++){
        for(i=0;i!=n;i++){
            if((vx[vy[j]]==i))
                cout<<"1"<<" ";
            else
                cout<<"0 ";
        }
        cout<<"\n";
    }
}
