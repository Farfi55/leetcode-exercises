// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <iostream>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 */

// @lc code=start
class MyHashMap {

	const static int N_BUCKETS = 256;
	// const int n_buckets;

	int hash(int key) {
		key = ((key) ^ (key >> 1)) % N_BUCKETS;
		return key;
	}

	vector<vector<pair<int, int>>> buckets;

public:
	MyHashMap() : buckets(N_BUCKETS) {}
	// MyHashMap(int n_buckets_) : n_buckets(n_buckets_), buckets(n_buckets_) {}

	void put(int key, int value) {

		vector<pair<int, int>>& bucket = buckets[hash(key)];
		for(int i = 0; i < bucket.size(); i++) {
			if(bucket[i].first == key) {
				bucket[i].second = value;
				return;
			}
		}
		bucket.push_back(make_pair(key, value));
	}

	int get(int key) {
		vector<pair<int, int>>& bucket = buckets[hash(key)];

		for(int i = 0; i < bucket.size(); i++) {
			if(bucket[i].first == key) {
				return bucket[i].second;
			}
		}

		return -1;
	}

	void remove(int key) {
		vector<pair<int, int>>& bucket = buckets[hash(key)];

		for(auto it = bucket.begin(); it != bucket.end(); it++) {
			if(it->first == key) {
				bucket.erase(it);
				return;
			}
		}
	}
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end


int main(int argc, char const* argv[])
{
	MyHashMap myHashMap;

	// for(int i = 0; i < 1000; i++) {
	// 	cout << i << ":\t" << myHashMap.hash(i) << endl;
	// }


	myHashMap.put(1, 1); // The map is now [[1,1]]
	myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
	cout << myHashMap.get(1) << endl;    // return 1, The map is now [[1,1], [2,2]]
	cout << myHashMap.get(3) << endl;    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
	myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
	cout << myHashMap.get(2) << endl;    // return 1, The map is now [[1,1], [2,1]]
	myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
	cout << myHashMap.get(2) << endl;    // return -1 (i.e., not found), The map is now [[1,1]]
	return 0;
}

