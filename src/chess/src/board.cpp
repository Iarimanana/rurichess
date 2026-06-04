//
// Created by marshallmallow on 5/25/26.
//

#include "../include/board.h"

#include <iostream>
#include <ranges>

#include "../include/pieces.h"
#include "constant.h"

using namespace rurichess;

Board::Board()
    : initial_position_{BitBoard(kInitialPosition)},
      whites_{BitBoard(kWhitePosition)},
      blacks_{BitBoard(kBlackPosition)} {
  for (const Int32 i : std::views::iota(0, kPieceArrayLen))
    board_[i] = Piece(i);
}

Int32 Board::Move(Piece p, std::string square) { return 0; }

const BitBoard& Board::whites() const { return whites_; }

const BitBoard& Board::blacks() const { return blacks_; }

void Board::PrintBoard() const {
  const std::array<Piece, kPieceArrayLen> tmp = board_;
  std::array<std::string, kNumSquares> output;
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
  for (Int32 i = 0; i < kSizeBoard; i++) {
    if (i % 8 == 0) std::cout << "\n" << (i / 8) + 1 << " | ";
    std::cout << output[i];
  }
}