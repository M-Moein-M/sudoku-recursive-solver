class Solver {
    public:
        Solver() {}
        int solve(); 
    private:
        void readBoard();
        std::string board[9];
        Validator *validator;
};

int Solver::solve() {
    std::cout << "Running solver" << std::endl;
    readBoard();
    
    Validator v(board);
    validator = &v;
    
    return 0;
}

void Solver::readBoard() {
    std::ifstream boardfile("board.txt");
    for (int i=0; i<9; i++){
        getline(boardfile, board[i]);
        std::cout<< "line " << i << " " << board[i] << std::endl;
    }
    boardfile.close();
}

