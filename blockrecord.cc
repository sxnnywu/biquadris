export module blockrecord;
// stores the original difficulty level of a placed block
// and tracks how many of those block's cells remain on the board

export struct BlockRecord {
  // difficulty level block was originally
  int generationLevel = 0;
  // how many cells from the block remain on the board
  int remainingCells = 0;
};
