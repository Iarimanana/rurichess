//
// Created by marshallmallow on 5/27/26.
//

#ifndef RURICHESS_PIECES_H
#define RURICHESS_PIECES_H

#include <array>

#include "bitboard.h"
#include "types.h"

namespace rurichess {

inline constexpr Int32 kPIECE_ARRAY_LEN = 12;
inline constexpr UInt64 kBLACK_POSITION = 0xffff000000000000;
inline constexpr UInt64 kWHITE_POSITION = 0xffff;

extern const std::array<UInt64, kPIECE_ARRAY_LEN> kPIECES_POSITIONS_ARRAY;
extern const std::array<char, kPIECE_ARRAY_LEN> kPIECES_REPRESENTATIONS_ARRAY;

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

class Piece {
 public:
  explicit Piece(PieceNames name);
  explicit Piece(Int32 name);
  Piece();
  Piece(const Piece& other) = default;
  Piece& operator=(Piece other) noexcept;
  // TODO: BitBoard movement() const;

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