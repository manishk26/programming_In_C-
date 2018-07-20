#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void finedAllNumber(vector<ll>&myVec){
    set<ll> mySet;
    mySet.insert(0);
    for(ll i=0;i<=60;i++){
        for(ll j=i;j<=60;j++){
            for(ll k=j;k<=60;k++){
                //for 1 bit numbers
                if(i==j && i==k){
                    ll value=(1LL<<i);
                    mySet.insert(value);
                }
                //for two set bits numbers
                else if(i==j && i!=k){
                    ll value=(1LL<<i)+(1LL<<k);
                    mySet.insert(value);
                }else if(i==k && i!=j){
                    ll value=(1LL<<i)+(1LL<<j);
                    mySet.insert(value);
                }else if(j==k && i!=j){
                    ll value=(1LL<<i)+(1LL<<j);
                    mySet.insert(value);
                }
                //for three set bits value
                else {
                    ll value=(1LL<<i)+(1LL<<j)+(1LL<<k);
                    mySet.insert(value);
                }
            }
        }
    }
    for(auto i=mySet.begin();i!=mySet.end();i++)
    myVec.push_back(*i);
}
int main(){
    int t;
    cin>>t;
    vector<ll> myVec;
    finedAllNumber(myVec);
    while(t--){
        ll first,second;
        cin>>first>>second;
        ll count=0;
        if(first==0)
         count=upper_bound(myVec.begin(),myVec.end(),second)-myVec.begin();
        else
         count=upper_bound(myVec.begin(),myVec.end(),second)-
        upper_bound(myVec.begin(),myVec.end(),first-1);
    cout<<count<<endl;
        
    }
}