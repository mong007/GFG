#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int, pair<int, int> > &p1, pair<int, pair<int, int> > &p2) {
    return abs(p1.first) > abs(p2.first);
} 
int main() {
	//code
	int t;
	cin>>t;
	while(t--) {
	    int n,X,Y;
	    cin>>n>>X>>Y;
	    vector<pair<int, pair<int, int> > > v1;
	    vector<int> v2,v3;
	    for(int i=0;i<n;i++) {
	        int t1;
	        cin>>t1;
	        v2.push_back(t1);
	    }
	    for(int i=0;i<n;i++) {
	        int t1;
	        cin>>t1;
	        v3.push_back(t1);
	        pair<int, int> p1;
	        pair<int , pair<int, int> > p2;
	        p1 = make_pair(v2[i], v3[i]);
	        p2 = make_pair(v2[i] - v3[i], p1);
	        v1.push_back(p2);
	    }
	    sort(v1.begin(), v1.end(), comp);
	    int ct1 = X,ct2 = Y;
	    int sum = 0;
	    for(int i=0;i<n;i++) {
	        if(ct1==0) {
	            sum+=v1[i].second.second;
	            ct2--;
	        }
	        else if(ct2==0) {
	            sum+=v1[i].second.first;
	            ct1--;
	        }
	        else {
	            if(v1[i].first > 0) {
	                sum+=v1[i].second.first;
	                ct1--;
	            }
	            else {
	                sum+=v1[i].second.second;
	                ct2--;
	            }
	        }
	        //cout<<v1[i].first<<" "<<v1[i].second.first<<" "<<v1[i].second.second<<endl;
	    }
	    cout<<sum<<endl;
	}
	return 0;
}