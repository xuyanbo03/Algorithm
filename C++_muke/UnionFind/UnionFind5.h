//
// Created by Awebone on 2018/1/15.
//

#ifndef UNIONFIND_UNIONFIND5_H
#define UNIONFIND_UNIONFIND5_H

#include <iostream>
#include <cassert>

using namespace std;

//路径压缩的优化
class UnionFind5 {
private:
    int *parent;
    int *rank;//rank[i]表示以i为根的集合所表示的树的层数
    int count;

public:
    UnionFind5(int count) {
        parent = new int[count];
        rank = new int[count];
        this->count = count;
        for (int i = 0; i < count; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    ~UnionFind5() {
        delete[] parent;
        delete[] rank;
    }

    //查
    int find(int p) {
        assert(p >= 0 && p < count);
        //路径压缩1
//        while (p != parent[p]) {
//            parent[p] = parent[parent[p]];
//            p = parent[p];
//        }
//        return p;
        //路径压缩2,rank=1
        if (p != parent[p]) {
            parent[p] = find(parent[p]);
        }
        return parent[p];
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

#endif //UNIONFIND_UNIONFIND5_H
