/*Simple DFS implemetation in C++
  Without the use of STL library
  By: Gkountelos Dimitrios*/
#include <iostream>
using namespace std; 
  

//the class for each node of the list
class node 
{
    public:
        int key;
        node* next;
        node () {
            key = 0;
            next = NULL;
        }
        node (int newK) {
            key = newK;
            next = NULL;
        } 
};

//the class of the linked list
class list : node
{
    public:
        node* head;
        list() {head = NULL;}
        void push_back (int nextKey);
};

void list::push_back (int nextKey) 
{
    if (head == NULL) {
        head = new class node (nextKey);
        return;
    }
    node* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new class node (nextKey);
}

//the basic class for the graph
class Graph
{ 
    private: 
        //the number of the vertices
        int vert;    
    
        // Pointer to an array containing 
        // adjacency lists 
        list* adj; 
        void DFSVisit(int v, bool* visited); 
    public:
        Graph(int V);   // Constructor 
    
        // function to add an edge to graph 
        void addEdge(int v, int w); 
        //the first call of the algorithm
        void DFS (int v);
}; 
  
Graph::Graph(int V) 
{ 
    vert = V; 
    adj = new list[V];
} 
  
void Graph::addEdge(int v, int nextKey) 
{ 
    adj[v].push_back(nextKey); 
} 

void Graph::DFS(int V) {
    bool* visited;
    visited = new bool[vert];
   
    for (int i=0; i<vert; i++) {
        visited[i] = false;
    } 
    DFSVisit(V, visited);
}

void Graph::DFSVisit(int v, bool* visited) 
{
    visited[v] = true;

    //now we should check the neighbors
    node *curr = this->adj[v].head;

    do {
        cout << curr->key << endl;
        
        if (visited[curr->key] == false) {
            DFSVisit(curr->key, visited);
        }

        curr = curr->next;
    } 
    while (curr != NULL);
}

int main() 
{ 
    Graph g(5); 
    g.addEdge(0, 3); 
    g.addEdge(0, 4); 
    g.addEdge(1, 2); 
    g.addEdge(1, 3); 
    g.addEdge(2, 1); 
    g.addEdge(3, 0);
    g.addEdge(3, 1);
    g.addEdge(3, 4);
    g.addEdge(4, 0);
    g.addEdge(4, 3); 
  
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n"; 
    g.DFS(2); 
  
    return 0; 
} 