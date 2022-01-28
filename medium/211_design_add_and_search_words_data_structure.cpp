/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class WordDictionary {
	WordDictionary* children[26] = { 0 };
	bool is_word = false;


public:
	~WordDictionary() {
		for(WordDictionary*& node : children)
			if(node)
				delete node;
	}

	WordDictionary() {}


	void addWord(string word) {
		WordDictionary* curr_node = this;

		for(int i = 0; i < word.length(); i++) {
			char c = word[i] - 'a';
			if(!curr_node->children[c])
				curr_node->children[c] = new WordDictionary();
			curr_node = curr_node->children[c];
		}
		curr_node->is_word = true;
	}


	bool search(string word) {
		WordDictionary* curr_node = this;

		for(int i = 0; i < word.length(); i++) {
			if(word[i] == '.') {
				for(char c = 0; c < 26; c++) {
					if(curr_node->children[c]) {
						auto tmp = curr_node->children[c];
						if(tmp->search(word.substr(i + 1)))
							return true;
					}
				}
				return false;
			}
			else {
				char c = word[i] - 'a';
				if(!curr_node->children[c])
					return false;

				curr_node = curr_node->children[c];
			}
		}
		return curr_node->is_word;
	}
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

