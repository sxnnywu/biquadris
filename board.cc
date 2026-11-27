export module board;
// defines the board class, which stores the playing area
// and declares functions for movements, detecting collisions,
// rotations, placements, clearing rows

import <array>;
import <map>;
import cell;
import blockrecord;
using namespace std;

export class Board {
  // array of 18 rows, each row with 11 Cells
  array<array<Cell, 11>, 18> cells{};
  // creates empty map, then each placed Block's ID will
  // be associated with its blockrecord
  map<int, BlockRecord> records;
  // when block is placed, its assigned this ID
  // which will be incremented so a new block gets a unique ID
  int nextBlockId = 1;

 public:
  // other classes use this to view board and not modify it, used for display
  // not in the UML, since its an accessor
  const array<array<Cell, 11>, 18> &getCells() const;
};
