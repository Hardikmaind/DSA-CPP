#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int maxi = *max_element(a.begin(), a.end());            //the method max_element(itr1,itr2) returns the iterator pointing to the maximum element in the range [itr1,itr2). and we have dereferenced it to get the value of the maximum element
    int mini = *min_element(a.begin(), a.end());            //same here also
    vector<int> f(maxi - mini + 2); // Statement A

    for (int i = 0; i < n; i++)
    {
        f[(a[i]-mini)]++; // Statement B
    }

    for (int i = 0; i < f.size(); i++)
    {
        for (int j = 0; j < f[i]; j++)
        {
            cout << (i + mini) << " "; // Statement C
        }
    }
}
int main(){
    solve();
    return 0;
}