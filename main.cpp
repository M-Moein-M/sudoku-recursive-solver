#include <iostream>
#include <fstream>

#include "validator.cpp"
#include "solver.cpp"

int main(){
    Solver s;
    bool solved = s.solve();
    if (solved)
        s.printBoard();
    else
        std::cout << "This board can't be solved" << std::endl;
    return 0;
}
