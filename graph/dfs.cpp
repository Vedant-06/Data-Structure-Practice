#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,n) for(ll i=a;i<n;i++)
#define FoR(i,a,n) for(ll i=a;i<=n;i++)
#define rFor(i,n,a) for(ll i=n-1;i>=a;i--)
#define INF LLONG_MAX
#define NINF LLONG_MIN
#define ff first
#define ss second
#define pb push_back
#define all(a) a.begin(),a.end()
#define print(a) cout<<a<<"\n";
vector<vector<ll>>adjList;
vector<bool>visited;
const ll mod=1e9+7;
void DFS(ll v){
    cout<<v<<" ";
    visited[v]=true;
    for(auto &u: adjList[v]){
        if(!visited[u]){
            DFS(u);
        }
    }
}
void solve(){
    // number of vertices
    ll n; cin>>n;
    // number of edges
    ll m; cin>>m;
    adjList.resize(n+1);
    visited.resize(n+1,false);
    For(i,0,m){
        ll a,b;
        cin>>a>>b;
        // a is connected to b 
        // a----b considering graph to undirected
        adjList[a].pb(b);
        adjList[b].pb(a);
    }
    ll root;
    cin>>root;
    DFS(root);
    print("");
} 
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    solve();
    return 0;
}