// block class, stores coordinates and original difficulty level
// contains functions for creating and manipulating blocks
export module block;

import <array>;
import types;
using namespace std;

export class Block {
    BlockType type;
    array<Position, 4> coordinates;
    int generationLevel;

public:
    // creates a block in the first place
    static Block create(BlockType t, int level);

    // accessors
    BlockType getType() const;
    const array<Position, 4>& getCoordinates() const;
    int getGenerationLevel() const;
};
