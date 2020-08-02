# 第十一周作业

主要代码

```c++
while (path.size() != (N - 1)) {
        tmp = Edges.RemoveMin();
        if (node.Different(tmp.fromnode, tmp.tonode)) {
            path.push_back(tmp);
            node.Union(tmp.fromnode, tmp.tonode);
        }
```

测试案例及结果

![image-20200517195335992](C:\Users\admin\AppData\Roaming\Typora\typora-user-images\image-20200517195335992.png)

![image-20200517195510106](C:\Users\admin\AppData\Roaming\Typora\typora-user-images\image-20200517195510106.png)