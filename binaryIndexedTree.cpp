// http://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/
// http://codeforces.com/blog/entry/619
// http://en.wikipedia.org/wiki/Fenwick_tree
// Advantage of BITs(Binary Index Trees) over segment trees are they require less space and easy to implement.
#include<iostream>

using namespace std;


// Returns sum of arr[0..index]. This function assumes that array is preprocessed and partial sums of array elements are store in BITre[].
int getSum(int BITree[], int n, int index)
{
	int sum = 0; // initialize result
	
	// index in BITree[] is 1 more than the index in arr[]
	index++;
	
	// Traverse ancestors of BITree[index]
	while(index > 0) {
		// Add current element of BITree to sum
		sum += BITree[index];
		
		// Move index to parent node
		index -= index & (-index);
	}
	return sum;
}

// Updates a node in Binary Index Tree (BITree) at a given index in BITree. The given value 'val' is added to BITree[i] and all of it's ancestors in tree
void updateBIT(int *BITree, int n, int index, int val)
{
	// index in BITree[] is 1 more than the index in arr[], this is just for our convinience
	index++;
	
	// Traverse all ancestors and add 'val'
	while(index <= n) {
		// Add 'val' to current node of BITree
		BITree[index] += val;
		
		// Update index to that of parent
		index += index & (-index);
	}
	
}

// Constructs and returns a Binary Indexed Tre for given array of size n
int *constructBITree(int arr[], int n)
{
	// Create and initialize BITree[] a 0
	int *BITree = new int[n + 1];
	for(int i = 1; i <= n; i++)
		BITree[i] = 0;
	
	// Store the actual values in BITrees[] using update()
	for(int i = 0; i < n; i++)
		updateBIT(BITree, n, i, arr[i]);
	
	return BITree;
}

int main()
{
	int arr[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
	int n = sizeof(arr)/sizeof(arr[0]);
	int *BITree = constructBITree(arr, n);
	cout << getSum(BITree, n, 5) << endl;
	
	arr[3] += 6;
	updateBIT(BITree, n, 3, 6);
	
	cout << getSum(BITree, n, 5) << endl;
	return 0;
}
/*
Parent can be obtaining by removing hte last set bit from index, i.e, index = index - (index & (-index))
*/