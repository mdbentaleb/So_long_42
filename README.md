# So_Long - 42 Network Project

<img width="1612" alt="Image" src="https://github.com/user-attachments/assets/83a4ed5f-0814-401f-b363-e35112141e9f" />

So_Long is a project from the 42 Network where the goal is to create a 2D game using the MiniLibX library. The game features a player that can move through a maze and collect items, with the objective of reaching the exit. This project reinforces understanding of graphical programming, event handling, and memory management.

🚀 **Features**  
- 2D maze with a player character that can move using the keyboard.  
- Collectible items and a goal to reach an exit.  
- Interactive graphics rendered using MiniLibX.  
- Game mechanics like collision detection and player movement.  

🛠️ **Getting Started**

**Prerequisites**  
To get started, ensure you have the following installed:
- A C compiler like `gcc` or `clang`
- `make` for building the project
- A UNIX-like operating system (Linux/macOS/WSL)

### 1. Clone the Repository
```bash
 git clone https://github.com/mdbentaleb/Push_swap_42
```
```bash
 cd So_long_42
```

### 2. Compile the Project
After cloning the repository, you can compile and run the game using the following commands:

- **To compile and run the game with the mandatory features:**
  1. Compile the project:
     ```bash
     make
     ```
  2. Run the game with a map:
     ```bash
     ./so_long maps/map.ber
     ```

- **To compile and run the game with bonus features (e.g., including enemies):**
  1. Compile the project with bonus features:
     ```bash
     make bonus
     ```
  2. Run the game with a map:
     ```bash
     ./so_long_bonus maps/map.ber
     ```

This setup allows you to choose between the mandatory version and the bonus version of the game.

### 4. Clean Up
To remove the compiled files:
```bash
 make clean
```