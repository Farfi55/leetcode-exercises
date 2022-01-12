/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// @lc code=start

class Trie {
	Trie* children[26] = { 0 };
	bool isWord = false;

public:
	Trie() {}

	Trie(string s) {
		if(s.length() == 0)
			isWord = true;
		else {
			children[s[0] - 'a'] = new Trie(s.substr(1));
		}
	}


	void insert(string word) {
		if(word.length() == 0) isWord = true;
		else {
			char c = word[0] - 'a';
			if(!children[c])
				children[c] = new Trie(word.substr(1));
			else children[c]->insert(word.substr(1));
		}
	}


	bool search(string word) {
		if(word.length() == 0) return isWord;

		char c = word[0] - 'a';
		if(!children[c]) return false;
		else return children[c]->search(word.substr(1));
	}


	bool startsWith(string prefix) {
		if(prefix.length() == 0) return true;

		char c = prefix[0] - 'a';
		if(!children[c]) return false;
		else return children[c]->startsWith(prefix.substr(1));
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

int main(int argc, char const* argv[])
{
	Trie trie = Trie();
	trie.insert("apple");
	cout << trie.search("apple") << endl;   // return True
	cout << trie.search("app") << endl;     // return False
	cout << trie.startsWith("app") << endl; // return True
	trie.insert("app");
	cout << trie.search("app") << endl;     // return True
	return 0;
}
