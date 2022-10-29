 class Solution {
 private:
 	int res_;
 	bool check(vector<string>& board, int row, int col, int n){
 		for(int i = 0; i < n; ++i){
 			if(board[row][i] == 'Q') return false;
 			if(board[i][col] == 'Q') return false;
 		}
 		int tx = row, ty = col;
 		while(tx >= 0 && ty >= 0) if(board[tx--][ty--] == 'Q') return false;
 		while(row >= 0 && col < n) if(board[row--][col++] == 'Q') return false;
 		return true;
 	}
 	void dfs(vector<string>& board, int row, int n){
 		if(row == n) res_++;
 		else{
 			for(int i = 0; i < n; ++i){
 				if(check(board, row, i, n)){
 					board[row][i] = 'Q';
 					dfs(board, row + 1, n);
 					board[row][i] = '.';
 				}
 			}
 		}
 	}
 public:
 	int totalNQueens(int n) {
 		res_ = 0;
 		string line = "";
 		for(int i = 0; i < n; ++i) line += ".";
 		vector<string> temp(n, line);
 		dfs(temp, 0, n);
 		return res_;
 	}
 };
