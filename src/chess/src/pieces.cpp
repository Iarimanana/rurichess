//
// Created by marshallmallow on 5/27/26.
//
#include "../include/pieces.h"

#include <stdexcept>

using namespace rurichess;

Pieces::Pieces() : Pieces(PieceNames::Wpawn) {}

Pieces::Pieces(const PieceNames name)
    : name_{kPIECES_REPRESENTATIONS_ARRAY[static_cast<Int32>(name)]} {
  const auto name_32 = static_cast<Int32>(name) + 1;
  suit_ = (name_32 % 2 == 0) ? Color::Black : Color::White;
  position_ = BitBoard(kPIECES_POSITIONS_ARRAY[name_32]);
}

Pieces::Pieces(const Int32 name) : name_{kPIECES_REPRESENTATIONS_ARRAY[name]} {
  if (name >= kPIECE_ARRAY_LEN)
    throw std::invalid_argument("The name of the piece is invalid.");

  suit_ = ((name + 1) % 2 == 0) ? Color::Black : Color::White;
  position_ = BitBoard(kPIECES_POSITIONS_ARRAY[name]);
}

Pieces& Pieces::operator=(const Pieces& other) {
  if (this != &other) {
    this->name_ = other.name_;
    this->position_ = other.position_;
    this->suit_ = other.suit_;
  }
  return *this;
}

BitBoard& Pieces::position() { return position_; }

char Pieces::name() const { return name_; }

Color Pieces::suit() const { return suit_; }