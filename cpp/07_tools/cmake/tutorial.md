## CMake Getting Started

A minimal guide showing the required directory structure, files, and CLI commands to build a simple C++ project using CMake.

---

## Project Structure

**Folders and files:**
- **MyProject/**
  - **CMakeLists.txt** — CMake configuration file  
  - **src/**
    - **main.cpp** — your C++ source file  
  - **build/** — empty directory for out-of-source builds  

    MyProject/
    ├─ CMakeLists.txt
    ├─ src/
    │  └─ main.cpp
    └─ build/

---

## src/main.cpp

**File:** `src/main.cpp`

    #include <iostream>
    
    int main() {
        std::cout << "Hello from CMake project\n";
        return 0;
    }

---

## CMakeLists.txt

**File:** `CMakeLists.txt` (in project root)

    cmake_minimum_required(VERSION 3.16)
    
    project(MyProject LANGUAGES CXX)
    
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    
    add_executable(MyProject
        src/main.cpp
    )

---

## Building the Project (CLI)

From the **project root**:

**1. Enter the build directory**

    cd build

**2. Configure the project**

    cmake ..

**3. Build the project**

    cmake --build .

---

## Running the Executable

**Linux/macOS:**

    ./MyProject

**Windows:**

    MyProject.exe

---

## Adding More Source Files

**Example structure:**

    src/
    ├─ main.cpp
    ├─ utils.cpp
    └─ utils.h

**Update `CMakeLists.txt`:**

    add_executable(MyProject
        src/main.cpp
        src/utils.cpp
    )
