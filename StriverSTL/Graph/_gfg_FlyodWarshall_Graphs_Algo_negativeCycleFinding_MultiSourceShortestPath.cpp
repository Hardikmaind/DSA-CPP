#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
      void floydWarshall(vector<vector<int>> &d) {
          // Code here
          const int INF=1e8;
          for (int k = 0; k <  d.size(); ++k) {
              for (int i = 0; i < d.size(); ++i) {
                  for (int j = 0; j < d[0].size(); ++j) {
                       if (d[i][k] != INF && d[k][j] != INF) {
                          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                      }
                  }
              }
          }
          
      }
  };

  void print_costMatrix(vector<vector<int>> &d) {
      const int INF=1e8;
      cout<<"Printing Cost Matrix"<<endl;
      for (int i = 0; i < d.size(); ++i) {
          for (int j = 0; j < d[0].size(); ++j) {
              if (d[i][j] == INF)
                  cout<<"INF ";
              else
                  cout<<d[i][j]<<" ";
          }
          cout<<endl;
      }
    }

  int main(){
    Solution obj;
    const int INF=1e8;
    vector<vector<int>> dist_or_costMatrix={{0,4,INF,5,INF},{INF,0,1,INF,6},{2,INF,0,3,INF},{INF,INF,1,0,2},{1,INF,INF,4,0}};
    print_costMatrix(dist_or_costMatrix);
    cout<<endl;
    obj.floydWarshall(dist_or_costMatrix);
    print_costMatrix(dist_or_costMatrix);
    return 0;

  }