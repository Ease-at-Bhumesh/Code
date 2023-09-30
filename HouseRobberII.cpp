#include<bits/stdc++.h>
// Header Line 2
using namespace std;
int solve(vector<int>&v){
    int n=v.size();
    if(n==1) return v[0];
    if(n==2) return max(v[0],v[1]);
    int s_m=0;
    int l_m=v[0];
    int temp=0;
    for(int i=1;i<n-1;i++){
        temp=s_m+v[i];
        s_m=max(s_m,l_m);
        l_m=max(temp,l_m);
    }
    int res1=max(s_m,l_m);
    s_m=0;
    l_m=v[1];
    temp=0;
    for(int i=2;i<n;i++){
        temp=s_m+v[i];
        s_m=max(s_m,l_m);
        l_m=max(temp,l_m);
    }
    int res2=max(s_m,l_m);
    return max(res1,res2);
}
int main(){
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    cout<<solve(v);
    return 0;
}