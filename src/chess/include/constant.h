//
// Created by marshallmallow on 5/25/26.
//

#ifndef RURICHESS_CONSTANT_H
#define RURICHESS_CONSTANT_H

#include <array>

#include "types.h"

namespace rurichess {

inline UInt64 kZero = 0x0000000000000000;
inline UInt64 kMaxUInt64 = 0xffffffffffffffff;
inline int kSizeBoard = 64;

inline constexpr Int32 kNumPieces = 32;
inline constexpr Int32 kNumSquares = 64;

enum class Color : UInt8 { Black, White };

enum class PieceNames : Int32 {
  Wpawn,
  Bpawn,
  Wrook,
  Brook,
  Wknight,
  Bknight,
  Wbishop,
  Bbishop,
  Wqueen,
  Bqueen,
  Wking,
  Bking
};

enum class SquareNames : Int32 {
  a8,
  b8,
  c8,
  d8,
  e8,
  f8,
  g8,
  h8,
  a7,
  b7,
  c7,
  d7,
  e7,
  f7,
  g7,
  h7,
  a6,
  b6,
  c6,
  d6,
  e6,
  f6,
  g6,
  h6,
  a5,
  b5,
  c5,
  d5,
  e5,
  f5,
  g5,
  h5,
  a4,
  b4,
  c4,
  d4,
  e4,
  f4,
  g4,
  h4,
  a3,
  b3,
  c3,
  d3,
  e3,
  f3,
  g3,
  h3,
  a2,
  b2,
  c2,
  d2,
  e2,
  f2,
  g2,
  h2,
  a1,
  b1,
  c1,
  d1,
  e1,
  f1,
  g1,
  h1
};

}  // namespace rurichess

#endif  // RURICHESS_CONSTANT_H
