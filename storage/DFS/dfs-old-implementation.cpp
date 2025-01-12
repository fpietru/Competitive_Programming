#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void addEdge(vector<int> A[], int v1, int v2)
{
    A[v1].push_back(v2);
    A[v2].push_back(v1);
}

void printout(vector<int> A[], int V)
{
    for (int i=0; i<V; i++)
    {
        cout<<"A["<<i<<"] ";
        for (auto j : A[i])
            cout<<j<<" ";
        cout<<endl;
    }
}

void DFS2(vector<int> A[], vector<bool> &visited, int i)
{
    visited[i] = true;
    cout<<i<<" ";
    for (unsigned int x=0; x<A[i].size(); x++)
        if (visited[A[i][x]] == false)
            DFS2(A, visited, A[i][x]);

}

void DFS(vector<int> A[], int V)
{
    vector<bool> visited(V, false);
    for (int i=0; i<V; i++)
        if (!visited[i])
            DFS2(A, visited, i);
}

int main()
{
    int V,E,v1,v2;
    cin>>V>>E;
    vector<int> *A = new vector<int>[V];


    for (int i=0; i<E; i++)
    {
        cin>>v1>>v2;
        addEdge(A, v1, v2);
    }

    printout(A,V);
    DFS(A,V);

    return 0;
}
