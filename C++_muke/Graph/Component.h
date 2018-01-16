//
// Created by Awebone on 2018/1/17.
//

#ifndef GRAPH_COMPONENT_H
#define GRAPH_COMPONENT_H

#include <iostream>
#include <cassert>

using namespace std;

//深度优先遍历算法
//并且计算连通分量
//求解连接问题
template<typename Graph>
class Component {
private:
    Graph &G;
    bool *visited;
    int ccount;//记录连通分量
    int *id;//计算连通分量,有几个图

    void dfs(int v) {
        visited[v] = true;
        id[v] = ccount;
        typename Graph::adjIterator adj(G, v);
        for (int i = adj.begin(); !adj.end(); i = adj.next()) {
            if (!visited[i]) {
                dfs(i);
            }
        }
    }

public:
    Component(Graph &graph) : G(graph) {
        //初始化
        visited = new bool[G.V()];
        id = new int[G.V()];
        ccount = 0;
        for (int i = 0; i < G.V(); i++) {
            visited[i] = false;
            id[i] = -1;
        }

        //深度优先遍历算法
        for (int i = 0; i < G.V(); i++) {
            if (!visited[i]) {
                dfs(i);
                ccount++;
            }
        }
    }

    ~Component() {
        delete[] visited;
        delete[] id;
    }

    int count() {
        return ccount;
    }

    bool isConnected(int v, int w) {
        assert(v >= 0 && v < G.V());
        assert(w >= 0 && w < G.V());
        return id[v] == id[w];
    }
};

#endif //GRAPH_COMPONENT_H
