#include <iostream>
#include <vector>
#include <list>
using namespace std;
struct Edge
{
    int to, len;
};
bool spfa(const int &beg,                    //出发点
          const vector<list<Edge>> &adjlist, //邻接表，通过传引用避免拷贝
          vector<int> &dist,                 //出发点到各点的最短路径长度
          vector<int> &path)                 //路径上到达该点的前一个点
{
    const int INF = 0x7FFFFFFF, NODE = adjlist.size(); //用邻接表的大小传递顶点个数，减少参数传递
    dist.assign(NODE, INF);                            //初始化距离为无穷大
    path.assign(NODE, -1);                             //初始化路径为未知
    list<int> que(1, beg);                             //处理队列
    vector<int> cnt(NODE, 0);                          //记录各点入队次数，用于判断负权回路
    vector<bool> flag(NODE, 0);                        //标志数组，判断是否在队列中
    dist[beg] = 0;                                     //出发点到自身路径长度为0
    cnt[beg] = flag[beg] = 1;                          //入队并开始计数
    while (!que.empty())
    {
        const int now = que.front();
        que.pop_front();
        flag[now] = 0;                  //将当前处理的点出队
        for (list<Edge>::const_iterator //用常量迭代器遍历邻接表
                 i = adjlist[now].begin();
             i != adjlist[now].end(); ++i)
            if (dist[i->to] > dist[now] + i->len) //不满足三角不等式
            {
                dist[i->to] = dist[now] + i->len; //更新
                path[i->to] = now;                //记录路径
                if (!flag[i->to])                 //若未在处理队列中
                {
                    if (NODE == ++cnt[i->to])
                        return 1;                                        //计数后出现负权回路
                    if (!que.empty() && dist[i->to] < dist[que.front()]) //队列非空且优于队首（SLF）
                        que.push_front(i->to);                           //放在队首
                    else
                        que.push_back(i->to); //否则放在队尾
                    flag[i->to] = 1;          //入队
                }
            }
    }
    return 0;
}