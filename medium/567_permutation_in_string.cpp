// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem567.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

/*
	a: 	0
	b: 	1
	c: 	2
	d: 	3
	e: 	4
	f: 	5
	g: 	6
	h: 	7
	i: 	8
	j: 	9
	k: 	10
	l: 	11
	m: 	12
	n: 	13
	o: 	14
	p: 	15
	q: 	16
	r: 	17
	s: 	18
	t: 	19
	u: 	20
	v: 	21
	w: 	22
	y: 	23
	x: 	24
	z: 	25
*/

// @lc code=start
class Solution {
public:
	bool checkInclusion(string s, string text) {
		const int n = text.length(); // big string
		const int m = s.length(); // small string to get permutations

		if(n < m) return false;

		int s_letters[26] = { 0 };
		int text_letters[26] = { 0 };


		//first pass
		for(int i = 0; i < m - 1; i++) {
			s_letters[s[i] - 'a']++;
			text_letters[text[i] - 'a']++;
		}

		// last letter is added only to s1_letters because
		// for s2 it is handled inside of the for loop
		s_letters[s[m - 1] - 'a']++;


		for(int i = 0; i <= n - m; i++) {
			text_letters[text[i + m - 1] - 'a']++;

			bool contains_permutation = true;
			for(int j = 0; j < 26 && contains_permutation; j++) {
				if(text_letters[j] != s_letters[j])
					contains_permutation = false;
			}
			if(contains_permutation) return true;

			text_letters[text[i] - 'a']--;
		}
		return false;

	}
};
// @lc code=end

