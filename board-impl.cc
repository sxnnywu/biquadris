module board;
// implements Board class
using namespace std;

// other classes use this to view board and not modify it, used for display
const array<array<Cell, 11>, 18> &Board::getCells() const { return cells; }

// checks if all 4 cells of the block fit on the board
bool Board::fits(const Block &b) const {
  for (const auto &p : b.getCoordinates()) {

    // check if the position is outside the board
    if (p.row < 0 || p.row >= 18 ||
        p.col < 0 || p.col >= 11) {
      return false;
    }

    // check if another block already occupies this cell
    if (cells[p.row][p.col].type != ' ') {
      return false;
    }
  }

  // true when all 4 cells are within the board and aren't occupied
  return true;
}
