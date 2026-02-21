#include <iostream>
#include <list>
using namespace std;

class Graph {
private:
    int vertices;
    list<int>* adj;
    list<int> bfs;
    list<int> dfs;   // DFS result list

    // Helper function for DFS
    void DFSUtil(int vertex, bool visited[]) {
        visited[vertex] = true;
        dfs.push_back(vertex);

        for (int neighbour : adj[vertex]) {
            if (!visited[neighbour]) {
                DFSUtil(neighbour, visited);
            }
        }
    }

public:
    Graph(int v){
        vertices = v;
        adj = new list<int>[vertices];
    }

    void add(int s,int d){
        adj[s].push_back(d);
        adj[d].push_back(s);
    }
// BFS function
    void BFS(int start){
        bool *visited = new bool[vertices];
        for(int i = 0; i < vertices; i++){
            visited[i] = false;
        }

        list<int> queue;
        visited[start] = true;
        queue.push_back(start);

        while(!queue.empty()){
            int current = queue.front();
            queue.pop_front();
            bfs.push_back(current);

            for(int neighbour : adj[current]){
                if(!visited[neighbour]){
                    visited[neighbour] = true;
                    queue.push_back(neighbour);
                }
            }
        }
        delete[] visited;
    }

    // DFS Function
    void DFS(int start){
        bool *visited = new bool[vertices];
        for(int i = 0; i < vertices; i++){
            visited[i] = false;
        }

        DFSUtil(start, visited);
        delete[] visited;
    }

    void Display(){
        cout << "BFS order are : " << endl;
        for(int i : bfs){
            cout << i << " ";
        }
        cout << endl;
    }

    void DisplayDFS(){
        cout << "DFS order are : " << endl;
        for(int i : dfs){
            cout << i << " ";
        }
        cout << endl;
    }
};

int main(){
    Graph g(6);
    g.add(0,1);
    g.add(0,2);
    g.add(1,4);
    g.add(2,5);

    g.BFS(0);
    g.Display();

    g.DFS(0);
    g.DisplayDFS();

    return 0;
}