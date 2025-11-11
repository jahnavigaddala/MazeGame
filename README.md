# 🎮 Maze Runner Game  

## 📌 Project Overview  
This project is a **C++-based Maze Runner Game**, developed as part of an **Object-Oriented Programming (OOP) course project**. It incorporates key OOP principles such as **encapsulation, abstraction, operator overloading, and function composition**, while delivering an engaging maze-solving experience. The game supports **real-time user interaction**, dynamic memory management, and a **scalable modular design**, making it an ideal foundation for future expansions.  

## 📂 Key Features  
✔ **Modular Class-Based Architecture**: Implemented separate classes (**Game, Maze, and Position**) for **scalability and maintainability**.  
✔ **Real-Time Feedback**: Uses `getch()` from `<conio.h>` to capture **instant user input**, enhancing interactivity.  
✔ **Advanced Gameplay Mechanics**: **Function Pointers** for dynamic player movement, **Operator Overloading** for seamless position manipulation, and **Static Storage** to track total games played.  
✔ **Dynamic Memory Allocation**: Efficiently manages the maze grid, player position, and level data at runtime.  
✔ **Persistent High Score Tracking**: Saves and retrieves best moves from `bestmoves.txt` to encourage player improvement.  
✔ **Comprehensive Game Analytics**: Displays **move count, elapsed time, and level progression** in real-time.  

## 🖥️ Technologies Used  
**C++ (OOP, STL)** | **File Handling (`fstream`)** | **Time Management (`ctime`)** | **Dynamic Memory (`new/delete`)**  

## 🚀 How to Run  
Clone the Repository:  
```bash
git clone https://github.com/SriAshritha/Maze-Game.git
cd Maze-Game
```

## 🎮 Game Description  

- The game **tracks and displays valid moves**, counting only **successful moves** toward the total allowed moves for each level.  
- After each successful move, the **elapsed time** since the game started is displayed, helping players **track their progress and pace**.  
- The game provides **comprehensive statistics**, including:  
  - **Total moves taken** across all levels.  
  - **Real-time level-specific stats** for performance tracking.  

### 🏆 Win & Lose Conditions  
- If the player **exceeds the maximum move limit** without reaching the goal, the game displays:  
  > **"You were lost in the maze."**  
  The level then **resets**, allowing the player to try again.  
- Successfully completing a level **within the allowed moves** rewards the player with a **congratulatory message** and progression to the next level.  

### 📈 Best Moves Tracking  
- If a player achieves a **new record for minimal moves**, the **best moves** are **saved in `bestmoves.txt`**, preserving achievements for future reference.  
- This system ensures **real-time feedback** and a **clear sense of progression**, making gameplay **engaging and immersive**.  


## Compile the Code:
``` bash
g++ -o maze_runner Main.cpp Game.cpp Maze.cpp Position.cpp Game.h Maze.h Position.h  -std=c++11
```

## Run the Game:
``` bash
./maze_runner
```

## 📊 Gameplay Instructions  
- Navigate the maze using **W (Up), A (Left), S (Down), D (Right)**.  
- Reach the goal **within the move limit** to progress to the next level.  
- If the move limit is exceeded, the level resets.  
- The game **tracks best moves** and updates records in `bestmoves.txt`.  

## 📈 Results & Insights  
✔ **Optimized Game Architecture**: Modular OOP approach for **easy expansion** and **feature integration**.  
✔ **Real-Time User Interaction**: Captures **instant player input** for a smooth, engaging experience.  
✔ **Efficient Memory Management**: Uses **dynamic memory allocation** for **scalable maze generation**.  
✔ **High Replayability**: Implements **persistent best move tracking**, motivating players to improve performance.  
✔ **Structured Codebase**: Implements **encapsulation, function pointers, and operator overloading** for maintainability.  

## 📬 Contact  
For inquiries, reach out via:  
🔗 **LinkedIn**: [Jahnavi Gaddala](https://www.linkedin.com/in/jahnavii-g/)  

