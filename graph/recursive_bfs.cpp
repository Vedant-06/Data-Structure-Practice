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
vector<ll>visited;
void BFS(queue<ll>&q){
    if(q.empty())
        return;
    ll v=q.front();
    q.pop();
    cout<<v<<" ";
    for(auto &u:adjList[v]){
        if(!visited[u]){
            visited[u]=true;
            q.push(u);
        }
    }
    BFS(q);
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
    queue<ll>q;
    ll root;
    cin>>root;
    q.push(root);
    visited[root]=true;
    BFS(q);
}
int main(){
    ios::sync_with_stdio(false),cin.tie(NULL);
    solve();
}
// to stop c++ using scientific notation
// cout.setf(ios::fixed);
// cout<<setprecision(0)<<value;