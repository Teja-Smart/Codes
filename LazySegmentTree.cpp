#include<bits/stdc++.h>
using namespace std;
#define INF 1e18


class SegmentTree{

};

class SegmentTreeLazy{
    public:
    
    vector<int> t;
    vector<int> lazy;

    SegmentTree(vector<int> a){
        int n = a.size();
        t.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        build(a, 1, 0, n - 1);
    }

    int merge(int a, int b){
        return a + b;
    }

    void build(vector<int> &a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
            lazy[v] = 0;
        } else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = merge(t[v * 2], t[v * 2 + 1]);
            lazy[v] = 0;
        }
    }

    void push(int v) {
        t[v * 2] += lazy[v];
        lazy[v * 2] += lazy[v];
        t[v * 2 + 1] += lazy[v];
        lazy[v * 2 + 1] += lazy[v];
        lazy[v] = 0;
    }

    void update(int v, int tl, int tr, int l, int r, int addend) {
        if (l > r) 
            return;
        if (l == tl && tr == r) {
            t[v] += addend;
            lazy[v] += addend;
        } else {
            push(v);
            int tm = (tl + tr) / 2;
            update(v * 2, tl, tm, l, min(r, tm), addend);
            update(v * 2+1, tm + 1, tr, max(l, tm + 1), r, addend);
            t[v] = max(t[v * 2], t[v * 2 + 1]);
        }
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return -INF;
        if (l == tl && tr == r)
            return t[v];
        push(v);
        int tm = (tl + tr) / 2;
        return max(query(v * 2, tl, tm, l, min(r, tm)), 
                query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }


    SegmentTree(int n){
        t.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }

    void RangeUpdate(int l, int r, int val){
        update(1, 0, n - 1, l, r, val);
    }

    int RangeQuery(int l, int r){
        return query(1, 0, n - 1, l, r);
    }




};
