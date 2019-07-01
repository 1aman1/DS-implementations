/* C++ Program to Implement Adjacency List */
#include <iostream>
#include <cstdlib>
using namespace std;
/* Adjacency List Node */ 
struct AdjListNode {
  int Node_ID;
  struct AdjListNode* next;

  AdjListNode():next(NULL)
  {} 
  AdjListNode(int Node):Node_ID(Node), next(NULL)
  {} 
};
/* Adjacency List */  
struct AdjList {
    struct AdjListNode *HEAD;
};
/* Class Graph */ 
class Graph {
  private:
    int* visited; 
    int Vert;
    struct AdjList* arrayOfList;
  public:
    Graph(int V) {
      this->Vert = V;
      arrayOfList = new AdjList [V];
      visited = new int[V];
    }
    /*  * Adding Edge to Graph  */ 
    void addEdge(int Src_Node, int Node_ID);

    /* Print the graph */ 
    void print();

    /* print DFS */
    void DFS(int n);
    void DFS_traversal();
};

void Graph::addEdge(int Src_Node, int Node_ID) {
  AdjListNode* newNode = new AdjListNode(Node_ID);
  newNode->next = arrayOfList[Src_Node].HEAD;
  arrayOfList[Src_Node].HEAD = newNode;
  newNode = new AdjListNode(Src_Node);
  newNode->next = arrayOfList[Node_ID].HEAD;
  arrayOfList[Node_ID].HEAD = newNode;
}

void Graph::print() {
  int v;
  for (v = 0; v < Vert; ++v) {
    AdjListNode* ptr = arrayOfList[v].HEAD;
    cout << "\n Adjacency list of vertex " << v << "\n HEAD ";
    while(ptr) {
      cout << "-> " << ptr->Node_ID;
      ptr = ptr->next;
    }
    cout << endl;
  }
}

void Graph::DFS_traversal() {
	for(int i = 0; i < Vert; ++i) {
    visited[i] = 0;
  }
  for(int i = 0; i < Vert; ++i) {
		if(!visited[i]) {
//      cout << "\ncalling in \n";
			DFS(i);
    }
  }
}

void Graph::DFS(int N) {
  visited[N] = 1;
  cout << N << " ";
  if( arrayOfList[N].HEAD->next ) {
	  AdjListNode* tmp = arrayOfList[N].HEAD->next;
    if(!visited[tmp->Node_ID]) {
//      cout << " reCurcall from node : " << tmp->Node_ID << "\n";
		  DFS(tmp->Node_ID);
    }
//	  cout << "#S_" << tmp->Node_ID << "@";
  }
  //cout << "done:\n";
}

/* Main */ 
int main() {
  Graph gh(5);
  gh.addEdge(0, 1);
  gh.addEdge(0, 4);
  gh.addEdge(1, 2);
  gh.addEdge(1, 3);
  gh.addEdge(1, 4);
  gh.addEdge(2, 3);
  gh.addEdge(3, 4);

  // print the adjacency list representation of the above graph
  gh.print();

  gh.DFS_traversal();

  return 0;
}
