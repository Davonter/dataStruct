// 链表反转
#include <stdint.h>
#include <iostream>

typedef struct Node
{
    int32_t element;
    Node* next;
} Node;

class Slist {

public:
    Slist();
    ~Slist();

public:
    /* 插入节点 */
    void insertElement(int32_t element);
    /* 打印节点 */
    void printList();
    /* 反转链表 */
    void reverseList();

private:
    Node        *mHead;
};

Slist::Slist() {
    mHead = new Node;
    mHead->next = nullptr;
}

Slist::~Slist() {
    Node* ptr = mHead, *temp;

    while (ptr->next != nullptr) {
        temp = ptr->next;
        ptr->next = ptr->next->next;
        delete temp;
    }

    delete mHead;
    mHead = nullptr;
}

void Slist::insertElement(int32_t element) {
    Node* ptr = mHead;

    Node* newNode = new Node;
    newNode->element = element;
    newNode->next = ptr;

    mHead = newNode;
}

void Slist::printList() {

    Node* ptr = mHead;

    while(ptr->next != nullptr) {
        std::cout << ptr->element << " ";
        ptr = ptr->next;
    }

    std::cout << std::endl;
}

void Slist::reverseList() {
    Node *pre = nullptr, *cur = mHead, *next = nullptr;

    while(cur) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    mHead = pre;
}


int main() {

    Slist list;

    int32_t element;
    while(1) {
        std::cout << "Please input a number: ";
        std::cin >> element;

        if (element == -1) {
            break;
        }

        list.insertElement(element);
        list.printList();
    }

    list.reverseList();
    list.printList();

    return 0;
}