/*
	Zadanie: "House Robber II" z Leetcode
*/
#include <bits/stdc++.h>
using namespace std;

int travel(vector<int>& nums, int st, int ed);

int rob(vector<int>& nums)
{
	int n = nums.size();

	int includeFR = travel(nums, 0, n-2); // z perwszym elementem i bez ostatniego elementu
	int excludeFR = travel(nums, 1, n-1); // bez pierwszego elementu i z ostatnim elementem
	
	return max(includeFR, excludeFR);
}

int travel(vector<int>& nums, int st, int ed)
{
	// to samo jak budowanie dp[n][2]
	// ale bez obciążania pamięci
	// bo w O(1), a nie w O(n)
	int take = nums[st];
	int leave = 0;
	
	for (int i=st+1; i<=ed; i++)
	{
		int new_take = leave + nums[i];
		int new_leave = max(take, leave);
		take = new_take;
		leave = new_leave;
	}

	return max(take, leave);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	vector<int> nums = {1, 2, 3, 1};
	cout << rob(nums) << "\n";
	
	return 0;
}