// tests board dimensions, empty cells,
// starting positions and whether blocks fit on the board

import <iostream>;
import <array>;
import cell;
import types;
import block;
import board;

using namespace std;

int main() {
  Board b;
  const auto &cells = b.getCells();

  // check the number of rows
  if (cells.size() != 18) {
    cout << "FAIL: Incorrect number of rows." << endl;
    return 1;
  }

  cout << "PASS: Board has 18 rows." << endl;

  // check the number of columns in each row
  for (const auto &row : cells) {
    if (row.size() != 11) {
      cout << "FAIL: Incorrect number of columns." << endl;
      return 1;
    }
  }

  cout << "PASS: All rows have 11 columns." << endl;

  // check that every cell starts off empty
  for (const auto &row : cells) {
    for (const auto &cell : row) {
      if (cell.type != ' ' || cell.blockId != -1) {
        cout << "FAIL: Cell is not initialized correctly." << endl;
        return 1;
      }
    }
  }

  cout << "PASS: All cells are empty." << endl;

  // check that all 7 blocks fit at their starting positions
  if (!b.fits(Block::create(BlockType::I, 0)) ||
      !b.fits(Block::create(BlockType::J, 0)) ||
      !b.fits(Block::create(BlockType::L, 0)) ||
      !b.fits(Block::create(BlockType::O, 0)) ||
      !b.fits(Block::create(BlockType::S, 0)) ||
      !b.fits(Block::create(BlockType::Z, 0)) ||
      !b.fits(Block::create(BlockType::T, 0))) {
    cout << "FAIL: A block doesn't fit at its starting position." << endl;
    return 1;
  }

  cout << "PASS: All 7 blocks fit at their starting positions." << endl;

  // move a block outside the left side of the board
  Block left = Block::create(BlockType::I, 0);
  left.translate(Motion::Left);

  if (b.fits(left)) {
    cout << "FAIL: Block fits outside left boundary." << endl;
    return 1;
  }

  cout << "PASS: Left boundary detected." << endl;

  // move an I block to the right edge of the board
  Block right = Block::create(BlockType::I, 0);

  for (int i = 0; i < 7; ++i) {
    right.translate(Motion::Right);
  }

  if (!b.fits(right)) {
    cout << "FAIL: Block doesn't fit at right edge." << endl;
    return 1;
  }

  cout << "PASS: Block fits at right edge." << endl;

  // move one more position, now outside the board
  right.translate(Motion::Right);

  if (b.fits(right)) {
    cout << "FAIL: Block fits outside right boundary." << endl;
    return 1;
  }

  cout << "PASS: Right boundary detected." << endl;

  // move an I block from row 3 to row 17
  Block bottom = Block::create(BlockType::I, 0);

  for (int i = 0; i < 14; ++i) {
    bottom.translate(Motion::Down);
  }

  if (!b.fits(bottom)) {
    cout << "FAIL: Block doesn't fit at bottom edge." << endl;
    return 1;
  }

  cout << "PASS: Block fits at bottom edge." << endl;

  // move one more row, now outside the board
  bottom.translate(Motion::Down);

  if (b.fits(bottom)) {
    cout << "FAIL: Block fits outside bottom boundary." << endl;
    return 1;
  }

  cout << "PASS: Bottom boundary detected." << endl;

  cout << "All board tests passed." << endl;

  return 0;
}
