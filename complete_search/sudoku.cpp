#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define For(i,a,n) for(ll i=a;i<n;i++)
#define rFor(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
#define INF LLONG_MAX
#define NINF LLONG_MIN
#define print(a) cout<<a<<"\n"
#define input(a) cin>>a
// function to get blocknum
ll blockNum(ll x,ll y){
    if(y<=2){
        return x/3;
    }
    else if(y<=5){
        return 3+x/3;
    }
    else{
        return 6+x/3;
    }
}
void solve(ll x,ll y,ll row[][9],ll col[][9],ll block[][9],vector<vector<char>> &A,bool &flag){
    if(y==9){
        flag=true;
        return;
    }
    if(x==9){
        solve(0,y+1,row,col,block,A,flag);
        return;
    }
    if(A[y][x]!='.'){
        solve(x+1,y,row,col,block,A,flag);
        return;
    }
    for(ll num=0;num<9;num++){

        if(row[y][num]||col[x][num]||block[blockNum(x,y)][num]) continue;

        row[y][num]=col[x][num]=block[blockNum(x,y)][num]=1;

        A[y][x]=(char)(num+'1');

        solve(x+1,y,row,col,block,A,flag);

        if(flag==true) return;

        A[y][x]='.';

        row[y][num]=col[x][num]=block[blockNum(x,y)][num]=0;

    }
}
int main(){
    vector<vector<char>>A;
    For(i,0,9){
        vector<char>tmp;
        For(j,0,9){
            char delta;
            input(delta);
            tmp.pb(delta);
        }
        A.pb(tmp);
    }
    ll row[9][9],col[9][9],block[9][9];
    bool flag=false;
    For(i,0,9){
        For(j,0,9){
            row[i][j]=col[i][j]=block[i][j]=0;
        }
    }
    For(i,0,9){
        For(j,0,9){
            if(A[i][j]=='.') continue;
            ll num=A[i][j]-'1';
            row[i][num]=col[j][num]=block[blockNum(j,i)][num]=1;
        }
    }
    solve(0,0,row,col,block,A,flag);
    For(i,0,9){
        For(j,0,9){
            cout<<A[i][j]<<" ";
        }
        print("");
    }
}