// 并查集大作业.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<time.h>
#include<cstdlib>
#define NUMTRY 10000
#define DENSE  20
//#include "stdafx.h"
#include "conio.h"
#include<graphics.h>
using namespace std;
template<class T>
class ParTreeNode
{
private:
    T value; 
    ParTreeNode <T>* parent;
    int nCount;// 以此结点为根的子树的总结点个数
public:
    ParTreeNode() {
        parent = NULL;
        nCount = 1;
    }
    
    virtual ~ParTreeNode() {};
    
    T getValue() { return value; }
    
    void setValue(const T& val) {value = val;}
    
    ParTreeNode<T>* getParent() {return parent;}
    
    void setParent(ParTreeNode<T>* par) { parent = par; }
    
    int getCount() { return nCount; }
    
    void setCount(const int count) { nCount = count; }
};

template<class T>
class ParTree
{public:
    ParTreeNode<T>* array;
    int Size; 
    int *label;
    ParTreeNode<T>* Find(ParTreeNode<T>* node) const;
    ParTree(const int size);
    virtual ~ParTree();
    void Union(int i, int j);
    bool Different(int i, int j);
    void sortlabel(int i,int j) {
        label[i] = label[j];
    }
};


template <class T>
ParTree<T>::ParTree(const int size)
{
    Size = size;
    array = new ParTreeNode<T>[size];
    label = new int[size];
    for (int i = 0;i < size;i++) {
        label[i] = i;
    }
}
template <class T>
ParTree<T>::~ParTree()
{
    delete[]array;
}
template <class T>
ParTreeNode<T>* 
ParTree<T>::Find(ParTreeNode<T>* node) const
{
    if (node->getParent() == NULL) {
        return node;
    }
    node->setParent(Find(node->getParent()));
    return node->getParent();
}
template<class T>
bool ParTree<T>::Different(int i, int j)
{
    ParTreeNode<T>* pointeri = Find(&array[i]); 
    ParTreeNode<T>* pointerj = Find(&array[j]); 
    return pointeri != pointerj;
}
template<class T>
void ParTree<T>::Union(int i, int j)
{   ParTreeNode<T>* pointeri = Find(&array[i]);
    ParTreeNode<T>* pointerj = Find(&array[j]);
    if (pointeri != pointerj)
    {
        if (pointeri-> getCount() >= pointerj->getCount())
        {
            pointerj->setParent(pointeri);  
            pointeri->setCount(pointeri->getCount() + pointerj->getCount());
            sortlabel(j, i);
            Size=Size-1;
            
        }
        else
        {
            pointeri->setParent(pointerj);
            pointerj->setCount(pointeri->getCount() + pointerj->getCount());
            sortlabel(i, j);
            Size=Size-1;
        }
    }
}

bool isoverlap(double x1,double y1,double len1,double wid1, double x2,double y2,double len2,double wid2 ){
    if (x1 + wid1 <= x2) return 0;
    if (x2 + wid2 <= x1)return 0;
    if (y2 - len2 >= y1)return 0;
    if (y1 - len1 >= y2)return 0;
    return 1;
}
void random_gen(double* x, double* y, double* len, double* wid) {
    int i; 
    srand(time(0));

    for (i = 0;i < NUMTRY;i++) {
         if(rand()%2)
         {
             len[i] = 20;
             wid[i] = rand()%10000+1;
         }
         else { 
             wid[i] = 20;
             len[i] = rand()%10000+1;
         }
         x[i] = (rand() %10000)*DENSE+1;
         y[i] = (rand()%10000)*DENSE+1;
    }

}

void plot(double* x, double* y, double* len, double* wid,int *label,int num) {
    initgraph(1001, 1001);						/*图形方式初始化*/
    	
    int i;
    for (i = 0;i < NUMTRY;i++) {
        setcolor(HSLtoRGB((label[i])%255, 1, 0.5f));
        rectangle(x[i]/100, (y[i]-len[i])/100, (x[i]+wid[i])/100, (y[i])/100);
        
    }
    Sleep(20000);
    closegraph();								/*退出图形状态*/
  
  
}

int main()
{
    double x[NUMTRY];
    double y[NUMTRY];
    double len[NUMTRY];
    double wid[NUMTRY];
    
    ParTree<int> cond(NUMTRY);
    random_gen(x, y, len, wid);
    //printf("%d", isoverlap(0, 0, 1, 1, 1, 1, 1, 1));
   // printf("%f,%f,%f,%f,%f", x[100], y[1000], len[10000], wid[70],wid[71]);
     int i, j;
     for (i = 0;i < NUMTRY;i++) {
       for (j = i + 1;j < NUMTRY;j++) {
           if (isoverlap(x[i], y[i], len[i], wid[i], x[j], y[j], len[j], wid[j])&& cond.Different(i, j)) {
              cond.Union(i,j);
           }
        }
     }
     for (i = 0;i < NUMTRY;i++) {
         printf("%d\n", cond.label[i]);
     }
     plot(x, y, len, wid,cond.label,cond.Size);
     return cond.Size;
}

