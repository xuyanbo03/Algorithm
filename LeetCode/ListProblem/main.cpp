#include <iostream>
#include <cassert>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *createLinkedList(int arr[], int n) {
    if (n == 0) {
        return NULL;
    }
    ListNode *head = new ListNode(arr[0]);
    ListNode *curhead = head;
    for (int i = 1; i < n; i++) {
        curhead->next = new ListNode(arr[i]);
        curhead = curhead->next;
    }
    return head;
}

void printLinkedList(ListNode *head) {
    ListNode *curNode = head;
    while (curNode != NULL) {
        cout << curNode->val << "->";
        curNode = curNode->next;
    }
    cout << "NULL" << endl;
    return;
}

void deleteLinkedList(ListNode *head) {
    ListNode *curNode = head;
    while (curNode != NULL) {
        ListNode *delNode = curNode;
        curNode = curNode->next;
        delete delNode;
    }
    return;
}

class Solution {
    //206. Reverse Linked List
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *pre = NULL;
        ListNode *cur = head;
        while (cur != NULL) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }


    //203. Remove Linked List Elements
public:
    ListNode *removeElements(ListNode *head, int val) {
//        while (head != NULL && head->val == val) {
//            ListNode *delNode = head;
//            head = delNode->next;
//            delete delNode;
//        }
//        if (head == NULL) {
//            return NULL;
//        }

        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *cur = dummyHead;
        while (cur->next != NULL) {
            if (cur->next->val == val) {
                //删除
                ListNode *delNode = cur->next;
                cur->next = delNode->next;
                delete delNode;
            } else {
                cur = cur->next;
            }
        }
        ListNode *retNode = dummyHead->next;
        delete dummyHead;
        return retNode;
    }


    //24. Swap Nodes in Pairs
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode *p = dummyHead;
        while (p->next && p->next->next) {
            ListNode *node1 = p->next;
            ListNode *node2 = node1->next;
            ListNode *next = node2->next;
            node2->next = node1;
            node1->next = next;
            p->next = node2;
            p = node1;
        }

        ListNode *retNode = dummyHead->next;
        delete dummyHead;
        return retNode;
    }


    //237. Delete Node in a Linked List
public:
    void deleteNode(ListNode *node) {
        if (node == NULL) {
            return;
        }
        if (node->next == NULL) {
            delete node;
            node = NULL;
            return;
        }

        node->val = node->next->val;
        ListNode *delNode = node->next;
        node->next = delNode->next;
        delete delNode;
        return;
    }


    //19. Remove Nth Node From End of List
    //解法1：先遍历一遍计算链表长度，再遍历一遍删除倒数第n个节点
    //解法2：只遍历一遍，使用双索引，滑动窗口
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        assert(n >= 0);
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode *p = dummyHead;
        ListNode *q = dummyHead;
        for (int i = 0; i < n + 1; i++) {
            assert(q);
            q = q->next;
        }
        while (q != NULL) {
            p = p->next;
            q = q->next;
        }

        ListNode *delNode = p->next;
        p->next = delNode->next;
        delete delNode;
        ListNode *retNode = dummyHead->next;
        delete dummyHead;
        return retNode;
    }
};

int main() {
//    int arr[] = {1, 2, 3, 4, 5};
//    int n = sizeof(arr) / sizeof(int);
//    ListNode *head = createLinkedList(arr, n);
//    printLinkedList(head);
//    ListNode *head2 = Solution().reverseList(head);
//    printLinkedList(head2);
//    deleteLinkedList(head2);

    return 0;
}


/*
 * 链表问题
 * 1.基础
 * 206
 * 92
 * 83
 * 86
 * 328
 * 2
 * 445
 *
 * 2.设立链表的虚拟头结点
 * 203
 * 82
 * 21
 *
 * 24
 * 25
 * 147
 * 148
 *
 * 237
 *
 * 3.双指针（双索引）
 * 19
 * 61
 * 143
 * 234
 * */