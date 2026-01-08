# Copilot Instructions for Conway's Game of Life

## Project Overview

A C++ implementation of Conway's Game of Life using **raylib 5.0.0** for rendering. The project is configured as a raylib desktop application targeting macOS, Linux, Windows, and other platforms.

## Architecture & Key Components

- **Single-file design**: Most logic currently in `src/main.cpp`
- **Raylib integration**: Window management, rendering loop, and graphics handled by raylib
- **Game loop pattern**: Update → Draw cycle executed while `!WindowShouldClose()`

## Build & Development Workflow

### Build Tasks (Makefile-based)

The Makefile is parameterized via command-line arguments:

```bash
# Debug build (with symbols)
make PROJECT_NAME=game OBJS=src/*.cpp BUILD_MODE=DEBUG

# Release build (optimized)
make PROJECT_NAME=game OBJS=src/*.cpp
```

VS Code tasks are configured in `tasks.json`:
- **"build debug"**: Compiles with debug symbols (`BUILD_MODE=DEBUG`)
- **"build release"**: Optimized build (default)

**Key parameters** in Makefile:
- `PROJECT_NAME`: Output executable name (default: `game`)
- `OBJS`: Object/source files to compile (default: `main.c`, override with `src/*.cpp`)
- `BUILD_MODE`: DEBUG or RELEASE (default: RELEASE)
- `PLATFORM`: PLATFORM_DESKTOP, PLATFORM_RPI, etc. (auto-detected)

### Development Setup

**Compiler**: Uses `clang`/`clang++` on macOS (configured in `.vscode/settings.json`)

**Raylib paths**: Configured in Makefile:
- Library: `$(RAYLIB_INSTALL_PATH)` (default: `/usr/local/lib`)
- Headers: `$(RAYLIB_H_INSTALL_PATH)` (default: `/usr/local/include`)

## Code Patterns & Conventions

### Raylib Game Loop Structure

```cpp
// Must precede game loop
InitWindow(screenWidth, screenHeight, "Title");
SetTargetFPS(60);

while (!WindowShouldClose()) {
    // Update game state
    ball.Update();
    
    // Render
    BeginDrawing();
        ClearBackground(darkGreen);
        ball.Draw();
    EndDrawing();
}

CloseWindow();
```

### Object Encapsulation

Objects like `ball` implement Update() and Draw() methods for clean separation of logic and rendering:
- `ball.Update()` handles physics/state changes
- `ball.Draw()` handles all raylib rendering calls

## Critical Dependencies

- **raylib 5.0.0**: Graphics/windowing library (installed system-wide or referenced in Makefile)
- **C++ standard library**: STL containers and utilities (referenced in workspace settings)

## Build Artifacts & Cleanup

- **Output**: `game.exe` (Windows), `game` (macOS/Linux)
- **Objects**: `.o` files (excluded from git via `.gitignore`)
- **Clean**: `make clean` removes build artifacts

## VS Code Configuration

**File associations** in workspace settings enable proper IntelliSense:
- `raylib.h` → treated as C
- STL headers (`vector`, `string`, `memory`) → C++

**Compiler warnings**: Strict warning flags enabled (`-Wall -Wextra -Wpedantic`, etc.) to catch issues early.
