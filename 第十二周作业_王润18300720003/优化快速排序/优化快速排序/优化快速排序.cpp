// 优化快速排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#define THRESHOLD 28
#include <iostream>
#include <stdlib.h>
#include <time.h> 
using namespace std;
void swap(int Array[], int pivot, int right) {
    int temp = Array[pivot];
    Array[pivot] = Array[right];
    Array[right] = temp;
}
int SelectPivot(int left, int right) {
    return (left + right) / 2;
}

int Partition(int Array[], int left, int right) {
    int l = left;
    int r = right;
    int temp = Array[r];
    while (l != r) {
        while (Array[l] <= temp && r > l)l++;
        if (l < r) {
            Array[r] = Array[l];
            r--;
        }
        while (Array[r] >= temp && r > l)r--;
        if (l < r) {
            Array[l] = Array[r];
            l++;
        }
    }
    Array[l] = temp;
    return l;
}

void ModQuickSort(int Array[], int left, int right,int axis[]) {
    if (right - left + 1 > THRESHOLD) {
        int pivot = SelectPivot(left, right);
        axis[pivot] = 1;
        swap(Array, pivot, right);
        pivot = Partition(Array, left, right);
        ModQuickSort(Array,left,pivot-1,axis);
        ModQuickSort(Array, pivot + 1, right,axis);
    }
}

void InsertSort(int Array[], int n) {
    int temp;
    for (int i = 1;i < n;i++) {
        temp = Array[i];
        int j = i - 1;
        while ((j >= 0) && (temp < Array[j])) {
            Array[j + 1] = Array[j];
            j = j - 1;
        }
        Array[j + 1] = temp;
    }
}
void Quicksort(int* Array, int n,int axis[]) {
    ModQuickSort(Array, 0, n - 1,axis);
    InsertSort(Array, n);
}

void gen_array(int* Array, int n) {
    for (int i = 0;i < n;i++) {
        Array[i] = rand()%1000;
     }
}
int main()
{
    int Array[1000];
    int axis[1000];
    for (int i = 0;i < 1000;i++) {
        axis[i] = 0;
    }
    gen_array(Array, 1000);
    Quicksort(Array, 1000,axis);
    for (int i = 0;i < 1000;i++) {
        printf("%d", Array[i]);
        if (axis[i])printf("*");
        printf(",");
    }

}

