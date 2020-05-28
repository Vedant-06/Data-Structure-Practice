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
#define rall(a) a.rbegin(),a.rend()
#define print(a) cout<<a<<"\n"
const ll mod=1e9+7;
vector<vector<ll>>adjList;
vector<bool>visited;
void DFS(ll v){
    visited[v]=true;
    for(auto &u:adjList[v]){
        if(!visited[u]){
            DFS(u);
        }
    }
}
void solve(){
    ll n,m;
    cin>>n>>m;
    adjList.resize(n+1);
    visited.resize(n+1,false);
    For(i,0,m){
        ll a,b;
        cin>>a>>b;
        adjList[a].pb(b);
        adjList[b].pb(a);
    }
    DFS(1);
    FoR(i,1,n){
        if(!visited[i]){
            print("NO");
            return;
        }
    }
    print("YES");
}
int main(){
    ios::sync_with_stdio(false),cin.tie(NULL);
    solve();
}
// to stop c++ using scientific notation
// cout.setf(ios::fixed);
// cout<<setprecision(0)<<value;