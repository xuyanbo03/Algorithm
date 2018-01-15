//
// Created by Awebone on 2018/1/15.
//

#ifndef UNIONFIND_UNIONFIND2_H
#define UNIONFIND_UNIONFIND2_H

#include <iostream>
#include <cassert>

using namespace std;

//基于Quick Union
class UnionFind2 {
private:
    int *parent;
    int count;

public:
    UnionFind2(int count) {
        parent = new int[count];
        this->count = count;
        for (int i = 0; i < count; i++) {
            parent[i] = i;
        }
    }

    ~UnionFind2() {
        delete[] parent;
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
        parent[pRoot] = qRoot;
    }
};

#endif //UNIONFIND_UNIONFIND2_H
