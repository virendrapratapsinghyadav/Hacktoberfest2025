class Solution {

public:
    bool search(vector<vector<char>>& board, string word, int i,
                int j, int index) {

                    if(word.size()>board.size()*board[0].size())return false;
        if (index == word.size())
            return true;

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            board[i][j] != word[index])
            return false;

        char temp = board[i][j];
        board[i][j] = '#';

        bool found = (search(board, word, i + 1, j, index + 1) ||
                      search(board, word, i - 1, j, index + 1) ||
                      search(board, word, i, j + 1, index + 1) ||
                      search(board, word, i, j-1, index + 1));

        board[i][j] = temp;
        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
         for(int i =0; i<row; i++){
            for(int j=0; j<col; j++){
                if( search(board, word, i, j, 0)) return true;
            }
         }
         return false;
    }
};
