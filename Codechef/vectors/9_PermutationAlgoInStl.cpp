#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	vector<int>v;
	int x;
	for(int i=0;i<n;i++){
	    cin>>x;
	    v.push_back(x);
	}
	next_permutation(v.begin(),v.end());
	for(int i:v)    cout<<i<<" ";
    cout<<endl;
    prev_permutation(v.begin(),v.end());
    prev_permutation(v.begin(),v.end());
    for(int i:v)    cout<<i<<" ";
}