//this is how we write the multiline macro ====>>>

// #define input(i, a, n)          \
// 	;                           \
// 	for (int i = 0; i < n; i++) \
// 	{                           \
// 		cin >> a[i];            \
// 	}




#include <bits/stdc++.h>
#define fastio               \
	ios::sync_with_stdio(0); \
	cin.tie(0);              \
	cout.tie(0);
#define lil long long int
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define input(i, a, n);          \
	for (int i = 0; i < n; i++) \
	{                           \
		cin >> a[i];            \
	}
#define wh(t) \
	int t;    \
	cin >> t; \
	while (t--)

using namespace std;

// in this problem we just have to check whether the minimum element is at the start and end of the array or not. if it is then we can make the array equal by adding the minimum element to the end of the array. else we can't make the array equal.. so print yes or no accordingly.

int main()
{
	fastio;
	wh(t)
	{
		lil n;
		cin >> n;
		lil a[n];
		input(i, a, n);
		if (n == 1)
		{
			cout << "YES\n";
			continue;
		}
		int min = a[0], pos = 0, flag = 0;
		for (int i = 1; i < n; i++)
		{
			if (a[i] < min)
			{
				min = a[i];
				pos = i;
			}
		}
		if (a[0] == min && a[n - 1] == min)
		{
			yes;
		}
		else
		{
			no;
		}
	}
}