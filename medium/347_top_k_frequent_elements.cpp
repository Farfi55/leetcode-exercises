/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
	void heapify(vector<pair<int, int>>& heap, int i) {
		int largest = i;
		int l = 2 * i; // left = 2*i
		int r = 2 * i + 1; // right = 2*i + 1

		// If left child is larger than root
		if(l < heap.size() && heap[l].second > heap[largest].second)
			largest = l;

		 // If right child is larger than largest so far
		if(r < heap.size() && heap[r].second > heap[largest].second)
			largest = r;

		// If largest is not root
		if(largest != i) {
			swap(heap[i], heap[largest]);

			// Recursively heapify the affected sub-tree
			heapify(heap, largest);
		}

	}


public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> frequencies;

		int uniques = 0;
		for(int x : nums) {
			if(frequencies[x]++)
				uniques++;
		}

		// we start at index 1 just to make index operation simpler
		vector<pair<int, int>> heap(1);
		heap.reserve(uniques + 1);

		for(auto& frequence : frequencies) {
			int i = heap.size();
			heap.emplace_back(frequence);

			// while this new frequence is higher than its parent
			while(i > 1 && heap[i].second > heap[i / 2].second) {
				swap(heap[i], heap[i / 2]);
				i /= 2;
			}
		}


		vector<int> out; out.reserve(k);

		for(int i = 0; i < k; i++) {
			out.push_back(heap[1].first);
			heap[1] = heap.back();
			heap.pop_back();

			heapify(heap, 1);

		}

		return out;



	}
};
// @lc code=end

