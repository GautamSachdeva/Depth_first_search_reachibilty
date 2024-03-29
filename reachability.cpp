#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void depth(int current,int finish,vector<vector<int> > &adj,vector<bool> &visited,bool &reachable){
	if(current == finish){
		reachable = true;
	}
	visited[current] = true;
	for(int i = 0; i < adj[current].size() ; i++){
		if(!visited[adj[current][i]]){
			depth(adj[current][i],finish,adj,visited,reachable);	
		}
	}
}


int reach(vector<vector<int> > &adj, int x, int y) {
  //write your code here
  vector<bool> visited(adj.size(),false);
  bool reachable = false;
  depth(x,y,adj,visited,reachable);
  if(reachable == true){
  	return 1;
  }
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
