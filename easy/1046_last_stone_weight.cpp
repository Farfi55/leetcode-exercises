#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;
        for(auto stone : stones)
            heap.push(stone);

        while(heap.size() > 1) {
            int x = heap.top(); heap.pop();
            int y = heap.top(); heap.pop();

            if(x > y)
                heap.push(x - y);
        }
        return heap.size() ? heap.top() : 0;

    }
};
// @lc code=end

