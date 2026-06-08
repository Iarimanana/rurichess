//
// Created by marshallmallow on 5/27/26.
//
#include "../include/pieces.h"

#include <stdexcept>

#include "constant.h"

using namespace rurichess;

Piece::Piece() : Piece(PieceNames::Wpawn) {}

Piece::Piece(const PieceNames name)
    : name_{kPiecesRepresentationsArray[static_cast<I32>(name)]} {
  const auto n = static_cast<I32>(name);
  color_ = ((n + 1) % 2 == 0) ? Color::Black : Color::White;
  position_ = BitBoard(kPiecesPositionsArray[n]);
}

Piece::Piece(const I32 name) : name_{kPiecesRepresentationsArray[name]} {
  if (name >= kPieceArrayLen)
    throw std::invalid_argument("The name of the piece is invalid.");

  color_ = ((name + 1) % 2 == 0) ? Color::Black : Color::White;
  position_ = BitBoard(kPiecesPositionsArray[name]);
}

Piece& Piece::operator=(const Piece& other) noexcept {
  if (this == &other) return *this;

  position_ = other.position_;
  name_ = other.name_;
  color_ = other.color_;

  return *this;
}

BitBoard& Piece::position() { return position_; }

const BitBoard& Piece::position() const { return position_; }

char Piece::name() const { return name_; }

Color Piece::color() const { return color_; }