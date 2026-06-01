//
// Created by marshallmallow on 5/25/26.
//

#include "../include/board.h"

#include <ranges>

#include "../include/pieces.h"

using namespace rurichess;

Board::Board() : board_{} {
  initial_position = BitBoard(0xffff00000000ffff);
  for (const Int32 i : std::views::iota(0, kPIECE_ARRAY_LEN))
    board_[i] = Pieces(i);
}

void Board::PrintBoard() const {
  const std::array<Pieces, kPIECE_ARRAY_LEN> tmp = board_;
  std::array<std::string, kNUM_SQUARES> output;
  output.fill(std::string("."));

  for (Pieces p : tmp) {
    while (p.position() != 0) {
      const Int32 position = p.position().CountToZero();
      output[position] = p.name();
      p.position().RemoveBit(position);
    }
  }
}