#include<bits/stdc++.h>
using namespace std;
using ll=long long;

void subset_sum(vector<int>& nums,vector<ll>& subSum,int n){
    int total=1<<n;
    subSum.resize(total);
    for(int i=0;i<total;i++){
        ll sum=0;
        for(int j=0;j<n;j++){
            if((i>>j)&1){
                sum+=nums[j];
            }
        }
        subSum[i]=sum;
    }
}


int main(){
    int n;
    ll x;
    cin>>n>>x;
    int n1=n/2,n2=n-n1;
    vector<int> A(n1),B(n2);
    for(int i=0;i<n1;i++){
        cin>>A[i];
    }
    for(int i=0;i<n2;i++){
        cin>>B[i];
    }
    vector<ll> left,right;
    subset_sum(A,left,n1);
    subset_sum(B,right,n2);
    sort(right.begin(),right.end());
    ll ans=0;
    for(int i=0;i<(int)left.size();i++){
        ll required=x-left[i];
        ans+=upper_bound(right.begin(),right.end(),required)-lower_bound(right.begin(),right.end(),required);
    }
    cout<<ans<<endl;
}