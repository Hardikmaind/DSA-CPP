#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //! THIS IS ONE STYLE OF WRITING THE CODE. 
    // * TC IS O()
        int util(vector<int>&arr,int ind,int sum){
            if(ind==arr.size()){
                return sum;
            }
            return util(arr,ind+1,sum+arr[ind]) + util(arr,ind+1,sum);
        }
        int allSubsetSum(vector<int>&arr){
            return util(arr,0,0);
        }

        // this is another style of writing the code
        int util2(vector<int>&arr,int ind,int sum){
            if(ind==arr.size()){
                return sum;
            }
            int withele=util2(arr,ind+1,sum+arr[ind]);

            int withoutele=util2(arr,ind+1,sum);

            return withele+withoutele;
        }
        int allSubsetSum2(vector<int>&arr){
            return util2(arr,0,0);
        }



        // this is the most optimised code
        int allSubsetSum3(vector<int>& arr) {
            int total = accumulate(arr.begin(), arr.end(), 0);
            int n = arr.size();
            return total * (1 << (n - 1));
        }
};
int main(){
    Solution obj;
    vector<int> arr={1,2,3};
    int res=obj.allSubsetSum(arr);
    cout<<res<<endl;
    int res2=obj.allSubsetSum2(arr);
    cout<<res2<<endl;
    int res3=obj.allSubsetSum3(arr);
    cout<<res3<<endl;
    return 0;

}