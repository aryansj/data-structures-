#include<bits/stdc++.h>
using namespace std ;
#define int long long
int ST[40];
int a[40];
int create(int i, int l, int r){
    if(r == l + 1)
        return ST[i] = a[l]; //if leaf, then assign a[l]
    create(2*i, l, (r + l)/2); // else create 2 seg trees, with 2 children at 2i and 2i+1, with first and second half ranges
    create(2*i + 1, (r + l)/2, r);
    return ST[i] = (ST[2*i] + ST[2*i + 1]); // combine results of both children
}
int query(int l, int r, int L, int R, int x){ // l, r is query range, LR is range covered by current node, x is its index in ST
    if(L > r || R <= l) // no intersection, 0 contribution to sum
        return 0;
    else if(L >= l && R <= r+1) // entirely included, full contribution to queried sum
        return ST[x];
    else
        return (query(l, r, L, (L + R)/2, 2*x) + query(l, r, (L + R)/2, R, 2*x+1));// partial contribution, add contributions of both halves
}
signed main (){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    int n, i, q;
    cout << "enter size" << endl;
    cin >> n;
    cout << "enter elements" << endl;
    for(i = 0; i < n; i++)
        cin >> a[i+1];
    create(1, 1, n + 1); // create seg-tree
    cout << "enter number of queries" << endl; 
    cin >> q;
    for(i = 0; i < q; i++){
        int l, r;
        cout << "enter range l, r" << endl;
        cin >> l >> r;
        cout << "sum of range is " << query(l, r, 1, n + 1, 1) << endl;
    }
    return 0 ;
}