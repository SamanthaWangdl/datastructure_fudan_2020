// 舞伴问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
template<class T>
class Queue {
private:
    int mSize;//存放队列的数组大小
    int front;
    int rear;
    T* qu;
public:
    Queue(int size) {
        mSize = size + 1;
        qu = new T[mSize];
        front = rear = 0;

    }
    ~Queue() {
        delete[]qu;
    }

    bool enQueue(const T item) {
        if (isFull())
        {
            cout << "队列已满" << endl;
            return false;
        }
        qu[rear] = item;
        rear = (rear + 1) % mSize;
        return true;
    }
    bool deQueue(T& item)
    {
        if (isEmpty()) {
            cout << "队列为空" << endl;
            return false;
        }
        item = qu[front];
        front = (front + 1) % mSize;
        return true;
    }
    bool isEmpty() {
        return rear == front;
    }
    bool isFull() {
        return (rear + 1) % mSize == front;
    }
};

int main() {
    Queue <int> girl(10);
    Queue <int> boy(15);
    int i;
    int temp1=0, temp2=0;
    for (i = 0;i < 10;i++) {       //把每个女孩编上号
        girl.enQueue(i);
    }
    for (i = 0;i < 15;i++) {       //把每个男孩编上号
        boy.enQueue(i);
    }
    for (i = 0;i < 100;i++) {       //进行100次仿真
        girl.deQueue(temp1);
        boy.deQueue(temp2);
        cout << "当前配对的是女生第" << temp1 << "位和男生第" << temp2 << "位" << endl;
        girl.enQueue(temp1);
        boy.enQueue(temp2);
    }
    return 0;
}



