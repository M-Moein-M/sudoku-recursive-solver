class Validator {
    public:
        Validator(std::string b[9]) {
            board = b;
        }
        int isValid(int row, int col, int val);
    private:
        std::string *board;
        bool checkRows();
        bool useNumber(char *used, int boardVal);
        int row, col, val;
};

int Validator::isValid(int r, int c, int v) {
    row = r;
    col = c;
    val = v;
    return int(checkRows());
}

bool Validator::useNumber(char *used, int boardVal) {
    int numVal = boardVal - '0';
    if (numVal == 0)
        return true;
    else if (used[numVal] != 1)
        return false;
    used[numVal] = 1;
    return true;
}

bool Validator::checkRows(){
    board[row][col] = val; // fake inserting the value
    for (int i = 0; i < 9; i++) {
        char *used = (char*)calloc(10, sizeof(char));
        for (int j = 0; j < 9; j++){
            bool usedOnce = useNumber(used, board[i][j]);
            if (!usedOnce)
                return false;
        }
    }
    board[row][col] = 0; // undo inserting the value
    return true;
}

