export module types;
// shared data types used across classes

// row and column of the cell on the board
export struct Position {
  int row;
  int col;
};

// all 7 possible shapes
export enum class BlockType { I, J, L, O, S, Z, T };
