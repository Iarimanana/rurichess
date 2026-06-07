def print_bitboard(b):
    b = bin(b)[2:].zfill(64)

    print("\n      A B C D E F G H ")
    print("    __________________ ")

    for i in range(8):
        temp = [' ', 8 - i, "|"] + [*(b[-8:])[::-1]]

        temp = [i if i != '0' else '·' for i in temp]

        print(*temp, sep=" ")
        b = b[:-8]


def generate_rook_moves(moves: list[int]) -> None:
    base_rank = 0xFF
    base_file = 0x0101010101010101

    for sq in range(64):
        rank = sq // 8
        file = sq % 8

        rank_mask = base_rank << (rank * 8)
        file_mask = base_file << file

        attacks = rank_mask | file_mask

        attacks = attacks ^ (1 << sq)

        moves.append(attacks)


def generate_bishop_moves(moves: list[int]):
    for sq in range(64):
        attacks = 0
        rank = sq // 8
        file = sq % 8

        directions = [
            (-1, -1),
            (-1, 1),
            (1, -1),
            (1, 1)
        ]

        for dr, df in directions:
            r, f = rank + dr, file + df

            while 0 <= r < 8 and 0 <= f < 8:
                target_sq = r * 8 + f
                attacks |= (1 << target_sq)

                r += dr
                f += df

        moves.append(attacks)


def main() -> None:
    moves = []
    generate_bishop_moves(moves)
    hex_moves = [hex(m) for m in moves]
    for m in moves:
        print(f"0x{m:x},")
        # print_bitboard(m)


if __name__ == '__main__':
    main()
