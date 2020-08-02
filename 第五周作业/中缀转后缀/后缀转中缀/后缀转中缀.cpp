// 后缀转中缀.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//数字与运算符对应关系： +：0，-：1，*：2，/：3，（：4，）：5，=：6 ,开始符号是7

#include <iostream>
#include <stdlib.h>
#include<stdio.h>
#include <string.h>
#include <conio.h>
using namespace std;
int determine[7][7] = { 1,1,2,2,2,1,1,
       1,1,2,2,2,1,1,
       1,1,1,1,2,1,1,
       1,1,1,1,2,1,1,
       2,2,2,2,2,3,3,
       1,1,1,1,3,1,1,
       2,2,2,2,2,3,3 };
class arrStack {
private:
    int mSize;
    int top;
    int* st;
    char* perfix;//后缀表达式
    int per;//后缀表达式末尾元素位置
    int i;//循环变量
    int b;//循环变量
    int p1=0;
   
    
public:
    arrStack() {
        mSize = 32;
        top = -1;
        st = new int[mSize];
        perfix= new char[mSize];
        per = 0;
        i = 0;
        b = 0;
        
       
    }
  
    ~arrStack() {
        delete[]st;
       
    }
    void clear() {
        top = -1;
    }
    bool push(const int item) {
        if (top == mSize - 1) {
            cout << "堆栈已满" << endl;
            return false;
        }
        else {
            st[++top] = item;
            return true;
        }
    }
    int pop() {
        if (top == -1) {
            cout << "栈为空" << endl;
            return false;
        }
        else {
            int item;
            item = st[top--];
            return item;
        }
    }
    int topread() {
        if (top == -1)return 6;
        return st[top];
    }
    bool isempty() {
        return top == -1;
    }
    bool  isfull() {
        return top == (mSize - 1);
    }
    //根据determine矩阵来判断接下来的工作的函数，第一个参数是determine矩阵的元素，第二个参数是外部运算符对应的数字
    void work(int c,int out) {
        if (c == 1) {
            
                
                int b = pop();
                switch (b) {
                case 0: perfix[per] = '+';break;
                case 1:perfix[per] = '-';break;
                case 2:perfix[per] = '*';break;
                case 3:perfix[per] = '/';break;
                case 4:perfix[per] = '(';break;
                case 5:perfix[per] = ')';break;
                }
                per++;
            }
    
        else if(c==2) {
            push(out);

        }
        else { pop(); }
    }
    //将输入的数字直接存储到后缀数组中
    void outnum(char a) {
        perfix[per] = a;
        per++;
    }
    void print() {
        cout << "当前后缀表达式为" << endl;
        for ( i=0; i < per;i++)
            cout << perfix[i] << endl;
        cout <<"当前有几个元素"<< per << endl;
        per = 0;
    }
    void workdetemine(int currentsig) {
        
        while (1) {
            p1 = topread();
            if (determine[p1][currentsig] == 1) {
                work(1, currentsig);
            }
            else if(determine[p1][currentsig]==2) {
                work(2, currentsig);
                break;
            }
            else {
                work(3, currentsig);
                break;
            }
        }
    }
   
};


int main()
{
    arrStack transfer;
//运算符优先级矩阵，1代表堆栈内优先级大，2代表输入的优先级大，3代表想等或者不会出现的情况
   
    char a=0;   //每次输入的字符
    
    int signal2;  //栈顶运算符对应的数字
    while (1) {
        cout << "请输入一个10以内的数字或者字符" << endl;
        a=getchar();
        rewind(stdin);  //防止缓冲区的无用字符的干扰
        if (a >= 48 && a <= 57) {
            transfer.outnum(a);
        }
        else {
            switch (a) {
            case '+':
                transfer.workdetemine(0);
                break;
            case '-':
                transfer.workdetemine(1);
                break;
            case '*':
                transfer.workdetemine(2);
                break;
            case '/':
                transfer.workdetemine(3);
            case '(':
                transfer.workdetemine(4);
                break;
            case ')':
                transfer.workdetemine(5);
                break;
            case '=':
                transfer.workdetemine(6);
                transfer.print();
                break;
            
            }
        }

    }
  

}

