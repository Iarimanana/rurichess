//
// Created by marshallmallow on 6/7/26.
//

#include "setup.h"

#include "piece_movement/utils.h"

Err rurichess::Setup() {
  GenerateBishopMoves();
  GenerateRookMoves();
  return Err::Success;
}