#include <iostream>
#include "stdio.h"
#include "assert.h"
using namespace std;

//定义全局数组w
int w[] = { 5,4,3,2,9,7 };
//定义结构Frame
struct Frame {
    int returnadd;
    int input1;
    int input2;
    bool result;
 

    Frame(int returnadd, int input1,int input2, bool result=0) {
        this->returnadd = returnadd;
        this->input1 = input1;
        this->input2 = input2;
        this->result = result;
       
    }
    Frame(){}
};
//定义堆栈MyStack
class MyStack {
    public:
#define MAXSIZE 4096
        MyStack() {
            _top = -1;
        }
        bool isEmpty() {
            return _top == -1;
        }
        bool isFull() {
            return _top == MAXSIZE - 1;
        }
        bool pop(Frame& frame) {
            if (!isEmpty()) {
                frame = stack[_top--];
                return true;
            }
            return false;
        }
        bool pop() {
            if (!isEmpty()) {
                _top--;
                return true;
            }
            return false;
        }
        bool push(const Frame& frame){
            if (!isFull()) {
                stack[++_top] = frame;
                return true;
            }
            return false;
        }
        Frame& top() {
            return stack[_top];
        }
        void clear() {
            _top = -1;
        }
private:
    int _top;
    Frame stack[MAXSIZE];
};
 
bool knap(int s, int n) {
    MyStack mystack;
    mystack.push(Frame(-1, s, n, 0));
    bool finalresult=0;
    int temp;
L0:  //迭代调用入口
    int input1 = mystack.top().input1;
    int input2 = mystack.top().input2;
    if (input1 == 0) {
        mystack.top().result = 1;
        goto L2;
    }
    if ((input2 < 1 && input1>0) || (input1 < 0)) {
        mystack.top().result = 0;
        goto L2;
    }
    mystack.push(Frame(1, input1 - w[input2 - 1], input2 - 1, 0));
    goto L0;
L1:  //规则1对应返回
     temp = mystack.top().result;
    if (temp) {
        cout << "装入第"<<mystack.top().input2+1<<"块石头"<<endl;
        mystack.pop();
        mystack.top().result = 1;
        goto L2;
    }
    
        mystack.pop();
 
        mystack.push(Frame(3, mystack.top().input1, mystack.top().input2-1, 0));
        goto L0;
 L3: //规则2对应返回
        temp = mystack.top().result;
        mystack.pop();
        mystack.top().result = temp;
        goto L2;
    
L2:  //递归出口处理
    int returnadd = mystack.top().returnadd;
    switch (returnadd) {
    case -1: {finalresult = mystack.top().result;
        mystack.pop();
        goto LEND;break;}
    case 0: {goto L0;break;}
    case 1: {goto L1;break;}
    case 2: {goto L2;break; }
    case 3: {goto L3;break;}
    }
LEND:  //函数出口
    assert(mystack.isEmpty());
    return finalresult;
}

int main()
{
   
    int a=knap(10,6);
    if (a)
        printf("能够实现");
    else printf("不能够实现");
}

