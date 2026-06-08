//
// Created by marshallmallow on 6/7/26.
//

#ifndef RURICHESS_UTILS_H
#define RURICHESS_UTILS_H

#include <tuple>
#include <vector>

#include "bitboard.h"
#include "pieces.h"

namespace rurichess {

/**
 *
 */
class MagicEntry {
 public:
  BitBoard mask{};
  U64 magic{};
  U8 index_bits{};
};

void GenerateRookMoves();
void GenerateBishopMoves();

U32 MagicIndex(const MagicEntry& entry, const BitBoard& blockers);

std::tuple<MagicEntry, std::vector<BitBoard>> FindMagic(const Piece& piece,
                                                        Square square,
                                                        U8 index_bits);

std::vector<BitBoard> MakeTable(const Piece& piece, Square square,
                                const MagicEntry& magic_entry);

}  // namespace rurichess

#endif  // RURICHESS_UTILS_H
