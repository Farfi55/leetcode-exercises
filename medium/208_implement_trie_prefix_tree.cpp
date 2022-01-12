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
	bool is_word = false;


public:
	~Trie() {
		for(Trie*& node : children)
			if(node)
				delete node;
	}

	Trie() {}

	Trie(const Trie& trie) {
		is_word = trie.is_word;
		for(int i = 0; i < 26;i++)
			if(trie.children[i])
				children[i] = new Trie(*trie.children[i]);
	}

	Trie operator=(const Trie& trie) {
		is_word = trie.is_word;
		for(int i = 0; i < 26;i++) {
			if(children[i])
				delete children[i];
			if(trie.children[i])
				children[i] = new Trie(*trie.children[i]);
			else children[i] = nullptr;
		}
		return *this;
	}

	void insert(string word) {
		Trie* curr_node = this;

		for(int i = 0; i < word.length(); i++) {
			char c = word[i] - 'a';
			if(!curr_node->children[c])
				curr_node->children[c] = new Trie();
			curr_node = curr_node->children[c];
		}
		curr_node->is_word = true;
	}


	bool search(string word) {
		Trie* curr_node = this;

		for(int i = 0; i < word.length(); i++) {
			char c = word[i] - 'a';
			if(!curr_node->children[c])
				return false;

			curr_node = curr_node->children[c];
		}
		return curr_node->is_word;
	}


	bool startsWith(string prefix) {
		Trie* curr_node = this;

		for(int i = 0; i < prefix.length(); i++) {
			char c = prefix[i] - 'a';
			if(!curr_node->children[c])
				return false;

			curr_node = curr_node->children[c];
		}
		return true;
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

int main()
{
	{
		Trie trie = Trie();
		trie.insert("apple");
		trie.insert("pie");
		cout << trie.search("apple") << endl;   // return True
		cout << trie.search("app") << endl;     // return False
		cout << trie.startsWith("app") << endl; // return True
		trie.insert("app");
		cout << trie.search("app") << endl;     // return True
	}
	cout << "i dont know\n";
	return 0;
}
