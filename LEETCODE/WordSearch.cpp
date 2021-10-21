class Solution {
private:
int row =0;
	int col =0;
	int index = 0;
	int len = 0;

	bool wordExist(vector<vector<char>>& board, string& word, vector<vector<bool>>& visited, int i, int j) {
		if ( board[i][j] == word[index] ){
visited[i][j] = true;
			index += 1;
			if (index >= len) return true;
			if (i+1 < row && visited[i+1][j] == false){
if (wordExist(board, word, visited, i+1, j)) return true; 
}
if (j+1 < col && visited[i][j+1] == false){
if (wordExist(board, word, visited, i, j+1)) return true; 
}
if (i-1 >=0 && visited[i-1][j] == false){
if (wordExist(board, word, visited, i-1, j)) return true; 
}
if (j-1 >= 0 && visited[i][j-1] == false){
if (wordExist(board, word, visited, i, j-1)) return true; 
}
visited[i][j] = false;
		index -= 1;
		}

return false;		
}

public:
    bool exist(vector<vector<char>>& board, string word) {
        	row = board.size();
	col = board[0].size();
	len = word.length();
	vector<vector<bool>> visited(row, vector<bool>(col, false));

	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++) {
			if (wordExist(board, word, visited, i, j)) return true; 
		} 
	}
	return false;
    }
};


