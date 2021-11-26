class Solver {
    public:
        Solver() {
            std::cout << "Initiating Solver" << std::endl;
            readBoard();
            
            Validator v(board);
            validator = &v;
        }
        int solve();
        void printBoard();
    private:
        void readBoard();
        std::string board[9];
        bool getEmptyCord(int *row, int *col);
        Validator *validator;
};

void Solver::printBoard() {
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++)
            std::cout << board[i][j] << ' ';
        std::cout << std::endl;
    }
}
bool Solver::getEmptyCord(int *row, int *col) {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (board[i][j] == '0') {
                *row = i;
                *col = j;
                return true;
            }
    return false;
}

int Solver::solve() {
    int row, col;
    bool isNotSolved = getEmptyCord(&row, &col);
    if (isNotSolved) {
        for (int i=1; i<=9; i++){
            board[row][col] = '0'+i;
            bool isValidNum = validator->isValid() && solve();
            if (isValidNum)
                return 1;
        }
        board[row][col] = '0';
        return 0;
    } 
    return 1;
}

void Solver::readBoard() {
    std::ifstream boardfile("board.txt");
    for (int i=0; i<9; i++){
        getline(boardfile, board[i]);
        std::cout<< "line " << i << " " << board[i] << std::endl;
    }
    boardfile.close();
}

