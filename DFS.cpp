#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

unordered_set<int>visited;

void addEdge(vector<vector<int>>&adjList,int src,int dest)
{
	adjList[src-1].push_back(dest-1);
}

void DFS(vector<vector<int>>&List1,int vertices,int cur)
{
	for(auto i:List1[cur]){
		if(visited.find(i)!=visited.end())
			continue;
		cout<<i+1<<"\t";
		visited.insert(i);
		DFS(List1,vertices,i);
	}
}

int main()
{
	int numvertices,numedges;
	cout<<"Enter the number of vertices: ";
	cin>>numvertices;
	cout<<"Enter the number of edges: ";
	cin>>numedges;
	vector<vector<int>>adjList(numvertices);
	for(int i=0;i<numedges;++i){
		int src,dst;
		cout<<"Enter source: ";
		cin>>src;
		cout<<"Enter destination: ";
		cin>>dst;
		addEdge(adjList,src,dst);
	}
	int startVertex;
	cout<<"Enter start vertex for DFS: ";
	cin>>startVertex;
	visited.insert(startVertex-1);
	cout<<"DFS of graph: "<<startVertex<<"\t";
	DFS(adjList,numvertices,startVertex-1);
	cout<<endl;
	return 0;
}