#include <iostream>
using namespace std;

// ����ڵ�ṹ
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// ����������������Ԫ�ذ�������뵽�������������
ListNode* insert(ListNode* head, int val) {
    ListNode dummy(0); // ����һ������ͷ�ڵ�
    dummy.next = head;
    ListNode* current = &dummy;

    // Ѱ�Ҳ���λ��
    while (current->next && current->next->val < val) {
        current = current->next;
    }

    // �����½ڵ�
    ListNode* newNode = new ListNode(val);
    newNode->next = current->next;
    current->next = newNode;

    return dummy.next; // ��������������ͷ�ڵ�
}

// �ϲ�����������ȷ���ظ�Ԫ��ֻ����һ��
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

        // ������A�в����Ƿ������ͬ��Ԫ��
        ListNode* currentA = listA;
        bool exists = false;
        while (currentA) {
            if (currentA->val == val) {
                exists = true;
                break;
            }
            currentA = currentA->next;
        }

        // �������A�в�������ͬԪ�أ���val��������A
        if (!exists) {
            listA = insert(listA, val);
        }

        currentB = currentB->next;
    }

    return listA;
}

// ��ӡ����
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

    // ��ȡ����A��Ԫ�ز���������A
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        listA = insert(listA, val);
    }

    // ��ȡ����B��Ԫ�ز���������B
    for (int i = 0; i < m; i++) {
        int val;
        cin >> val;
        listB = insert(listB, val);
    }

    // �ϲ���������
    listA = mergeLists(listA, listB);

    // ����ϲ��������
    printList(listA);

    // �ͷ������ڴ�
    while (listA) {
        ListNode* temp = listA;
        listA = listA->next;
        delete temp;
    }

    return 0;
}

