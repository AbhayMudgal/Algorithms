#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef map<ll, vl> mvp;

#define pb push_back
#define f(i, a, b) for(ll i = a; i<b; i++)

void tarjan(int curr, int parent, int time, mvp& map, vl& low, vvl& ans){
  low[curr] = time++;
  for(auto x:map[curr]){
    if(x==parent) continue;

    if(low[x]==0) tarjan(x, curr, time, map, low, ans);
    low[curr] = min(low[curr], low[x]);

    if(low[x]==time) ans.pb({curr, x});
  }
}

vvl critical_connections(int n, vvl& connections){
  mvp map;
  for (auto x: connections){
    map[x[0]].pb(x[1]);
    map[x[1]].pb(x[0]);
  }

  vvl ans;
  vl low(n, 0);
  tarjan(0, -1, 1, map, low, ans);
  return ans;
}

int main(){
  int n; //The number of vertices in the graph
  cin>>n;
  int m; //The number of edges
  cin>>m;

  vvl connections; //Edges
  f(i, 0, m){
    ll a, b;
    cin>>a>>b;
    connections.pb({a, b});
  }

  vvl crit_connect = critical_connections(n, connections);
  //print to get the critical critical_connections
  //use size to get number of critical connections

  return 0;
}
