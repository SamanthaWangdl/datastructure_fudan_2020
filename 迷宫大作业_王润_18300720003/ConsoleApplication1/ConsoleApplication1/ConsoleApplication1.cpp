// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<time.h>
#include<cstdlib>
#include "conio.h"
#include<graphics.h>
#include<stack>
#include<queue>
using namespace std;
#define lENGTH   5
#define WIDTH 5
//迷宫的边境从0开始，0为可以走，1为不可以走,宽度和长度要大于2
int* maze = new int[lENGTH * WIDTH];
void maze_gen(int* maze) {
    int i, j;
    srand(time(0));
    for (i = 0;i < WIDTH;i++)
    {
        maze[i] = 1;
        maze[(lENGTH - 1) * WIDTH + i] = 1;
    }
    for (j = 0;j < lENGTH;j++) {
        maze[j * WIDTH] = 1;
        maze[(j + 1) * WIDTH-1] = 1;
    }
    for (i = 0;i < (WIDTH - 2);i++) {     
        for (j = 0;j < (lENGTH - 2);j++) {
            maze[WIDTH + 1 + i+j*WIDTH] = (rand() % 5>3);
            
        }
    }
    maze[WIDTH + 1] = 0;
    maze[lENGTH*WIDTH-2-WIDTH] = 0;


}
void plot(int* maze) {
    initgraph(1001, 1001);						/*图形方式初始化*/

    int i;
    for (i = 0;i < lENGTH*WIDTH;i++) {
        setfillcolor(HSLtoRGB((maze[i]+1)*50, 1, 0.5f));
        bar(20*(i%WIDTH),20*(i/WIDTH), 20 * (i % WIDTH+1), 20 * (i / WIDTH+1));

    }
    Sleep(20000);
    closegraph();
}


bool find_path(int* maze, int row, int col) {
    if (col == (WIDTH - 2) && row == (lENGTH - 2)) { return true; }
    if (maze[row * WIDTH + col] == 1 || maze[row * WIDTH + col] == 2 || maze[row * WIDTH + col] == 3)return false;
    maze[row * WIDTH + col] = 2;
    bool up = find_path(maze, row + 1, col);
    bool down = find_path(maze, row - 1, col);
    bool left = find_path(maze, row, col + 1);
    bool right = find_path(maze, row, col - 1);
    if (up || down || left || right) {
        cout << "(" << row << "," << col << ")" << endl;
        return true;
    }
    else {
        maze[row * WIDTH + col] = 3;
        return false;
    }

}

bool find_print_path(int* maze, int row, int col) {
    if (col == (WIDTH - 2) && row == (lENGTH - 2)) { return true; }
    if (maze[row * WIDTH + col] == 1 || maze[row * WIDTH + col] == 2 || maze[row * WIDTH + col] == 3)return false;
    maze[row * WIDTH + col] = 2;
    bool up = find_print_path(maze, row + 1, col);
    bool down = find_print_path(maze, row - 1, col);
    bool left = find_print_path(maze, row, col + 1);
    bool right = find_print_path(maze, row, col - 1);
    if (up || down || left || right) {
        cout << "(" << row << "," << col << ")" << endl;
        return true;
    }
    else {
        maze[row * WIDTH + col] = 3;
        return false;
    }

}
typedef struct
{
    int i;
    int j;
}Box;
typedef struct
{
    Box data[1000];
    int length;		//路径长度 
}PathType;
int num = 0;
void print_all_path( int row, int col, PathType path) {
    if (col == (WIDTH - 2) && row == (lENGTH - 2)) {
        path.data[path.length].i = col;
        path.data[path.length].j = row;
        path.length++;
        printf("迷宫路径 %d 如下：\n", ++num);
        for (int k = 0;k < path.length;k++) {
            printf("\t(%d,%d)", path.data[k].i, path.data[k].j);
            if ((k + 1) % 5 == 0)		//每输出5个方块后换行 
                printf("\n");
        }
        printf("\n");
    }
   
    else {
        int i;
        if (maze[row * WIDTH + col] != 1 && maze[row * WIDTH + col] != 2) {
            for (i = 0;i < 4;i++) {


                maze[row * WIDTH + col] = 2;
                path.data[path.length].i = col;
                path.data[path.length].j = row;
                path.length++;
                switch (i)
                {
                case 0: print_all_path(row + 1, col, path);break;
                case 1: print_all_path(row - 1, col, path); break;
                case 2: print_all_path(row, col + 1, path);break;
                case 3:  print_all_path(row, col - 1, path);break;
                default:
                    break;
                }
                path.length--;//这步忘记加了
                maze[row * WIDTH + col] = 0;


            }
        }
       
    }
}

int main()
{
//迷宫生成和画出迷宫
    maze_gen(maze);
    int i;
    plot(maze);

//第一个任务：查找是否有路径
    //bool ispath = find_path(maze,1,1);
    //printf("%d", ispath);
    //plot(maze);

    //第二个任务：打印路径   
    find_print_path(maze, 1, 1);
    plot(maze);
 
    //第三个任务：打印所有路径
    //PathType path;
    //path.length = 0;
    //print_all_path( 1, 1, path);
}


