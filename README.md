# 📍 Pathfinding Visualizer

A high-performance **C++/Qt** application designed to visualize pathfinding algorithms on an interactive grid. This tool provides a real-time look at how algorithms "think," featuring step-by-step execution, speed control, and automatic path reconstruction. The project is avaliable as desktop and web application (see [web version](#-web-version)).

> [!NOTE]
> This project is built using the Qt Framework. If you want to build it from source, ensure you have the proper kit configured in your IDE to compile and run the application. See [installation](#-installation).

---

## 🚀 Features

* **Step-by-Step Visualization:** Watch algorithms explore the grid in real-time (Dijkstra, A* for now).
* **Dynamic Controls:** Adjustable execution speed, plus the ability to pause and resume at any point.
* **Interactive Grid UI:** Easily place walls, set start/end points, and view visited nodes versus the final path.
* **Modular Design:** Clean separation between the core algorithm logic and the graphical interface.

---
## 🌐 Web Version

A web version of the **Pathfinding Visualizer** is available and built using **WebAssembly** with Qt.

This allows the application to run directly in the browser without requiring any installation.

### 🔧 Technology

* Qt 6 (Qt Quick / QML)
* WebAssembly (via Emscripten)
* CMake + Ninja

### 🚀 How it works

The project is compiled to WebAssembly using Qt's WebAssembly toolchain.
The output consists of:

* `app.html`
* `app.js`
* `app.wasm`

These files are deployed via GitHub Pages and can be accessed directly in the browser.

> [!NOTE]
> The WebAssembly build must be served over HTTP (not opened via `file://`), otherwise the application will not load due to browser security restrictions (CORS).

---

You can try the web version here:
👉 **https://detluck.github.io/pathfinding-visualizer/**

## 📦 Installation

### Option 1: Download Pre-built Binaries
You can skip the compilation process by downloading the latest stable version directly:
1. Go to the [Latest Release](https://github.com/detluck/pathfinding-visualizer/releases/latest) page.
2. **Windows:** Download the `PathfindingVisualizer-windows.zip`.
3. **macOS:** Download the `PathfindingVisualizer-macos.zip`.
> [!NOTE]
> The macOS pre-build was not tested, so it could be broken.

### Option 2: Build from Source (CMake)

Dependencies:

-   `qt6-declarative`
-   `gcc-libs`
-   `qt6-base`

Build dependencies:

-   [`cmake`](https://cmake.org)
-   [`ninja`](https://github.com/ninja-build/ninja)

To install the app manually, install all dependencies, then:

# 1. Clone this repo
```sh
git clone https://github.com/detluck/pathfinding-visualizer.git
cd pathfinding-visualizer
```

# 2. Create a build directory
```sh
mkdir build && cd build
```

# 3. Configure and build
```sh
cmake ..
cmake --build .
```

## 🛠️ Usage

* **Start / Resume:** Initiate the search or continue from a paused state.
* **Pause:** Temporarily halt the algorithm to inspect the current frontier.
* **Stop:** Terminate the current search and reset the grid to its initial state.
* **Speed Control:** Use the integrated slider to adjust the interval between steps for faster or more detailed viewing.
> [!NOTE]
> Setting the speed to the **maximal value ("Blazing Fast")** effectively removes the delay, solving the entire grid instantly in just a few milliseconds.

---

## 🔮 Future Improvements

* [ ] **Algorithm Expansion:** Add support for Breadth-First Search (BFS), and Depth-First Search (DFS).
* [ ] **Visual Polish:** Implement smooth path animations and transition effects.
* [ ] **Complex Grids:** Support for weighted edges (terrain costs) and advanced heuristic visualizations.
* [ ] **Travelling Salesperson Problem (TSP) Integration:** A major upcoming feature is the implementation of a multi-destination pathfinding mode, solving a grid-based version of the Travelling Salesperson Problem.
