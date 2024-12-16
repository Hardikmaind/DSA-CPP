#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int peakElement(vector<int> &arr) {
        // Your code here
        int l=0;
        int r=arr.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if((mid==0 ||arr[mid]>arr[mid-1]) &&( mid==arr.size()-1|| arr[mid]>arr[mid+1])){
                return mid;
            }
            if(mid>0 && arr[mid-1]>arr[mid]){
                r=mid-1;
            }else{
                l=mid+1;
            }
            
            
        }
        return -1;
    }



    int peakElement2(vector<int>&arr){
        int l=0;
        int r=arr.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            bool leftGreater=mid==0 || arr[mid]>arr[mid-1];

            bool rightGreater=mid==arr.size()-1 || arr[mid]>arr[mid+1];
            if(leftGreater && rightGreater){
                return mid;
            }

            if(mid>0 && arr[mid-1]>arr[mid]){
                r=mid-1;

            }else{
                l=mid+1;
                }
        }
        return -1;
    }
};
int main(){
    Solution s;
    vector<int> arr={1,2,4,5,7,8,3};
    cout<<"INDEX At: "<<s.peakElement(arr);
    cout<<endl;
    vector<int> arr2={1,2,4,5,7,8,3};
    cout<<"INDEX At: "<<s.peakElement2(arr);
}