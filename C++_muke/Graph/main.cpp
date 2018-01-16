#include <iostream>
#include <string>
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "ReadGraph.h"
#include "Component.h"

using namespace std;

int main() {
//    int N = 20;
//    int M = 100;
//    srand(time(NULL));
//
//    //SparseGraph
//    SparseGraph g1(N, false);
//    for (int i = 0; i < M; i++) {
//        int a = rand() % N;
//        int b = rand() % N;
//        g1.addEdge(a, b);
//    }
//    //O(E)
//    for (int v = 0; v < N; v++) {
//        cout << v << ":";
//        SparseGraph::adjIterator adj(g1, v);
//        for (int w = adj.begin(); !adj.end(); w = adj.next()) {
//            cout << w << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//
//    //DenseGraph
//    DenseGraph g2(N, false);
//    for (int i = 0; i < M; i++) {
//        int a = rand() % N;
//        int b = rand() % N;
//        g2.addEdge(a, b);
//    }
//    //O(V^2)
//    for (int v = 0; v < N; v++) {
//        cout << v << ":";
//        DenseGraph::adjIterator adj(g2, v);
//        for (int w = adj.begin(); !adj.end(); w = adj.next()) {
//            cout << w << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;

//    string filename = "testG1.txt";
//    SparseGraph g1(13, false);
//    ReadGraph<SparseGraph> readGraph1(g1, filename);
//    g1.show();
//    cout << endl;
//    DenseGraph g2(13, false);
//    ReadGraph<DenseGraph> readGraph2(g2, filename);
//    g2.show();

//    string filename1 = "testG1.txt";
//    SparseGraph g1=SparseGraph(13, false);
//    ReadGraph<SparseGraph> readGraph1(g1, filename1);
//    Component<SparseGraph> component1(g1);
//    cout<<component1.count()<<endl;
//    cout << endl;
//    string filename2 = "testG2.txt";
//    DenseGraph g2=DenseGraph(13, false);
//    ReadGraph<DenseGraph> readGraph2(g2, filename2);
//    Component<DenseGraph> component2(g2);
//    cout<<component2.count()<<endl;

    return 0;
}