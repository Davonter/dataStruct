/* 
 * LRU算法
 */
#include <stdint.h>
#include <iostream>

/* 定义节点 */
typedef struct Node
{
    int32_t data;
    Node *next;
} Node;

class SList {

public:
    SList();
    SList(int32_t maxLen);
    ~SList();
    
public:
    // 判断链表是否为空
    bool isEmpty();

    // 判断链表是否已满
    bool isFull();
    
    // 查询元素是否存在
    bool findElement(int32_t element);

    // 删除一个节点
    void deleteElement(int32_t element);

    // 删除尾节点
    void deleteElementEnd();
    
    // 在头部插入元素
    void insertElementHead(int32_t element);
    
    // 打印链表
    void printAllList();
    
private:
    int32_t         mMaxLen;        // 链表最大长度
    int32_t         mLength;        // 链表当前长度

    Node*           mHead;          // 链表头
};

SList::SList() {
    
    mHead = new Node;
    mHead->next = nullptr;

    mMaxLen = 10;
    mLength = 0;
}

SList::SList(int32_t maxLen) {

    mHead = new Node;
    mHead->next = nullptr;

    mMaxLen = maxLen;
    mLength = 0;
}

SList::~SList() {
    Node *ptr, *tmp;

    ptr = mHead;

    while(ptr->next != nullptr) {
        tmp = ptr->next;
        ptr->next = ptr->next->next;
        delete tmp;
    }
    
    delete mHead;

    mHead = nullptr;
    mLength = 0;
}

bool SList::isEmpty() {
    return mLength == 0;
}

bool SList::isFull() {
    return mLength == mMaxLen;
}

bool SList::findElement(int32_t element) {
    
    Node *ptr = mHead;

    while(ptr->next != nullptr) {
        if (ptr->next->data == element) {
            return true;
        }
        ptr = ptr->next;
    }
    
    return false;
}

void SList::deleteElement(int32_t element) {
    
    Node* ptr = mHead, *tmp;
    
    while(ptr->next != nullptr) {
        if (ptr->next->data == element) {
            tmp = ptr->next;
            ptr->next = tmp->next;
            
            delete tmp;

            mLength--;
            return;
        }
        ptr = ptr->next;
    }
}

void SList::deleteElementEnd() {
    
    Node* ptr = mHead, *tmp;

    while(ptr->next != nullptr && ptr->next->next != nullptr) {
        ptr = ptr->next;
    }
    
    tmp = ptr->next;
    ptr->next = tmp->next;
    delete ptr;

    mLength--;
}

void SList::insertElementHead(int32_t element) {
    
    Node *ptr = mHead;

    Node *newPtr = new Node;
    newPtr->data = element;
    newPtr->next = ptr;

    mHead = newPtr;
    
    mLength++;
}

void SList::printAllList() {

    Node *ptr = mHead;

    while(ptr->next != nullptr) {
        std::cout << ptr->next->data << "  " << std::endl;
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

int main() {
    
    SList list(10);
    int32_t num = 0;

    while(1) {
        std::cout << "please enter a number" << std::endl;
        std::cin >> num;
        if (-1 == num) {
            break;
        }
        
        if (list.findElement(num)) {
            list.deleteElement(num);
        }
        
        if (list.isFull()) {
            list.deleteElementEnd();
        }
        list.insertElementHead(num);

        list.printAllList();
    }

    return 0;
}


























