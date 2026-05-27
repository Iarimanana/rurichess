//
// Created by marshallmallow on 5/27/26.
//

#include "../include/pieces.h"

Pieces::Pieces() : Pieces(PieceNames::Wpawn) {}

Pieces::Pieces(const PieceNames name)
    : name_ { kPIECE_REPRESENTATION[static_cast<UInt8>(name)] } {
  const auto name_uint8 = static_cast<UInt8>(name);
  suit_ = (name_uint8 % 2 == 0) ? Color::Black : Color::White;
  position_ = BitBoard(kPIECES_POSITION[name_uint8]);
}

Pieces::Pieces(const UInt8 name)
    : name_ { kPIECE_REPRESENTATION[name] } {
  suit_ = (name % 2 == 0) ? Color::Black : Color::White;
  position_ = BitBoard(kPIECES_POSITION[name]);
}

Pieces& Pieces::operator=(const Pieces& other) {
  if (this != &other) {
    this->name_ = other.name_;
    this->position_ = other.position_;
    this->suit_ = other.suit_;
  }
  return *this;
}

BitBoard Pieces::GetPosition() const { return position_; }

std::string Pieces::GetName() const { return name_; }

Color Pieces::GetSuit() const { return suit_; }