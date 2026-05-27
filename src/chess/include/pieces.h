//
// Created by marshallmallow on 5/27/26.
//

#ifndef RURICHESS_PIECES_H
#define RURICHESS_PIECES_H

#include <array>
#include <string>

#include "bitboard.h"
#include "types.h"

inline std::array<UInt64, 64> kPIECES_POSITION = {
  0xff000000000000, 0xff00,
  0x8100000000000000, 0x81,
  0x4200000000000000, 0x42,
  0x2400000000000000, 0x24,
  0x800000000000000, 0x8,
  0x1000000000000000, 0x10,
  0xffff000000000000, 0xffff,
};

inline std::array<std::string, 16> kPIECE_REPRESENTATION = {
  "P", "p", "R", "r", "N", "n",
  "B", "b", "Q", "q", "K", "k"
};

enum class PieceNames : UInt8 {
  Wpawn, Bpawn, Wrook, Brook, Wknight, Bknight,
  Wbishop, Bbishop, Wqueen, Bqueen, Wking, Bking
};

enum class Color : Int8 {
  Black, White
};

class Pieces {
public:
  explicit Pieces(PieceNames name);
  explicit Pieces(UInt8 name);
  Pieces();
  Pieces(const Pieces& other) = default;
  Pieces& operator=(Pieces const& other);
  // TODO: BitBoard movement() const;

  [[nodiscard]] BitBoard GetPosition() const;
  [[nodiscard]] std::string GetName() const;
  [[nodiscard]] Color GetSuit() const;

private:
  BitBoard position_;
  std::string& name_;
  Color suit_;
};

class Pawn : public Pieces {
public:
  using Pieces::Pieces;
};

class Rook : public Pieces {
public:
  using Pieces::Pieces;
};

class Knight : public Pieces {
public:
  using Pieces::Pieces;
};

class Bishop : public Pieces {
public:
  using Pieces::Pieces;
};

class Queen : public Pieces {
public:
  using Pieces::Pieces;
};

class King : public Pieces {
public:
  using Pieces::Pieces;
};

#endif  // RURICHESS_PIECES_H
