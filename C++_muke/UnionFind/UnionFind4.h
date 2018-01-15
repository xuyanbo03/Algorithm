//
// Created by Awebone on 2018/1/15.
//

#ifndef UNIONFIND_UNIONFIND4_H
#define UNIONFIND_UNIONFIND4_H

#include <iostream>
#include <cassert>

using namespace std;

//基于rank的优化
class UnionFind4 {
private:
    int *parent;
    int *rank;//rank[i]表示以i为根的集合所表示的树的层数
    int count;

public:
    UnionFind4(int count) {
        parent = new int[count];
        rank = new int[count];
        this->count = count;
        for (int i = 0; i < count; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    ~UnionFind4() {
        delete[] parent;
        delete[] rank;
    }

    //查
    int find(int p) {
        assert(p >= 0 && p < count);
        while (p != parent[p]) {
            p = parent[p];
        }
        return p;
    }

    //连接问题：是否连接
    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }

    //并,找到根节点,进行连接
    void unionElements(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot == qRoot) {
            return;
        }
        if (rank[pRoot] < rank[qRoot]) {
            parent[pRoot] = qRoot;
        } else if (rank[pRoot] > rank[qRoot]) {
            parent[qRoot] = pRoot;
        } else {
            //rank[pRoot] == rank[qRoot]
            parent[pRoot] = qRoot;
            rank[qRoot] += 1;
        }
    }
};

#endif //UNIONFIND_UNIONFIND4_H
