/*
* @lc app = leetcode id = 997 lang = cpp
*
*[997] Find the town judge
*/

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
// @lc code=start
class Solution {
public:

	int findJudge(int n, vector<vector<int>>& trust) {
		vector<int> votes(n + 1, 0);

		int judge = 1;

		for(int i = 0; i < trust.size(); i++) {
			votes[trust[i][0]] = INT_MIN; //the town judge doesn't trust nobody
			votes[trust[i][1]] += 1; //the town judge doesn't trust nobody
			if(votes[judge] < votes[trust[i][1]])
				judge = trust[i][1];
		}

		return votes[judge] == n - 1 ? judge : -1;
	}
};


// @lc code=end

