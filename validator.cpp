class Validator {
    public:
        Validator(std::string b[9]) {
            board = b;
        }
        bool isValid();
    private:
        std::string *board;
        bool useNumber(char *, int);
        bool checkRowOrCol(bool testRows);
        bool checkGrids();
        char NoSegFault;  // removing this results in segfault ???
};

bool Validator::isValid() {
    bool validCols = checkRowOrCol(false);
    bool validRows = checkRowOrCol(true);
    bool validGrids = checkGrids();
    return validCols && validRows && validGrids;
}

bool Validator::useNumber(char *used, int boardVal) {
    int numVal = boardVal - '0';
    if (numVal == 0)
        return true;
    else if (used[numVal] >= 1)
        return false;
    used[numVal] += 1;
    return true;
}

bool Validator::checkGrids() {
    for (int k=0; k<9; k++) {
        char *used = (char*)calloc(10, sizeof(char));
        for (int i=0; i<3; i++) 
            for (int j=0; j<3; j++) {
                bool usedOnce = useNumber(used, board[k/3*3+i][k%3*3+j]);
                if (!usedOnce)
                    return false;
            }
    }
    return true;
}

bool Validator::checkRowOrCol(bool testRows) {
    for (int j=0; j<9; j++) {
        char *used = (char*)calloc(10, sizeof(char));
        for (int i=0; i<9; i++){
            bool usedOnce = useNumber(
                used,
                testRows ? board[i][j] : board[j][i]);
            if (!usedOnce)
                return false;
        }
    }
    return true;
}
