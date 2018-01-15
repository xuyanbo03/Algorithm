//
// Created by Awebone on 2018/1/15.
//

#ifndef UNIONFIND_UNIONFIND_H
#define UNIONFIND_UNIONFIND_H

#include <iostream>
#include <cassert>

using namespace std;

//基于Quick Find
class UnionFind1 {
private:
    int *id;
    int count;

public:
    //所有元素一开始独立
    UnionFind1(int n) {
        count = n;
        id = new int[n];
        for (int i = 0; i < n; i++) {
            id[i] = i;
        }
    }

    ~UnionFind1() {
        delete[] id;
    }

    //查
    int find(int p) {
        assert(p >= 0 && p < count);
        return id[p];
    }

    //连接问题：是否连接
    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }

    //并,遍历全部节点更新id
    void unionElements(int p, int q) {
        int pId = find(p);
        int qId = find(q);
        if (pId == qId) {
            return;
        }
        for (int i = 0; i < count; i++) {
            if (id[i] == pId) {
                id[i] = qId;
            }
        }
    }
};


#endif //UNIONFIND_UNIONFIND_H
