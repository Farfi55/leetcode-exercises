/*
* @lc app=leetcode id=1905 lang=java
*
* [1905] Count Sub Islands
*/

// @lc code=start
public class Solution {
	// porco dio java non ha i tipi unsigned
	public boolean bfs(int[][] grid1, int[][] grid2, int i, int j) {
		if (i < 0 || j < 0 || i >= grid1.length || j >= grid1[0].length || grid2[i][j] == 0)
			return true;

		// trasformo la terra in mare così da evitare di ripetere il calcolo
		// per la stessa
		grid2[i][j] = 0;

		// uso il bitwise & per accettarmi che vengano settati a 0
		// tutti i punti dell'isola
		// che essa sia sub-isola o meno
		return ((grid1[i][j] == 0) &
				(bfs(grid1, grid2, i + 1, j)) &
				(bfs(grid1, grid2, i - 1, j)) &
				(bfs(grid1, grid2, i, j + 1)) &
				(bfs(grid1, grid2, i, j - 1)));
	}

	public int countSubIslands(int[][] grid1, int[][] grid2) {
		int m = grid1.length;
		int n = grid1[0].length;

		int counter = 0;

		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (grid1[i][j] == 1 && grid2[i][j] == 1)
					if (bfs(grid1, grid2, i, j))
						counter++;

		return counter;

	}

	 public static void main(String[] args) {
		 int[][] grid1 =
		 {{1,1,1,0,0},{0,1,1,1,1},{0,0,0,0,0},{1,0,0,0,0},{1,1,0,1,1}};

		 int[][] grid2 =
		 {{1,1,1,0,0},{0,0,1,1,1},{0,1,0,0,0},{1,0,1,1,0},{0,1,0,1,0}};

		 var sol = new Solution();
		 var out = sol.countSubIslands(grid1, grid2);
		 System.out.println(out);
	 }
};
// @lc code=end
