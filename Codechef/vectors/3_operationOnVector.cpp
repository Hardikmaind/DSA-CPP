#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    // write your code here
    int N, x;
    cin >> N >> x;
    vector<int> arr;
    for (int i = 0; i < N; i++)
    {
        int ele;
        cin >> ele;
        arr.push_back(ele);
    }

    //   this is a loop to reaplce the element x

    //   for(int i=0;i<arr.size();i++){
    //       if(arr[i]==x){
    //           arr[i]=x+1;
    //       }
    //   }

    // this is the vector method to replace the eelment directly

    replace(arr.begin(), arr.end(), x, x + 1);

    //   this is a loop to pritn the elements of the vector
    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}
