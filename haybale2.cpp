#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

bool cmpFunc(int i, int j)
{
	return i < j;
}

int binary(int *arr, int i)
{
	int n = sizeof(arr) / sizeof(int);
	int low = 0, high = n - 1;
	int mid = (low + high) / 2;
	while(low < high) {
		if(arr[mid] <= i)
			low = mid;
		else
			high = mid - 1;
		mid = (low + high) / 2;
	}
	return low;
}

int main()
{
	int n, q;
	cin >> n >> q;
	int *arr = new int [n];
	memset(arr, 0, n * sizeof(int));
	int *start = new int[q];
	int *end = new int[q];
	for(int i = 0; i < q; i++)
		cin >> start[i] >> end[i];
	sort(start, start + q, cmpFunc);
	sort(end, end + q, cmpFunc);
	for(int i = 0; i < q; i++)
		cout << start[i] << " ";
	cout << endl;
//	for(int i = 0; i < n; i++)
//		arr[i] = binary(start, i) - binary(end, i);
		cout << binary(start, i, q) << " " << binary(end, );
	cout << endl;
	return 0;
	
}
