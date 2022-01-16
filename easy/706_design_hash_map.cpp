// @before-stub-for-debug-begin
#include <vector>
#include <forward_list>
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

	const static int N_BUCKETS = 10007; // is prime

	vector<forward_list<pair<int, int>>> map;

public:
	MyHashMap() : map(N_BUCKETS) {}
	// MyHashMap(int n_buckets_) : n_buckets(n_buckets_), buckets(n_buckets_) {}

	void put(int key, int value) {
		auto& list = map[key % N_BUCKETS];
		for(auto it = list.begin(); it != list.end(); it++) {
			if(it->first == key) {
				it->second = value;
				return;
			}
		}
		list.emplace_front(key, value);
	}

	int get(int key) {
		auto& list = map[key % N_BUCKETS];

		for(auto it = list.begin(); it != list.end(); it++)
			if(it->first == key)
				return it->second;


		return -1;
	}

	void remove(int key) {
		auto& list = map[key % N_BUCKETS];
		list.remove_if([key](auto n) { return n.first == key; });
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

