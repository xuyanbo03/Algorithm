//
// Created by Awebone on 2018/1/15.
//

#ifndef UNIONFIND_UNIONFIND3_H
#define UNIONFIND_UNIONFIND3_H

#include <iostream>
#include <cassert>

using namespace std;

//基于size的优化
class UnionFind3 {
private:
    int *parent;
    int *sz;//sz[i]表示以i为根的元素的个数
    int count;

public:
    UnionFind3(int count) {
        parent = new int[count];
        sz = new int[count];
        this->count = count;
        for (int i = 0; i < count; i++) {
            parent[i] = i;
            sz[i] = 1;
        }
    }

    ~UnionFind3() {
        delete[] parent;
        delete[] sz;
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
        if (sz[pRoot] < sz[qRoot]) {
            parent[pRoot] = qRoot;
            sz[qRoot] += sz[pRoot];
        } else {
            parent[qRoot] = pRoot;
            sz[pRoot] += sz[qRoot];
        }
    }
};

#endif //UNIONFIND_UNIONFIND3_H
