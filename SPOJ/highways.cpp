#include <iostream>
#include <vector>
#include <utility>
#include <set>

using namespace std;

#define INF 100000

struct edge { int to, cost; };
    
int dijkstra(const vector< vector<edge> > &g, int source, int target) {
  vector<int> mind( g.size(), INF );
  mind[source] = 0;
  set< pair<int, int>> active;
  active.insert( {0, source} );

  while (!active.empty()) {
    int cur = active.begin()->second;
    if (cur == target) return mind[cur];
    active.erase( active.begin() );
    for (edge ed : g[cur]) 
      if (mind[ed.to] > mind[cur] + ed.cost) {
        active.erase( { mind[ed.to], ed.to } );
        mind[ed.to] = mind[cur] + ed.cost;
        active.insert( { mind[ed.to], ed.to } );
      }
  }
  return INF;
}

int main()
{
  int nTests;
  cin >> nTests;
  for (int i = 0; i < nTests; i++){
    int a, b;
    int v, k;
    cin >> v >> k >> a >> b;
    a--;
    b--;
    vector< vector<edge>> g(v);
    g.reserve(v);
    for (int j = 0; j < k; j++){
      int v1, v2, weight;
      cin >> v1 >> v2 >> weight;
      v1--;
      v2--;
      edge e1 = {v2, weight};
      edge e2 = {v1, weight};
      g[v1].push_back(e1);
      g[v2].push_back(e2);
    }
    if (dijkstra(g, a, b) == INF)
      cout << "NONE" << endl;
    else
      cout << dijkstra(g, a, b) << endl;
  }
  
  return 0;
}