// disjkstra.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<time.h>
#include<cstdlib>
#include<vector>
#include <algorithm>
#include <functional>
#include <cstdio>
using namespace std;

template <class T>
class MinHeap {
    // 最小堆类定义
private:
    T* heapArray;
    // 存放堆数据的数组
    int CurrentSize;
    // 当前堆中元素数目
    int MaxSize; // 堆所能容纳的最大元素数目
    void swap(int pos_x, int pos_y) {T tmp = heapArray[pos_x];heapArray[pos_x] = heapArray[pos_y];heapArray[pos_y] = tmp; }; // 交换位置x和y的元素
    void BuildHeap(); // 建堆
public:
    MinHeap(const int n); // 构造函数，n表示 堆的最大元素数目
    virtual ~MinHeap() { delete[]heapArray; }; // 析构函数
    bool isEmpty(); // 如果堆空，则返回真
    bool isLeaf(int pos) const; // 如果是叶结点，返回TRUE
    int leftchild(int pos) const; // 返回左孩子位置
    int rightchild(int pos) const; // 返回右孩子位置
    int parent(int pos) const; // 返回父结点位置
    bool Remove(int pos, T& node); // 删除给定下标的元素
    bool Insert(const T& newNode); // 向堆中插入新元素newNode
    T& RemoveMin(); // 从堆顶删除最小值
    void SiftUp(int position); // 从position向上开始调整，使序列成为堆
    void SiftDown(int left); // 向下筛选，参数left表示开始处理的数组下标
};
template<class T>
MinHeap<T>::MinHeap(const int n) {
    if (n <= 0)
        return;
    CurrentSize = 0;
    MaxSize = n; // 初始化堆容量为n
    heapArray = new T[MaxSize]; // 创建堆空间
    // 此处进行堆元素的赋值工作
    BuildHeap();
}
template<class T>
bool MinHeap<T>::isLeaf(int pos) const {
    return (pos >= CurrentSize / 2) && (pos < CurrentSize);
}
template<class T>
void MinHeap<T>::BuildHeap() {
    for (int i = CurrentSize / 2 - 1; i >= 0; i--) // 反复调用筛选函数
        SiftDown(i);
}
template<class T>
int MinHeap<T>::leftchild(int pos) const {
    return 2 * pos + 1; // 返回左孩子位置
}
template<class T>
int MinHeap<T>::rightchild(int pos) const {
    return 2 * pos + 2; // 返回右孩子位置
}
template<class T>
int MinHeap<T>::parent(int pos) const {
    return (pos - 1) / 2; // 返回父结点位置
}
template <class T>
bool MinHeap<T>::Insert(const T& newNode) { // 向堆中插入新元素newNode
    if (CurrentSize == MaxSize) // 堆空间已经满
        return 0;
    heapArray[CurrentSize] = newNode;
    SiftUp(CurrentSize); // 向上调整
    CurrentSize++;
    return 1;
}
template<class T>
T& MinHeap<T>::RemoveMin() { // 从堆顶删除最小值
    if (CurrentSize == 0) {
        cout << "Can't Delete"; // 调用RemoveMin之前，需要判断堆非空
        exit(1);
    }
    else {
        swap(0, --CurrentSize); // 交换堆顶和最后一个元素
        if (CurrentSize > 1)
            SiftDown(0); // 从堆顶开始筛选
        return heapArray[CurrentSize];
    }
}
template<class T>
bool MinHeap<T>::Remove(int pos, T& node) { // 删除给定下标的元素
    if ((pos < 0) || (pos >= CurrentSize))
        return false;
    node = heapArray[pos];
    heapArray[pos] = heapArray[--CurrentSize]; // 用最后的元素值替代删除位置的元素
    if (heapArray[parent(pos)] > heapArray[pos])
        SiftUp(pos); // 当前元素小于父结点，需要上升调整
    else SiftDown(pos); // 当前元素大于父结点，向下筛
    return true;
}
template<class T>
void MinHeap<T>::SiftUp(int position) {
    // 从position向上开始调整
    int temppos = position;
    T temp = heapArray[temppos];
    while ((temppos > 0) && (heapArray[parent(temppos)].val > temp.val)) {
        heapArray[temppos] = heapArray[parent(temppos)];
        temppos = parent(temppos);
    }
    heapArray[temppos] = temp;
}
template <class T>
void MinHeap<T>::SiftDown(int left) {
    int i = left; // 标识父结点
    int j = leftchild(i); // 标识关键值较小的子结点
    T temp = heapArray[i]; // 保存父结点
    while (j < CurrentSize) { // 过筛
        if ((j < CurrentSize - 1) && (heapArray[j].val > heapArray[j + 1].val))
            //若有右子节点，且小于左子节点
            j++; // j指向右子结点
        if (temp.val > heapArray[j].val) { //若父节点大于子节点的值则交换位置
            heapArray[i] = heapArray[j];
            i = j;
            j = leftchild(j);
        }
        else break; //堆序满足，跳出
    }
    heapArray[i] = temp;
}

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

    void setValue(const T& val) { value = val; }

    ParTreeNode<T>* getParent() { return parent; }

    void setParent(ParTreeNode<T>* par) { parent = par; }

    int getCount() { return nCount; }

    void setCount(const int count) { nCount = count; }
};

template<class T>
class ParTree
{
public:
    ParTreeNode<T>* array;
    int Size;
    int* label;
    ParTreeNode<T>* Find(ParTreeNode<T>* node) const;
    ParTree(const int size);
    virtual ~ParTree();
    void Union(int i, int j);
    bool Different(int i, int j);
    void sortlabel(int i, int j) {
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
{
    ParTreeNode<T>* pointeri = Find(&array[i]);
    ParTreeNode<T>* pointerj = Find(&array[j]);
    if (pointeri != pointerj)
    {
        if (pointeri->getCount() >= pointerj->getCount())
        {
            pointerj->setParent(pointeri);
            pointeri->setCount(pointeri->getCount() + pointerj->getCount());
            sortlabel(j, i);
            Size = Size - 1;

        }
        else
        {
            pointeri->setParent(pointerj);
            pointerj->setCount(pointeri->getCount() + pointerj->getCount());
            sortlabel(i, j);
            Size = Size - 1;
        }
    }
}

struct edge {
    int fromnode;
    int tonode;
    int val;
};
int main()
{
    int N = 5;
    int  E = 8;
    //path为存储最短路径的数组
    vector<edge> path;
    //node为查找节点是否成环的并查集
    ParTree <int> node(N+1);
    //Edges为查找最短路径的最小堆
    MinHeap <edge> Edges(10);
    //graph为存储图中边信息的结构数组
    edge graph[8];
    graph[0] = {1,2,1};
    graph[1] = { 1,3,4 };
    graph[2] = { 1,4,7 };
    graph[3] = { 1,5,8 };
    graph[4] = { 2,3,3 };
    graph[5] = { 3,4,6 };
    graph[6] = { 4,5,10 };
    graph[7] = { 2,5,5 };
    //对最小堆插入所有边
    for (int i = 0;i < E;i++) {
        Edges.Insert(graph[i]);
    }
    edge tmp;
    while (path.size() != (N - 1)) {
        tmp = Edges.RemoveMin();
        if (node.Different(tmp.fromnode, tmp.tonode)) {
            path.push_back(tmp);
            node.Union(tmp.fromnode, tmp.tonode);
        }

    }
    for (int i = 0;i < (N - 1);i++) {
        cout <<"from"<< path[i].fromnode<<", to"<< path[i].tonode << endl;
        
    }
    

}

