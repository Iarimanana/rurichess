//
// Created by marshallmallow on 5/27/26.
//

#ifndef RURICHESS_PIECES_H
#define RURICHESS_PIECES_H

#include <array>
#include <string>

#include "bitboard.h"
#include "types.h"

namespace rurichess {

inline constexpr Int32 kPIECE_ARRAY_LEN = 12;
inline constexpr UInt64 kBLACK_POSITION = 0xffff000000000000;
inline constexpr UInt64 kWHITE_POSITION = 0xffff;

enum class Color : UInt8 { Black, White };

inline std::array<UInt64, kPIECE_ARRAY_LEN> kPIECES_POSITIONS_ARRAY = {
    0xff00, 0xff000000000000,   0x81, 0x8100000000000000,
    0x42,   0x4200000000000000, 0x24, 0x2400000000000000,
    0x8,    0x800000000000000,  0x10, 0x1000000000000000,
};

inline std::array kPIECES_REPRESENTATIONS_ARRAY = {
    'P', 'p', 'R', 'r', 'N', 'n', 'B', 'b', 'Q', 'q', 'K', 'k'};

enum class PieceNames : UInt8 {
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

class Pieces {
 public:
  explicit Pieces(PieceNames name);
  explicit Pieces(Int32 name);
  Pieces();
  Pieces(const Pieces& other) = default;
  Pieces& operator=(const Pieces& other);
  // TODO: BitBoard movement() const;

  [[nodiscard]] BitBoard& position();
  [[nodiscard]] char name() const;
  [[nodiscard]] Color suit() const;

 private:
  BitBoard position_;
  char name_;
  Color suit_;
};

}  // namespace rurichess

#endif  // RURICHESS_PIECES_H