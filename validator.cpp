class Validator {
    public:
        Validator(std::string b[9]) {
            board = b;
        }
        int isValid(int row, int col, int val);
    private:
        std::string *board;
        bool checkRows();
        int row, col, val;
};

int Validator::isValid(int r, int c, int v) {
    row = r;
    col = c;
    val = v;
    return int(checkRows());
}

bool Validator::checkRows(){
    board[row][col] = val; // fake inserting the value
    for (int i = 0; i < 9; i++) {
        char *used = (char*)calloc(10, sizeof(char));
        for (int j = 0; j < 9; j++){
            int numVal = board[i][j] - '0';
            if (numVal == 0)
                continue;
            else if (used[numVal] != 0)
                return false;
            else
                used[numVal] = 1;
        }
    }
    board[row][col] = 0; // undo inserting the value
    return true;
}

