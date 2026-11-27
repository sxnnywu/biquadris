module board;
// implements Board class
using namespace std;

// other classes use this to view board and not modify it, used for display
const array<array<Cell, 11>, 18> &Board::getCells() const { return cells; }
