//
// Created by marshallmallow on 6/7/26.
//

#include "piece_movement/utils.h"

#include <ranges>

#include "piece_movement/bishop.h"
#include "piece_movement/rook.h"

using namespace rurichess;

void GenerateRookMoves() {
  for (I32 i = 32; BitBoard& b : kRookAttacks) {
    b = BitBoard(kU64RookMoves[i]);
    i++;
  }
}

void GenerateBishopMoves() {
  for (I32 i = 0; BitBoard& b : kBishopMoves) {
    b = BitBoard(kU64BishopMoves[i]);
    i++;
  }
}

U64 MagicIndex(const MagicEntry& entry, const BitBoard& blockers) {
  const BitBoard masked_blockers = entry.mask & blockers;
  const BitBoard hash = masked_blockers * entry.magic;
  return (hash >> (kNumSquares - entry.index_bits)).bit_board();
}