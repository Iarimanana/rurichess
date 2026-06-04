//
// Created by marshallmallow on 6/4/26.
//

#ifndef RURICHESS_PIECE_MOVEMENT_H
#define RURICHESS_PIECE_MOVEMENT_H

#include "pieces.h"

namespace rurichess {

bool CheckIllegalMove(PieceNames p, SquareNames initial_square,
                      const BitBoard& ending_square);

}  // namespace rurichess

#endif  // RURICHESS_PIECE_MOVEMENT_H
