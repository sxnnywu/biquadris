module block;
// implements block class

using namespace std;

// creates a block at its starting position on the board
Block Block::create(BlockType t, int level) {
    Block b{};

    b.type = t;
    b.generationLevel = level;

    if (t == BlockType::I) {
        b.coordinates = {
            Position{3, 0}, Position{3, 1},
            Position{3, 2}, Position{3, 3}
        };
    } else if (t == BlockType::J) {
        b.coordinates = {
            Position{2, 0}, Position{3, 0},
            Position{3, 1}, Position{3, 2}
        };
    } else if (t == BlockType::L) {
        b.coordinates = {
            Position{2, 2}, Position{3, 0},
            Position{3, 1}, Position{3, 2}
        };
    } else if (t == BlockType::O) {
        b.coordinates = {
            Position{2, 0}, Position{2, 1},
            Position{3, 0}, Position{3, 1}
        };
    } else if (t == BlockType::S) {
        b.coordinates = {
            Position{2, 1}, Position{2, 2},
            Position{3, 0}, Position{3, 1}
        };
    } else if (t == BlockType::Z) {
        b.coordinates = {
            Position{2, 0}, Position{2, 1},
            Position{3, 1}, Position{3, 2}
        };
    } else if (t == BlockType::T) {
        b.coordinates = {
            Position{2, 0}, Position{2, 1},
            Position{2, 2}, Position{3, 1}
        };
    }

    return b;
}

// returns the block's type
BlockType Block::getType() const {
    return type;
}

// returns the coordinates
const array<Position, 4>& Block::getCoordinates() const {
    return coordinates;
}

// returns the level the block was originally generated at
int Block::getGenerationLevel() const {
    return generationLevel;
}
