/*
 * @lc app=leetcode id=1823 lang=cpp
 *
 * [1823] Find the Winner of the Circular Game
 */
#include <array>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
	int findTheWinner(const int n, int k) {
		if(k == 1) return n;

		vector<bool> playing(n, true);

		int i = k - 1;
		playing[i] = false;
		int n_playing = n - 1;

		while(n_playing > 1) {
			for(int j = 0; j < k;) {
				if(playing[(++i) % n]) j++;
			}
			playing[i = (i % n)] = false;
			n_playing--;
		}

		for(i = 0; i < n; i++)
			if(playing[i])
				return i + 1;


		return -1;
	}
};
// @lc code=end

int main(int argc, char const* argv[])
{
	Solution().findTheWinner(5, 2);
	return 0;
}
