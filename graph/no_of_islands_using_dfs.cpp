//can also be solved without using visited matrix by using a as visited matrix
//rohanm9
//DA-IICT,Gandhinagar
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define NINF LLONG_MIN
#define INF LLONG_MAX
#define For(i,a,b) for(ll i=a;i<b;i++)
#define FoR(i,a,b) for(ll i=a;i<=b;i++)
#define rFor(i,a,b) for(ll i=a;i>=b;i--)
#define pb push_back
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
#define print(a) cout<<a<<"\n"
const ll mod=1e9+7;
ll n,m;
vector<vector<ll>>a;
vector<vector<bool>>visited;
// direction vector
//-->y
//|
//|
//v
//x
ll d[3]={-1,0,1};
void DFS(ll x,ll y){
    visited[x][y]=true;
    For(i,0,3){
        For(j,0,3){
            if(d[i]==0&&d[j]==0) continue;
            if((x+d[i]>=0&&x+d[i]<=n-1) && (y+d[j]>=0&&y+d[j]<=m-1)){
                if(!visited[x+d[i]][y+d[j]] && a[x+d[i]][y+d[j]]==1){
                    DFS(x+d[i],y+d[j]);
                }
            }
        }
    }
}
void solve(){
    cin>>n>>m;
    a.resize(n);
    For(i,0,n) a[i].resize(m);
    For(i,0,n){
        For(j,0,m){
            cin>>a[i][j];
        }
    }
    visited.resize(n);
    For(i,0,n) visited[i].resize(m,false);
    ll count=0;
    For(i,0,n){
        For(j,0,m){
            if(!visited[i][j]&&a[i][j]==1){
                DFS(i,j);
                count+=1;
            }    
        }
    }
    print(count);   
}
int main(){
    ios::sync_with_stdio(false),cin.tie(NULL);
    solve();
}
// to stop c++ using scientific notation
// cout.setf(ios::fixed);
// cout<<setprecision(0)<<value;