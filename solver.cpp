class Solver {
    public:
        Solver() {
            std::cout << "Initiating Solver" << std::endl;
            readBoard();
            
            Validator v(board);
            validator = &v;
        }
        int solve(); 
    private:
        void readBoard();
        std::string board[9];
        Validator *validator;
};

int Solver::solve() {
    
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

