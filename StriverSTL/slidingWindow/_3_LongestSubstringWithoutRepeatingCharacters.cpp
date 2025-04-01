#include <bits/stdc++.h>
using namespace std;


void print(vector<int>&arr){
    for(auto x:arr){
        cout<<x<<" ";
    }
}
void printmap(unordered_map<char,int>&map){
    for(auto x:map){
        cout<<x.first<<" "<<x.second<<" "<<endl;
    }
}

//this is a brute force solution 
int longestSubstring1(string &s){
    int set[255]={0};

    int len=0,maxlen=0;
    for(int i=0;i<s.size();i++){
        for(int j=i;j<s.size();j++){
            if(set[s[j]]==1) break;
            len=j-i+1;
            maxlen=max(maxlen,len);
            set[s[j]]=1;
        }
    }
    return maxlen;
    
}
int longestSubstring(string &s){
    int set[255]={0};
    int l=0,r=0,len=0,maxlen=0;
    while(r<s.size()){
        while(set[s[r]]==1){                //do this until the set[s[r]] is unique again. and also remove the leftest element , and then move the pointer forward
            set[s[l]]==0;
            l++;
  
        }
        len=r-l+1;
        set[s[r]]=1;
        maxlen=max(len,maxlen);
        r++;

    }
    return maxlen;
}

int main(){
    string str="cadbzabcd";
    cout<<longestSubstring1(str)<<endl;
    cout<<longestSubstring(str)<<endl;
    return 0;
}