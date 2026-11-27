import <iostream>;
import <array>;
import cell;
import board;
using namespace std;

int main() {
  Board b;
  const auto &cells = b.getCells();

  if (cells.size() != 18) {
    cout << "FAIL: Incorrect number of rows." << endl;
    return 1;
  }

  cout << "PASS: Board has 18 rows." << endl;

  for (const auto &row : cells) {
    if (row.size() != 11) {
      cout << "FAIL: Incorrect number of columns." << endl;
      return 1;
    }
  }

  cout << "PASS: All rows have 11 columns." << endl;

  for (const auto &row : cells) {
    for (const auto &cell : row) {
      if (cell.type != ' ' || cell.blockId != -1) {
        cout << "FAIL: Cell is not initialized correctly." << endl;
        return 1;
      }
    }
  }

  cout << "PASS: All cells are empty." << endl;
  cout << "All board tests passed." << endl;

  return 0;
}
