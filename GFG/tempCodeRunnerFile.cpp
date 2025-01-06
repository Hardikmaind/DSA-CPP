//function to print hash map
void printMap(map<int,vector<int>> &hm){
    for(auto &x:hm){
        cout<<x.first<<"->";
        for(auto &y:x.second){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}