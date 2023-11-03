#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;cin>>t;
	while(t--){
	    long long n;cin>>n;
	    vector<long long> v(n);
	    for(int i = 0 ; i<n;i++)
	        cin>>v[i];
        int sum = 0 ;
	    for(int i = 0 ; i<n-2;i++){
            int ini = v[i+2];
	        v[i+2] +=  (v[i]+v[i+1]+v[i+2])%3==0 ? 0 : 3 -(v[i]+v[i+1]+v[i+2])%3 ;
            sum += v[i+2] - ini ;
	    }
	    cout<<sum<<endl;
	}
	return 0;
}