// 数组形式的栈
#include <stdint.h>
#include <iostream>

template <class T> class StackArray {

public:
    StackArray();
    StackArray(int32_t count);
    ~StackArray();

public:
    // 压栈
    void push(T data);
    // 出栈
    T pop();
    // 打印堆栈
    void print();

public:
    int32_t flag;       // 栈顶标签
    int32_t count;      // 栈容量
    T*      array;      // 栈指针
};

template <class T>
StackArray<T>::StackArray() {

    this->flag = 0;
    this->count = 10;
    this->array = new T[this->count];

    if (!this->array) {
        std::cout << "alloc memory success!" << std::endl;
    }
}

template <class T>
StackArray<T>::StackArray(int32_t count) {
    
    this->count = count;
    this->flag = 0;

    this->array = new T[this->count];
    if (!this->array) {
        std::cout << "alloc memory success!" << std::endl;
    }
}

template <class T> 
StackArray<T>::~StackArray() {
    
    if (this->array) {
        delete [] this->array;
    }
    this->count = 0;
    this->flag = 0;
}

template <class T>
void StackArray<T>::push(T data) {

    if (this->count == this->flag) {    // 栈已满，申请一个更大的栈

        this->count = this->count * 2;
        T* temp = new T[this->count];
        for (int32_t i = 0; i < this->count; i++) {
            temp[i] = this->array[i];
        }
        delete []this->array;
        temp[this->flag] = data;
        this->flag++;
        this->array = temp;
    } else {
        this->array[this->flag] = data;
        this->flag++;
    }
}

template <class T>
T StackArray<T>::pop() {

    this->flag--;
    T temp = this->array[this->flag];
    return temp;
}

template <class T>
void StackArray<T>::print() {

}

int main() {

    StackArray<int32_t> stack(5);

    while(1) {
        std::cout << "please input a element: ";
        int32_t element;

        std::cin >> element;
        if (element == -1) {
            break;
        }

        stack.push(element);
    }

    for (int32_t i = 0; i < stack.count; i++) {
        std::cout << stack.pop() << " ";
    }
    std::cout << std::endl;

    return 0;
}