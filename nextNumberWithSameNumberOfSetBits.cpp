#include <iostream>
using namespace std;
#define ll long long int
ll findNextWithSameSetBit(ll n){
    ll rightBit=(n & -n);
    ll nextNumber=n+rightBit;
    ll BitPattern=n^nextNumber;
    BitPattern=BitPattern/rightBit;
    BitPattern=BitPattern>>2;
    nextNumber=nextNumber|BitPattern;
    return nextNumber;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    ll n;
	    cin>>n;
	    cout<<findNextWithSameSetBit(n)<<endl;
	}
	return 0;
}