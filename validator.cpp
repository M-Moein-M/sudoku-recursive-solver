class Validator {
    public:
        Validator(std::string b[9]) {
            board = b;
        }
        bool isValid();
    private:
        std::string *board;
        bool useNumber(char *, int);
        bool checkRows();
        char NoSegFault;  // removing this results in segfault ???
};

bool Validator::isValid() {
    return checkRows();
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

bool Validator::checkRows(){
    for (int i = 0; i < 9; i++) {
        char *used = (char*)calloc(10, sizeof(char));
        for (int j = 0; j < 9; j++){
            bool usedOnce = useNumber(used, board[i][j]);
            if (!usedOnce)
                return false;
        }
    }
    return true;
}

