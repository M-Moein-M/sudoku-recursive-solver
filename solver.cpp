class Solver {
    public:
        Solver() {}
        int solve() {
            std::cout << "Running solver" << std::endl;
            readBoard();
            return 0;
        }
    
    private:
        std::string board[9];
        void readBoard() {
            std::ifstream boardfile("board.txt");
            for (int i=0; i<9; i++){
                getline(boardfile, board[i]);
                std::cout<< "line " << i << " " << board[i] << std::endl;
            }
            boardfile.close();
        }
};

