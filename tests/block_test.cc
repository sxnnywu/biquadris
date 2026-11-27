// tests creation, starting positions, shapes,
// types and generation difficulty levels of all seven blocks.

import <iostream>;
import <array>;
import <string>;
import types;
import block;

using namespace std;

bool checkBlock(BlockType type, string top, string bottom) {
  Block b = Block::create(type, 2);

  if (b.getType() != type) {
    return false;
  }

  if (b.getGenerationLevel() != 2) {
    return false;
  }

  bool actual[2][4]{};

  for (const auto &p : b.getCoordinates()) {
    // verify that the coordinate is inside the spawning area
    if (p.row < 2 || p.row > 3 || p.col < 0 || p.col > 3) {
      return false;
    }

    // Check for duplicate coordinates.
    if (actual[p.row - 2][p.col]) {
      return false;
    }

    actual[p.row - 2][p.col] = true;
  }

  // compare the actual block with its expected shape
  for (int col = 0; col < 4; ++col) {
    if (actual[0][col] != (top[col] == 'X')) {
      return false;
    }

    if (actual[1][col] != (bottom[col] == 'X')) {
      return false;
    }
  }

  return true;
}

int main() {
  if (!checkBlock(BlockType::I, "    ", "XXXX")) {
    cout << "FAIL: I-block" << endl;
    return 1;
  }
  cout << "PASS: I-block" << endl;

  if (!checkBlock(BlockType::J, "X   ", "XXX ")) {
    cout << "FAIL: J-block" << endl;
    return 1;
  }
  cout << "PASS: J-block" << endl;

  if (!checkBlock(BlockType::L, "  X ", "XXX ")) {
    cout << "FAIL: L-block" << endl;
    return 1;
  }
  cout << "PASS: L-block" << endl;

  if (!checkBlock(BlockType::O, "XX  ", "XX  ")) {
    cout << "FAIL: O-block" << endl;
    return 1;
  }
  cout << "PASS: O-block" << endl;

  if (!checkBlock(BlockType::S, " XX ", "XX  ")) {
    cout << "FAIL: S-block" << endl;
    return 1;
  }
  cout << "PASS: S-block" << endl;

  if (!checkBlock(BlockType::Z, "XX  ", " XX ")) {
    cout << "FAIL: Z-block" << endl;
    return 1;
  }
  cout << "PASS: Z-block" << endl;

  if (!checkBlock(BlockType::T, "XXX ", " X  ")) {
    cout << "FAIL: T-block" << endl;
    return 1;
  }
  cout << "PASS: T-block" << endl;

  cout << "All block creation tests passed." << endl;

  return 0;
}
