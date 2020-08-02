// houzui.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//  本函数输入不区分运算符和数字，因此输入数字只能为0-9，运算符可输入加减乘除，输出=可得最终结果，运算过程中堆栈的值会打印出来

#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
template <class T>
class arrStack{
private:
    int mSize;
    int top;
    T* st;
public:
    arrStack(int size) {
        mSize = size;
        top = -1;
        st = new T[mSize];
    }
    arrStack() {
        top = -1;
    }
    ~arrStack() {
        delete[]st;
    }
    void clear() {
        top = -1;
    }
    bool push(const T item) {
        if (top == mSize - 1) {
            cout << "堆栈已满" << endl;
            return false;
        }
        else {
            st[++top] = item;
            return true;
        }
    }
    T pop() {
        if (top == -1) {
            cout << "栈为空" << endl;
            return false;
        }
        else {
            T item;
            item = st[top--];
            return item;
        }
    }
    bool isempty() {
        return top == -1;
    }
    bool  isfull() {
        return top == (mSize - 1);
    }
    void print() {
        int i;
        cout << "当前堆栈中元素有" << endl;
        for (i = 0;i <= top;i++)
            cout <<st[i] << endl;
    }
};

int main()
{
    arrStack <int> calculator(32);
    char input1;
    int op1, op2;
    int result;
    int middleresult;
    cout << "this is a polish calculator" << endl;
    cout << "please enter a valid command: " << endl;
    while (1) {
        cin >> input1;
        if ((input1 == '+') || (input1 == '-') || (input1 == '*') || (input1 == '/')) {
            op1 = calculator.pop();
            op2 = calculator.pop();
            switch (input1) {
            case '+':middleresult = op1 + op2;  break;
            case'-':middleresult = op1 - op2;  break;
            case'*':middleresult = op1 * op2;  break;
            case'/':middleresult = op1/op2;  break;
            }
            cout << "运算中间结果："<<middleresult<< endl;
            calculator.push(middleresult);
            calculator.print();
        }

        else if (input1 == '=') {
            result = calculator.pop();
            if (calculator.isempty()) cout << "the result is" << result << endl;
            else cout << "error" << endl;
            return 0;
        }
        else {
            calculator.push((input1-48));
            calculator.print();
        }

        

    }
    
}

