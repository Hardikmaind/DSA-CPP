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

//tc is O(n) and sc is O(n)
int longestSubstring(string &s){
    int set[255]={0};
    int l=0,r=0,len=0,maxlen=0;
    while(r<s.size()){
        while(set[s[r]]==1){                //do this until the set[s[r]] is unique again. and also remove the leftest element , and then move the pointer forward
            set[s[l]]=0;
            l++;
  
        }
        len=r-l+1;
        set[s[r]]=1;
        maxlen=max(len,maxlen);
        r++;

    }
    return maxlen;
}


int longestSubstring3(string &s){
    int set[255]={-1};
    int l=0,r=0,len=0,maxlen=0;
    while(r<s.size()){
        if(set[s[r]]!=-1 && set[s[r]]>=l){          //set[s[r]] >= l ensures that we only update l (the left pointer) if the repeating character exists within the current window.
            l=set[s[r]]+1;

        }
        len=r-l+1;

        maxlen=max(maxlen,len);
        set[s[r]]=r;
        r++;
    }
    return maxlen;
}

int main(){
    string str="cadbzabcd";                                     //here in longestsubString3 ,algo we set the c as 0 in set. and because of a appeaing 2 times we move the l to (ind of a)+1 pos. so after moving we encounter the c again , but c is stored in the set alrady ,but now in this case set[s[r]]<l, since l is moved ahead, so we dont need to change the c value in the set.
    cout<<longestSubstring1(str)<<endl;
    cout<<longestSubstring(str)<<endl;
    cout<<longestSubstring3(str)<<endl;
    return 0;
}