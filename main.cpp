#include <iostream>
#include <fstream>

#include "validator.cpp"
#include "solver.cpp"

int main(){
    Solver s;
    s.solve();
    s.printBoard();
    return 0;
}
