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
void search(ll y,ll column[],ll diag1[],ll diag2[],ll &count,ll &n){
    if(y==n){
        count++;
        return;
    }
    For(x,0,n){
        // checking column ,the two diagonals not row because we are going row wise in this search/recursion
        if(column[x]||diag1[x+y]||diag2[x-y+n-1]) continue;
        column[x]=diag1[x+y]=diag2[x-y+n-1]=1;
        // fill the next row
        search(y+1,column,diag1,diag2,count,n);
        // for using different colummn for placing the queen
        column[x]=diag1[x+y]=diag2[x-y+n-1]=0;
    }
}
void solve(){
    //dimension of the chess board
    ll n;
    cin>>n;
    ll column[n],diag1[2*n-1],diag2[2*n-1];
    For(i,0,n) column[i]=0;
    For(i,0,2*n-1) diag1[i]=0,diag2[i]=0;
    ll count=0;
    
    search(0,column,diag1,diag2,count,n);
    print(count);
}
int main(){
    fastio;
    solve();
}