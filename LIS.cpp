#include<bits/stdc++.h>
using namespace std ;
#define int long long
signed main (){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    int n, i;
    cin >> n;
    int a[n];
    vector <int> ele;
    for(i = 0; i < n; i++){
        cin >> a[i];
        vector <int> :: iterator upper;
        upper = upper_bound(ele.begin(), ele.end(), a[i]); // search for first element strictly greater than a[i], and update the last element for LIS of that length.
        if(upper == ele.end())
            ele.push_back(a[i]);
        else
            ele[upper - ele.begin()] = a[i];        
    }    
    cout << ele.size() << endl;
    return 0 ;
}