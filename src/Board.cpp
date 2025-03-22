#include "Board.h"

Board::Board() {
    initBoard();
}

void Board::initBoard() {
    whitePawns   = 0x000000000000FF00ULL;
    whiteKnights = 0x0000000000000042ULL;
    whiteBishops = 0x0000000000000024ULL;
    whiteRooks   = 0x0000000000000081ULL;
    whiteQueens  = 0x0000000000000008ULL;
    whiteKing    = 0x0000000000000010ULL;
    blackPawns   = 0x00FF000000000000ULL;
    blackKnights = 0x4200000000000000ULL;
    blackBishops = 0x2400000000000000ULL;
    blackRooks   = 0x8100000000000000ULL;
    blackQueens  = 0x0800000000000000ULL;
    blackKing    = 0x1000000000000000ULL;
    whiteKingMoved = false;
    whiteKingSideRookMoved = false;
    whiteQueenSideRookMoved = false;
    blackKingMoved = false;
    blackKingSideRookMoved = false;
    blackQueenSideRookMoved = false;
    turn = Color::WHITE;
}

U64 Board::getOccupancy() const {
    return (whitePawns | whiteKnights | whiteBishops |
            whiteRooks | whiteQueens | whiteKing |
            blackPawns | blackKnights | blackBishops |
            blackRooks | blackQueens | blackKing);
}

U64 Board::getOccupancy(bool white) const {
    if (white) {
        return (whitePawns | whiteKnights | whiteBishops |
                whiteRooks | whiteQueens | whiteKing);
    } else {
        return (blackPawns | blackKnights | blackBishops |
                blackRooks | blackQueens | blackKing);
    }
}

bool Board::isTileEmpty(int tile) const {
    U64 mask = (1ULL << tile);
    bool res = getOccupancy() & mask;
    return res == 0ULL;
}

Color Board::getPieceColor(int tile) const {
    U64 mask = (1ULL << tile);
    if (isWhite(tile)) return Color::WHITE;
    if (isBlack(tile)) return Color::BLACK;
    return Color::EMPTY;
}

bool Board::isWhite(int tile) const {
    U64 mask = (1ULL << tile);
    U64 white = (whitePawns | whiteKnights | whiteBishops | 
                 whiteRooks | whiteQueens | whiteKing) & mask;
    return white != 0ULL;
}

bool Board::isBlack(int tile) const {
    U64 mask = (1ULL << tile);
    U64 black = (blackPawns | blackKnights | blackBishops | 
                 blackRooks | blackQueens | blackKing) & mask;
    return black != 0ULL;
}

U64 Board::getWhitePawns() const {
    return whitePawns;
}

U64 Board::getWhiteKnights() const {
    return whiteKnights;
}

U64 Board::getWhiteBishops() const {
    return whiteBishops;
}

U64 Board::getWhiteRooks() const {
    return whiteRooks;
}

U64 Board::getWhiteQueens() const {
    return whiteQueens;
}

U64 Board::getWhiteKing() const {
    return whiteKing;
}

U64 Board::getBlackPawns() const {
    return blackPawns;
}

U64 Board::getBlackKnights() const {
    return blackKnights;
}

U64 Board::getBlackBishops() const {
    return blackBishops;
}

U64 Board::getBlackRooks() const {
    return blackRooks;
}

U64 Board::getBlackQueens() const {
    return blackQueens;
}

U64 Board::getBlackKing() const {
    return blackKing;
}

Color Board::getTurn() const {
    return turn;
}

Type Board::getPieceType(int tile) const {
    U64 mask = (1ULL << tile);
    if (whitePawns & mask) return Type::PAWN;
    if (whiteKnights & mask) return Type::KNIGHT;
    if (whiteBishops & mask) return Type::BISHOP;
    if (whiteRooks & mask) return Type::ROOK;
    if (whiteQueens & mask) return Type::QUEEN;
    if (whiteKing & mask) return Type::KING;
    if (blackPawns & mask) return Type::PAWN;
    if (blackKnights & mask) return Type::KNIGHT;
    if (blackBishops & mask) return Type::BISHOP;
    if (blackRooks & mask) return Type::ROOK;
    if (blackQueens & mask) return Type::QUEEN;
    if (blackKing & mask) return Type::KING;
    return Type::NONE;
}

bool Board::hasWhiteKingMoved() const {
    return whiteKingMoved;
}

bool Board::hasWhiteKingSideRookMoved() const {
    return whiteKingSideRookMoved;
}

bool Board::hasWhiteQueenSideRookMoved() const {
    return whiteQueenSideRookMoved;
}

bool Board::hasBlackKingMoved() const {
    return blackKingMoved;
}

bool Board::hasBlackKingSideRookMoved() const {
    return blackKingSideRookMoved;
}

bool Board::hasBlackQueenSideRookMoved() const {
    return blackQueenSideRookMoved;
}

void Board::setWhitePawns(U64 value) {
    whitePawns = value;
}

void Board::setWhiteKnights(U64 value) {
    whiteKnights = value;
}

void Board::setWhiteBishops(U64 value) {
    whiteBishops = value;
}
void Board::setWhiteRooks(U64 value) {
    whiteRooks = value;
}

void Board::setWhiteQueens(U64 value) {
    whiteQueens = value;
}

void Board::setWhiteKing(U64 value) {
    whiteKing = value;
}

void Board::setBlackPawns(U64 value) {
    blackPawns = value;
}

void Board::setBlackKnights(U64 value) {
    blackKnights = value;
}

void Board::setBlackBishops(U64 value) {
    blackBishops = value;
}

void Board::setBlackRooks(U64 value) {
    blackRooks = value;
}

void Board::setBlackQueens(U64 value) {
    blackQueens = value;
}

void Board::setBlackKing(U64 value) {
    blackKing = value;
}

void Board::setTurn(Color color) {
    turn = color;
}

void Board::switchTurn() {
    turn = (turn == Color::WHITE) ? Color::BLACK : Color::WHITE;
}

void Board::clearPiece(int tile) {
    U64 mask = ~(1ULL << tile);
    whitePawns &= mask;
    whiteKnights &= mask;
    whiteBishops &= mask;
    whiteRooks &= mask;
    whiteQueens &= mask;
    whiteKing &= mask;
    blackPawns &= mask;
    blackKnights &= mask;
    blackBishops &= mask;
    blackRooks &= mask;
    blackQueens &= mask;
    blackKing &= mask;
}

void Board::clearBoard() {
    whitePawns = 0ULL;
    whiteKnights = 0ULL;
    whiteBishops = 0ULL;
    whiteRooks = 0ULL;
    whiteQueens = 0ULL;
    whiteKing = 0ULL;
    blackPawns = 0ULL;
    blackKnights = 0ULL;
    blackBishops = 0ULL;
    blackRooks = 0ULL;
    blackQueens = 0ULL;
    blackKing = 0ULL;
}

int Board::getFile(int tile) {
    return tile % 8;
}

int Board::getRank(int tile) {
    return tile / 8;
}

std::string Board::indexToTile(int index) {
    int file = getFile(index);
    int rank = getRank(index);

    std::string res;
    res.push_back(char('a' + file));
    res.push_back(char('1' + rank));

    return res;
}

int Board::tileToIndex(const std::string& tile) {
    if (tile.size() != 2) {
        return -1;
    }

    char file = static_cast<char>(std::tolower(static_cast<unsigned char>(tile[0])));
    char rank = tile[1];

    if (file < 'a' || file > 'h' || rank < '1' || rank > '8') {
        return -1;
    }

    int f = file - 'a';
    int r = rank - '1';

    return r * 8 + f;
}

void Board::movePiece(int fromTile, int toTile) {
    Type pieceType = getPieceType(fromTile);
    Color pieceColor = getPieceColor(fromTile);
    
    // Clear the destination tile first
    clearPiece(toTile);
    
    // Create masks for the move
    U64 fromMask = ~(1ULL << fromTile);
    U64 toMask = 1ULL << toTile;
    
    // Move the piece based on its type and color
    if (pieceColor == Color::WHITE) {
        switch (pieceType) {
            case Type::PAWN:
                whitePawns = (whitePawns & fromMask) | toMask;
                break;
            case Type::KNIGHT:
                whiteKnights = (whiteKnights & fromMask) | toMask;
                break;
            case Type::BISHOP:
                whiteBishops = (whiteBishops & fromMask) | toMask;
                break;
            case Type::ROOK:
                whiteRooks = (whiteRooks & fromMask) | toMask;
                
                // Update castling flags
                if (fromTile == 0) {
                    whiteQueenSideRookMoved = true; // a1
                }

                if (fromTile == 7) {
                    whiteKingSideRookMoved = true; // h1
                }

                break;
            case Type::QUEEN:
                whiteQueens = (whiteQueens & fromMask) | toMask;
                break;
            case Type::KING:
                whiteKing = (whiteKing & fromMask) | toMask;
                whiteKingMoved = true;
                
                // Handle castling
                if (fromTile == 4) {    // e1
                    if (toTile == 6) {  // g1 (kingside castle)
                        // Move the rook from h1 to f1
                        whiteRooks = (whiteRooks & ~(1ULL << 7)) | (1ULL << 5);
                        whiteKingSideRookMoved = true;
                    } else if (toTile == 2) {  // c1 (queenside castle)
                        // Move the rook from a1 to d1
                        whiteRooks = (whiteRooks & ~(1ULL << 0)) | (1ULL << 3);
                        whiteQueenSideRookMoved = true;
                    }
                }

                break;
            default:
                break;
        }
    } else {
        switch (pieceType) {
            case Type::PAWN:
                blackPawns = (blackPawns & fromMask) | toMask;
                break;
            case Type::KNIGHT:
                blackKnights = (blackKnights & fromMask) | toMask;
                break;
            case Type::BISHOP:
                blackBishops = (blackBishops & fromMask) | toMask;
                break;
            case Type::ROOK:
                blackRooks = (blackRooks & fromMask) | toMask;

                // Update castling flags
                if (fromTile == 56) {
                    blackQueenSideRookMoved = true; // a8
                }
                if (fromTile == 63) {
                    blackKingSideRookMoved = true; // h8
                }

                break;
            case Type::QUEEN:
                blackQueens = (blackQueens & fromMask) | toMask;
                break;
            case Type::KING:
                blackKing = (blackKing & fromMask) | toMask;
                blackKingMoved = true;
                
                // Handle castling
                if (fromTile == 60) {    // e8
                    if (toTile == 62) {  // g8 (kingside castle)
                        // Move the rook from h8 to f8
                        blackRooks = (blackRooks & ~(1ULL << 63)) | (1ULL << 61);
                        blackKingSideRookMoved = true;
                    } else if (toTile == 58) {  // c8 (queenside castle)
                        // Move the rook from a8 to d8
                        blackRooks = (blackRooks & ~(1ULL << 56)) | (1ULL << 59);
                        blackQueenSideRookMoved = true;
                    }
                }

                break;
            default:
                break;
        }
    }
    
    // Switch turns
    switchTurn();
}