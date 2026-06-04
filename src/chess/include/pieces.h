//
// Created by marshallmallow on 5/27/26.
//

#ifndef RURICHESS_PIECES_H
#define RURICHESS_PIECES_H

#include "bitboard.h"
#include "constant.h"
#include "types.h"

namespace rurichess {

inline constexpr Int32 kPieceArrayLen = 12;

inline constexpr std::array<UInt64, kPieceArrayLen> kPiecesPositionsArray = {
    0xff00, 0xff000000000000,   0x81, 0x8100000000000000,
    0x42,   0x4200000000000000, 0x24, 0x2400000000000000,
    0x8,    0x800000000000000,  0x10, 0x1000000000000000,
};

inline constexpr std::array kPiecesRepresentationsArray = {
    'P', 'p', 'R', 'r', 'N', 'n', 'B', 'b', 'Q', 'q', 'K', 'k'};

class Piece {
 public:
  explicit Piece(PieceNames name);
  explicit Piece(Int32 name);
  Piece();
  Piece(const Piece& other) = default;
  Piece& operator=(Piece other) noexcept;

  [[nodiscard]] BitBoard& position();
  [[nodiscard]] const BitBoard& position() const;
  [[nodiscard]] char name() const;
  [[nodiscard]] Color suit() const;

 private:
  BitBoard position_;
  char name_;
  Color suit_;
};

}  // namespace rurichess

#endif  // RURICHESS_PIECES_H