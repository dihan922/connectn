# Connect-N

A text-based version of Connect-4, allowing users to customize the dimensions of the board and the number of pieces needed to win.

## Getting Started

Follow these instructions to get Connect-N running on your computer.

1. **Clone the Repository:**
    ```bash
    git clone https://github.com/dihan922/connectn
    cd connectn
    ```

2. **Build executable:**
    ```bash
    make
    ```

## Usage

1. **Start Program:**
    ```bash
    ./connectn.out <num_rows> <num_columns> <number_of_pieces_in_a_row_needed_to_win>
    ```

2. **Gameplay:**
    - Players take turns making a move by entering the index of the column to drop a piece in.
    - The game continues until one of the following conditions is met: a player achieves the specified number of pieces in a row and wins, or the board fills up, resulting in a tie.

## License

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT).
