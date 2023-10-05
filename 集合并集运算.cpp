#include <iostream>
using namespace std;

// 链表节点结构
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 插入排序函数，将新元素按升序插入到已排序的链表中
ListNode* insert(ListNode* head, int val) {
    ListNode dummy(0); // 创建一个虚拟头节点
    dummy.next = head;
    ListNode* current = &dummy;

    // 寻找插入位置
    while (current->next && current->next->val < val) {
        current = current->next;
    }

    // 插入新节点
    ListNode* newNode = new ListNode(val);
    newNode->next = current->next;
    current->next = newNode;

    return dummy.next; // 返回排序后的链表头节点
}

// 合并两个链表，并确保重复元素只保留一个
ListNode* mergeLists(ListNode* listA, ListNode* listB) {
    if (!listA) {
        return listB;
    }
    if (!listB) {
        return listA;
    }

    ListNode* currentB = listB;

    while (currentB) {
        int val = currentB->val;

        // 在链表A中查找是否存在相同的元素
        ListNode* currentA = listA;
        bool exists = false;
        while (currentA) {
            if (currentA->val == val) {
                exists = true;
                break;
            }
            currentA = currentA->next;
        }

        // 如果链表A中不存在相同元素，则将val插入链表A
        if (!exists) {
            listA = insert(listA, val);
        }

        currentB = currentB->next;
    }

    return listA;
}

// 打印链表
void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->val;
        if (current->next) {
            cout << " ";
        }
        current = current->next;
    }
    cout << endl;
}

int main() {
	freopen("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;

    ListNode* listA = NULL;
    ListNode* listB = NULL;

    // 读取集合A的元素并插入链表A
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        listA = insert(listA, val);
    }

    // 读取集合B的元素并插入链表B
    for (int i = 0; i < m; i++) {
        int val;
        cin >> val;
        listB = insert(listB, val);
    }

    // 合并两个链表
    listA = mergeLists(listA, listB);

    // 输出合并后的链表
    printList(listA);

    // 释放链表内存
    while (listA) {
        ListNode* temp = listA;
        listA = listA->next;
        delete temp;
    }

    return 0;
}

