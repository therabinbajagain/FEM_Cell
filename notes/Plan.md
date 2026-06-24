# FEM_Cell – Repository Setup Notes

## 1. Repository structure

The repository is organized as follows:

```text
FEM_Cell/
├── src/        # real FEM_Cell source code
├── include/    # header files for the real project
├── examples/   # C++ learning demos related to FEM / mechanics
├── tests/      # later: correctness tests
└── notes/      # learning notes and derivations
```

Folder roles:

* `src/` — actual project implementation
* `include/` — headers for project classes/functions
* `examples/` — small C++ and mechanics demos used for learning
* `tests/` — unit or validation tests
* `notes/` — setup notes, derivations, and development logs

---

## 2. Initial Git commands

To stage, commit, and push the initial repository structure:

```bash
git add .
git commit -m "Set up initial FEM project structure"
git push -u origin main
```

---

## 3. Command to print repository tree

To inspect the working directory tree while ignoring `.git/` and `build/`:

```bash
find . \
  -path ./.git -prune -o \
  -path ./build -prune -o \
  -print
```

---

## 4. Initial `CMakeLists.txt`

The top-level `CMakeLists.txt` should live in the repository root, not inside `src/`.

Example:

```cmake
cmake_minimum_required(VERSION 3.10)

project(FEM_Cell)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(FEM_Cell
    src/main.cpp
)
```

---

## 5. Build commands

From the repository root:

```bash
mkdir -p build
cd build
cmake ..
make
./FEM_Cell.  // cause cmake has a project name called FEM
```

Explanation:

* `mkdir -p build` creates the build directory if it does not already exist
* `cmake ..` configures the project using the root `CMakeLists.txt`
* `make` compiles the executable
* `./FEM_Cell` runs the compiled program

---

## 6. Minimal `src/main.cpp`

A minimal starting point for `src/main.cpp`:

```cpp
#include <iostream>

int main()
{
    std::cout << "FEM_Cell project initialized." << std::endl;
    return 0;
}
```

---

## 7. Git commmit on main

```bash
git add .
git commit -m "Add initial CMake build"
git push origin main


## 8. Git create brach, commit to branch and merge to main origin 

// commit all the staged change before workin on or creating a branch 
# create and push dev
git checkout -b dev         // creates a new branch called dev and switches to it
git push -u origin dev     // pushes the branch to GitHub and sets upstream tracking

# work on dev 
git add . 
git commit -m "Your change" 
git push 
# merge dev into main
git checkout main 
git pull origin main 
git merge dev 
git push origin main 
# continue development 
git switch dev