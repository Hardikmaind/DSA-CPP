================== tc is O(n) and SC is O(1)...This below code is more optimised
        Solution obj;
        vector<int>arr={1,2,3,2,1,4};
        auto res=obj.singleNum(arr);
        for(auto &x:res){
            cout<<x<<" ";
        }
        cout<<endl;