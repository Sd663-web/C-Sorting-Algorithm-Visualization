# C-Sorting-Algorithm-Visualization
A C++ sorting visualizer using WinBGIm to display Bubble Sort and Selection Sort as animated vertical bars. Both algorithms run in parallel threads for real-time comparison, making it a simple and effective educational tool to understand sorting through graphical animation.



📊 C++ Sorting Visualization (Bubble Sort & Selection Sort)

A high-performance C++ sorting visualizer demonstrating the internal operations of Bubble Sort and Selection Sort using the WinBGIm graphics library.
This project renders real-time animations for both algorithms, executing them in parallel threads to provide a direct visual and performance comparison under identical input conditions.

🚀 Features
🔹 Real-Time Sorting Animation

Each array element is represented as a vertical bar.

Bars dynamically change positions during swaps.

Graphical updates occur on every comparison and swap.

🔹 Dual-Window Visualization

Bubble Sort and Selection Sort run in separate graphics windows.

Independent rendering pipelines for each algorithm.

🔹 Multithreaded Execution

Uses std::thread to execute two sorting algorithms simultaneously.

Accurate performance measurement using std::chrono.

🔹 Technical Rendering

Based entirely on WinBGIm (Windows BGI).

No GPU, OpenGL, or DirectX required.

Lightweight CPU-based graphical rendering.

🔹 Configurable Visualization

Adjustable array size

Custom bar gap, animation speed, and rendering behavior

🛠️ Tech Stack
Component	Description
Language	C++ (C++11 threads)
Graphics Library	WinBGIm (graphics.h)
Build Tools	MinGW/GCC, VS Code
Concurrency	std::thread, std::chrono
Algorithms	Bubble Sort, Selection Sort
📂 Project Structure
sorting-visualizer/
│
├── quick_sort.cpp         # Main source file
├── graphics.h             # WinBGIm header
├── libbgi.a               # WinBGIm library
├── README.md              # Project documentation
└── assets/                # Screenshots (optional)

⚙️ Installation & Setup
1. Install MinGW (GCC)

Download MinGW:

https://sourceforge.net/projects/mingw/


Install:

gcc

g++

mingw32-gcc-g++

mingw32-base

Add MinGW bin/ to PATH.

2. Add WinBGIm to MinGW

Place these files inside:

C:\mingw\include\graphics.h
C:\mingw\lib\libbgi.a

3. Configure VS Code Build Task

tasks.json example:

{
    "version": "2.0.0",
    "tasks": [
        {
            "type": "cppbuild",
            "label": "C/C++: g++.exe build active file",
            "command": "C:\\MinGW\\bin\\g++.exe",
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                "${file}",
                "-o",
                "${fileDirname}\\${fileBasenameNoExtension}.exe",
                "-lbgi",
                "-lgdi32",
                "-lcomdlg32",
                "-luuid",
                "-loleaut32",
                "-lole32"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "compiler: C:\\MinGW\\bin\\g++.exe"
        }
    ]
}

▶️ Running the Program
Method 1: From VS Code

Press:

Ctrl + Shift + B


Then run:

./visualizer.exe

Method 2: From Terminal
g++ main.cpp -o visualizer.exe -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
visualizer.exe

🧠 How It Works (Technical Overview)
1. Data Representation

An integer array of sizeN elements is generated and shuffled.

Each element corresponds to a bar drawn using:

line(x, height, x, height - value);

2. Rendering Pipeline

Rendering is handled using WinBGIm's CPU-based line drawing.

Double-buffer effect created manually by clearing + redrawing per frame.

3. Multithreading Architecture
[Thread 1] → Bubble Sort → Window A
[Thread 2] → Selection Sort → Window B


Threads execute:

thread t1(bubbleSortGraphics, winBubble);
thread t2(selectionSortGraphics, winSelect);

4. Performance Measurement

Execution time computed using:

auto start = chrono::high_resolution_clock::now();
auto end = chrono::high_resolution_clock::now();

🧪 Algorithms Included
1. Bubble Sort

Compares adjacent elements.

Swaps on every mis-order.

O(n²) worst-case.

2. Selection Sort

Locates minimum element in each iteration.

Swaps at end of each outer loop.

O(n²) comparisons, fewer swaps than Bubble Sort.

📈 Future Enhancements

Add Quick Sort, Merge Sort, Heap Sort

FPS counter & adjustable speed slider

Color-coded comparisons, swaps, pivots

UI panel for algorithm selection

Audio feedback on swaps (beep tones)

📜 License

This project is released under the MIT License.

👨‍💻 Author

Soumyajit Dalal
B.Tech CSE • C++ Developer • Graphics & Algorithm Enthusiast
