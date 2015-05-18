// we need to find a decreasing-increasing sequence for L, i, j, k, R
// If difference between L and R is less than 3 then output 0
/*
 Brute force
 Start with L check for next element less than L, store this element in a i. Use this var to check if the next element is greater than i. Keep doing this 'n' time for each L, i, j, k, R. 
 Complexity O(n^4)
 */

#include<iostream>

using namespace std;

int main()
{
	int n, q, a[2000];
	int l, r;
	cin >> n >> q;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	while(q--) {
		cin >> l >> r;
	}
	return 0;
}
