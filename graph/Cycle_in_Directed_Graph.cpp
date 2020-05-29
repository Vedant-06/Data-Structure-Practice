#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100];
bool v[100] = {0};
bool recStack[100] = {0};

int dfs(int s)
{
    if(!v[s])
    {
        v[s] = true;
        recStack[s] = true;
    
        for(int i=0;i<adj[s].size();i++)
        {
            if(!v[adj[s][i]] && dfs(adj[s][i]))
                return true;
            else if(recStack[s] == true)
                return true;
        }
    }
    
    cout << s << " ";
    recStack[s] = false;
    return false;
    
}

int main() 
{
	// your code goes here
	
	// Nos. of Nodes
	int n;
	cin >> n;
	// Nos of Edges
	int m;
	cin >> m;
	
	for(int i=0;i<m;i++)
	{
	    int a,b;
	    cin >> a >> b;
	    adj[a].push_back(b);
	    //adj[b].push_back(a);
	}
	
	for(int i=0;i<n;i++)
	{
		if(dfs(i))
		cout << "Cycle is Detected" << endl;
	}
	
	cout << '\n'<< dfs(0);
}
