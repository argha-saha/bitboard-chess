#include "Validator.h"

bool Validator::isValidMove(const Board& board, const Move& move) {
    int from = move.getFromTile();
    int to = move.getToTile();

    // Bounds check
    if (from < 0 || from > 63 || to < 0 || to > 63) {
        return false;
    }

    // Same tile
    if (from == to) {
        return false;
    }

    Color movingColor = board.getPieceColor(from);
    Type pieceType = board.getPieceType(from);

    // Checks if piece exists and turn is correct
    if (movingColor != board.getTurn()) {
        return false;
    }

    // Destination tile can't be same color
    Color toColor = board.getPieceColor(to);

    if (toColor == movingColor) {
        return false;
    }

    // Get file/rank of source and destination
    int fromFile = Board::getFile(from);
    int fromRank = Board::getRank(from);
    int toFile = Board::getFile(to);
    int toRank = Board::getRank(to);

    // Calculate changes in file and rank
    int dFile = toFile - fromFile;
    int dRank = toRank - fromRank;

    bool whiteTurn = (movingColor == Color::WHITE);

    if (whiteTurn) {
        // Pawn logic
        if (pieceType == Type::PAWN) {
            // Forward moves (single or double step)
            if (dFile == 0 && dRank > 0) {
                // Check if destination is empty
                if (!board.isTileEmpty(to)) {
                    return false;
                }
                
                // For double step, also check if the tile in between is empty
                if (dRank == 2 && (!board.isTileEmpty(from + 8) || fromRank != 1)) {
                    return false;
                }
                
                return Pawn::canMoveToTile(dFile, dRank, true);
            }
            
            // Diagonal captures
            if (std::abs(dFile) == 1 && dRank == 1) {
                // Check if destination has an enemy piece
                if (board.isTileEmpty(to) || board.getPieceColor(to) == Color::WHITE) {
                    return false;
                }
                
                return Pawn::canMoveToTile(dFile, dRank, true);
            }
            
            return false;
        }
    } else {
        // Black piece logic
        if (pieceType == Type::PAWN) {
            // Forward moves (single or double step)
            if (dFile == 0 && dRank < 0) {
                // Check if destination is empty
                if (!board.isTileEmpty(to)) {
                    return false;
                }
                
                // For double step, also check if the tile in between is empty
                if (dRank == -2 && (!board.isTileEmpty(from - 8) || fromRank != 6)) {
                    return false;
                }
                
                return Pawn::canMoveToTile(dFile, dRank, false);
            }
            
            // Diagonal captures
            if (std::abs(dFile) == 1 && dRank == -1) {
                // Check if destination has an enemy piece
                if (board.isTileEmpty(to) || board.getPieceColor(to) == Color::BLACK) {
                    return false;
                }
                
                return Pawn::canMoveToTile(dFile, dRank, false);
            }
            
            return false;
        }
    }

    // Knight logic
    if (pieceType == Type::KNIGHT) {
        return Knight::canMoveToTile(dFile, dRank);
    }

    // Bishop logic
    if (pieceType == Type::BISHOP) {
        return Bishop::canMoveToTile(dFile, dRank) && isPathClear(board, fromFile, fromRank, toFile, toRank);
    }

    // Rook logic
    if (pieceType == Type::ROOK) {
        return Rook::canMoveToTile(dFile, dRank) && isPathClear(board, fromFile, fromRank, toFile, toRank);
    }

    // Queen logic
    if (pieceType == Type::QUEEN) {
        return Queen::canMoveToTile(dFile, dRank) && isPathClear(board, fromFile, fromRank, toFile, toRank);
    }

    // King logic
    if (pieceType == Type::KING) {
        // Check for castling
        if (dRank == 0 && std::abs(dFile) == 2) {
            // Castling conditions:
            // 1. King hasn't moved
            // 2. Appropriate rook hasn't moved
            // 3. No pieces between king and rook
            // 4. King is not in check
            // 5. King doesn't pass through check

            bool isKingside = (dFile == 2);  // Moving towards h-file
            int rookFile = isKingside ? 7 : 0;
            int rookRank = whiteTurn ? 0 : 7;
            int rookFrom = rookRank * 8 + rookFile;

            // Check if king and rook have moved
            if (whiteTurn) {
                if (board.hasWhiteKingMoved()) return false;
                if (isKingside && board.hasWhiteKingSideRookMoved()) return false;
                if (!isKingside && board.hasWhiteQueenSideRookMoved()) return false;
            } else {
                if (board.hasBlackKingMoved()) return false;
                if (isKingside && board.hasBlackKingSideRookMoved()) return false;
                if (!isKingside && board.hasBlackQueenSideRookMoved()) return false;
            }

            // Check if rook is present
            if (whiteTurn && !(board.getWhiteRooks() & (1ULL << rookFrom))) return false;
            if (!whiteTurn && !(board.getBlackRooks() & (1ULL << rookFrom))) return false;

            // Check if path is clear
            if (!isPathClear(board, fromFile, fromRank, rookFile, rookRank)) return false;

            // Check if king is in check
            if (isUnderThreat(board, from, !whiteTurn)) return false;

            // Check if king passes through check
            int throughSquare = from + (isKingside ? 1 : -1);
            if (isUnderThreat(board, throughSquare, !whiteTurn)) return false;

            // Check if destination square is under attack
            if (isUnderThreat(board, to, !whiteTurn)) return false;

            return true;
        }

        // Normal king move
        if (!King::canMoveToTile(dFile, dRank)) return false;

        // Ensure destination square is not under attack
        if (isUnderThreat(board, to, !whiteTurn)) return false;

        return true;
    }

    return false;
}

bool Validator::isPathClear(
    const Board& board,
    int fromFile, int fromRank,
    int toFile, int toRank
) {
    int dFile = 0;
    int dRank = 0;

    // Determine direction
    if (toFile > fromFile) {
        dFile = 1;
    } else if (toFile < fromFile) {
        dFile = -1;
    }

    if (toRank > fromRank) {
        dRank = 1;
    } else if (toRank < fromRank) {
        dRank = -1;
    }

    int currentFile = fromFile + dFile;
    int currentRank = fromRank + dRank;

    // Path
    while (currentFile != toFile || currentRank != toRank) {
        int index = currentRank * 8 + currentFile;

        if (!board.isTileEmpty(index)) {
            return false;
        }

        currentFile += dFile;
        currentRank += dRank;
    }

    return true;
}

bool Validator::isUnderThreat(const Board& board, int tile, bool byWhite) {
    int targetFile = Board::getFile(tile);
    int targetRank = Board::getRank(tile);
    
    // Check for pawn threats
    // White pawns attack upward, black pawns attack downward
    int pawnRankOffset = byWhite ? -1 : 1;
    
    for (int fileOffset : {-1, 1}) {
        int attackFile = targetFile + fileOffset;
        int attackRank = targetRank + pawnRankOffset;
        
        if (attackFile >= 0 && attackFile < 8 && attackRank >= 0 && attackRank < 8) {
            int attackTile = attackRank * 8 + attackFile;
            U64 pawnMask = 1ULL << attackTile;

            if (byWhite) {
                if (board.getWhitePawns() & pawnMask) {
                    return true;
                }
            } else {
                if (board.getBlackPawns() & pawnMask) {
                    return true;
                }
            }
        }
    }
    
    // Check for knight threats
    const int knightOffsets[8][2] = {
        {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
        {1, -2}, {1, 2}, {2, -1}, {2, 1}
    };
    
    for (const auto& offset : knightOffsets) {
        int attackFile = targetFile + offset[0];
        int attackRank = targetRank + offset[1];
        
        if (attackFile >= 0 && attackFile < 8 && attackRank >= 0 && attackRank < 8) {
            int attackTile = attackRank * 8 + attackFile;
            U64 knightMask = 1ULL << attackTile;

            if (byWhite) {
                if (board.getWhiteKnights() & knightMask) {
                    return true;
                }
            } else {
                if (board.getBlackKnights() & knightMask) {
                    return true;
                }
            }
        }
    }
    
    // Check for king threats
    const int kingOffsets[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
        {0, 1}, {1, -1}, {1, 0}, {1, 1}
    };
    
    for (const auto& offset : kingOffsets) {
        int attackFile = targetFile + offset[0];
        int attackRank = targetRank + offset[1];
        
        if (attackFile >= 0 && attackFile < 8 && attackRank >= 0 && attackRank < 8) {
            int attackTile = attackRank * 8 + attackFile;
            U64 kingMask = 1ULL << attackTile;

            if (byWhite) {
                if (board.getWhiteKing() & kingMask) {
                    return true;
                }
            } else {
                if (board.getBlackKing() & kingMask) {
                    return true;
                }
            }
        }
    }
    
    // Check for sliding piece threats
    // Used for queen, rook, bishop
    const int directions[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
        {0, 1}, {1, -1}, {1, 0}, {1, 1}
    };
    
    for (const auto& dir : directions) {
        int attackFile = targetFile + dir[0];
        int attackRank = targetRank + dir[1];
        
        while (attackFile >= 0 && attackFile < 8 && attackRank >= 0 && attackRank < 8) {
            int attackTile = attackRank * 8 + attackFile;
            U64 attackMask = 1ULL << attackTile;
            
            // If we hit any piece, check if it's a threatening piece
            if (!board.isTileEmpty(attackTile)) {
                bool isStraight = dir[0] == 0 || dir[1] == 0;
                bool isDiagonal = dir[0] != 0 && dir[1] != 0;
                
                if (byWhite) {
                    if ((board.getWhiteQueens() & attackMask) ||
                        (isStraight && (board.getWhiteRooks() & attackMask)) ||
                        (isDiagonal && (board.getWhiteBishops() & attackMask))) {
                        return true;
                    }
                } else {
                    if ((board.getBlackQueens() & attackMask) ||
                        (isStraight && (board.getBlackRooks() & attackMask)) ||
                        (isDiagonal && (board.getBlackBishops() & attackMask))) {
                        return true;
                    }
                }

                // Stop checking this direction if we hit any piece
                break;
            }
            
            attackFile += dir[0];
            attackRank += dir[1];
        }
    }
    
    return false;
}

bool Validator::isInCheck(const Board& board, bool whiteKing) {
    // Find the king's position
    U64 kingBitboard = whiteKing ? board.getWhiteKing() : board.getBlackKing();

    // Get the position of the least significant 1 bit
    // Prevent undefined behavior for ctzll if kingBitboard is 0
    if (kingBitboard == 0) {
        return false;
    }

    int kingTile = __builtin_ctzll(kingBitboard);
    
    // Check if the king's position is under threat by enemy pieces
    return isUnderThreat(board, kingTile, !whiteKing);
}

bool Validator::hasLegalMoves(const Board &board, bool forWhite) {
    // Collect all pieces for the given color
    U64 pieces = board.getOccupancy(forWhite);
    Board tempBoard;

    while (pieces) {
        int fromTile = __builtin_ctzll(pieces);

        // Clear the least significant bit
        pieces &= pieces - 1;

        for (int toTile = 0; toTile < 64; ++toTile) {
            // TODO: Might need to adjust this to work for all promotions
            Move move(fromTile, toTile, '\0');
            
            if (isValidMove(board, move)) {
                tempBoard = board;
                tempBoard.movePiece(fromTile, toTile);

                if (!isInCheck(tempBoard, forWhite)) {
                    return true;
                }
            }
        }
    }

    return false;
}

bool Validator::isCheckmate(const Board &board, bool whiteTurn) {
    // Checkmate occurs when the king is in check and there are no legal moves available
    return isInCheck(board, whiteTurn) && !hasLegalMoves(board, whiteTurn);
}

bool Validator::isStalemate(const Board &board, bool whiteTurn) {
    // King is not in check but there are no legal moves available
    return !isInCheck(board, whiteTurn) && !hasLegalMoves(board, whiteTurn);
}