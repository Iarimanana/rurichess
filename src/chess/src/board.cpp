//
// Created by marshallmallow on 5/25/26.
//

#include "../include/board.h"

#include <ranges>

#include "../include/pieces.h"

Board::Board() {
  initial_position = BitBoard(0xffff00000000ffff);
  for (const UInt8 i : std::views::iota(0, NUM_PIECES)) {
    board_[i] = Pieces(i);
  }
}

void Board::PrintBoard() const {
  std::array<std::string, NUM_SQUARES> output;
  output.fill(".");
  for (Pieces p : board_) {
    const Int32 position = GetPiecePosition(p);
    output[position] = p.GetName();
  }
}

Int32 Board::GetPiecePosition(const Pieces& p) {
  return  p.GetPosition().CountToZero();
}