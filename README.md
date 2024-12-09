# so_long

**so_long** is a 2D game project developed as part of the 42 curriculum. Inspired by classic arcade games, it challenges players to navigate a maze, collect items, and overcome obstacles.

---

## Features

- Grid-based 2D graphics.
- Player-controlled navigation.
- Collectibles and exit mechanics.
- Custom map support.

---

## Technologies Used

- **Language**: C
- **Library**: MiniLibX (MLX) for graphics and window management.
- **Build Tool**: Makefile
- **Operating Systems**: Linux and macOS

---

## How to Run

### Prerequisites

- **C compiler**: `gcc` or `clang`
- **Make utility**
- **MiniLibX library**

### Steps

1. Clone the repository:
   ```bash
   git clone https://github.com/raniiyya/42so_long.git
   cd 42so_long
2. Compile the program
   ```bash
   make
3. Run the game with the map file
   ```bash
   ./so_long maps/example_map.ber

---

## Controls

- **W**: Move up  
- **A**: Move left  
- **S**: Move down  
- **D**: Move right

---

## Gameplay Mechanics

#### 1. Collect All Coins
The player must collect all coins (C) before the exit (E) becomes accessible.
#### 2. Avoid Monsters
The map may include monsters (M). Stepping on a tile occupied by a monster results in a loss.
#### 3. Win Condition
The player wins by collecting all coins and successfully reaching the exit (E).
#### 4. Custom Maps
Users can create their own .ber files. See the Map Format for details.

---

## Map Format

Maps are `.ber` files and must follow these rules:

- **`1`**: Wall  
- **`0`**: Empty space  
- **`P`**: Player start position (1 required)  
- **`C`**: Collectibles (At least 1 required)  
- **`E`**: Exit (1 required)  
- **`M`**: Monster (Optional, adds difficulty)  

### Example Map:

```bash
11111
1P0C1
1M0E1
11111
```

### Map Requirements:
- Maps must be rectangular.  
- Surrounded by walls (`1`) on all sides.  
- At least one player start (`P`), one collectible (`C`), and one exit (`E`).  
- No gaps or irregular shapes.  

---

## License

This project is for educational purposes under the 42 Network. Redistribution is prohibited without prior authorization.


![so_long](https://github.com/user-attachments/assets/30d6542b-f68c-47b0-a2ea-9646f982e09a)
