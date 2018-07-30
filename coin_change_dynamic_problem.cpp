#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int V,N;
	    cin>>V>>N;
	    int a[N];
	    for(int i=0;i<N;i++)
	    cin>>a[i];
	    long int result[V+1];
	    result[0]=0;
	    for(int i=1;i<=V;i++)
	    result[i]=INT_MAX;
	    for(int i=0;i<N;i++)
	    {
	        for(int j=0;j<=V;j++){
	            if(a[i]<=j)
	            result[j]=min(result[j],1+result[j-a[i]]);
	        }
	    }
	    if(result[V]==INT_MAX)
	    cout<<"-1"<<endl;
	    else
	    cout<<result[V]<<endl;
	    
	    
	}
	return 0;
}