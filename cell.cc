export module cell;
// represents an individual cell on the board
// it stores the block type and ID of the block

// struct is public, allowing board to access it directly
// only needs two pieces of information
export struct Cell {
  char type = ' ';
  // valid placed block IDs will start at 1, empty cell starts at -1
  int blockId = -1;
};
