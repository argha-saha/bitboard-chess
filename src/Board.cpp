#include "Board.h"

Board::Board() {
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