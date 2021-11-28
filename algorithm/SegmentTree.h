
#include<stdio.h>
#include<memory.h>
#include<algorithm>
#include<string.h>
#include<cstring>
#include<vector>
#include<map>
#include<list>
#include<iostream>
#define MAX 10000
using namespace std;
// rt << 1 = rt * 2, rt << 1 | 1 = rt * 2 + 1
int a[MAX],ans[MAX<<2],lazy[MAX<<2],n;
//a[]为原序列信息，ans[]模拟线段树维护区间和，lazy[]为懒惰标记
 
namespace SegmentTree
{
    //向上更新节点
    void pushup(int rt){
        ans[rt] = ans[rt<<1] + ans[rt<<1|1];	//查询区间和
        //ans[rt] = max(ans[rt<<1],ans[rt<<1|1]);	查询区间最值
    }
    
    //建树操作, rt记录当前位置
    // build（1，n, 1)
    void build(int l,int r,int rt){
        if(l == r){
            ans[rt] = a[l]; //或初始化为0
            return;
        }
        int mid = (l + r) >> 1;
        build(l, mid, rt<<1);	//左子树递归
        build(mid+1, r, rt<<1|1);	//右子树递归
        pushup(rt);
    }
    
    //向下更新节点
    //l表示节点个数
    // += ： 区间增减  =：区间替换
    void pushdown(int rt, int l){
        if(lazy[rt]){
            lazy[rt << 1] += lazy[rt];
            lazy[rt << 1|1] += lazy[rt];
            ans[rt << 1] += lazy[rt] * (l-l/2);
            ans[rt << 1|1] += lazy[rt] * (l/2);
            lazy[rt] = 0;
        }
    }
    
    //单点更新
    //L  R  区间范围
    //l 查找的点
    //C 更新值
    void add(int L, int R, int l, int C, int rt){
        if(L == R){
            ans[rt] = C;
            return ;
        }
        int mid = (L+R) >> 1;
        pushdown(rt, R-L+1);	//若既有点更新又有区间更新，需要此句
        if(l <= mid)
            add(L, mid, l, C, rt <<1);
        else
            add(mid+1, R, l, C, rt<<1|1);
        pushup(rt);
    }
    
    //区间更新
    //update（1,1,2,1,n,1)
    //L  R  区间范围
    //l 查找的点
    //l  r  更新区间
    void update(int L,int R,int C, int l, int r, int rt){
        if(L >= l && R <= r){
            ans[rt] = C * (R-L+1);
            lazy[rt] = C;
            return ;
        }
        int mid = (L+R) >> 1;
        pushdown(rt, R-L+1);
        if(r <= mid)	//只在左边更新
            update(L, mid, C, l, r, rt<<1);
        else if(r > mid)	//只在右边更新
            update(mid+1, R, C, l, r, rt<<1|1);
        else{	//两边都要更新
            update(L, mid, C, l, r, rt<<1);
            update(mid+1, R, C ,l, r, rt<<1|1);
        }
        pushup(rt);
    }
    
    //查询区间和
    //L  R  区间范围
    //l  r  查询区间
    int query(int L, int R, int l, int r, int rt){
        if(L >= l && R <= r)
        return ans[rt];
        int mid = (L+R)>>1;
        pushdown(rt, R-L+1);
        if(r <= mid)
        return query(L, mid, l, r, rt<<1);
        else if(l > mid)
        return query(mid+1, R, l, r, rt<<1|1);
        else{
            return query(L, mid, l, mid, rt<<1) + query(mid+1, R, mid+1, r, rt<<1|1);
        } 
        //查询区间最值
        //return max(query(L, mid, l, mid, rt<<1),query(mid+1, R, mid+1, r, rt<<1|1));
    }
}
