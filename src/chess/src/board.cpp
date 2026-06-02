//
// Created by marshallmallow on 5/25/26.
//

#include "../include/board.h"

#include <iostream>
#include <ranges>

#include "../include/pieces.h"
#include "constant.h"

using namespace rurichess;

Board::Board() : board_{} {
  initial_position = BitBoard(0xffff00000000ffff);
  for (const Int32 i : std::views::iota(0, kPIECE_ARRAY_LEN))
    board_[i] = Piece(i);
}

void Board::PrintBoard() const {
  const std::array<Piece, kPIECE_ARRAY_LEN> tmp = board_;
  std::array<std::string, kNUM_SQUARES> output;
  output.fill(std::string("."));

  for (Piece p : tmp) {
    BitBoard& b = p.position();
    while (b != 0) {
      const Int32 position = b.CountTrailingZero();
      output[position] = p.name();
      b.RemoveBit(position);
    }
  }

  std::cout << "    ABCDEFGH\n";
  std::cout << "    --------";
  for (Int32 i = 0; i < SIZE_BOARD; i++) {
    if (i % 8 == 0) std::cout << "\n" << (i / 8) + 1 << " | ";
    std::cout << output[i];
  }
}