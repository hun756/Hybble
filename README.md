# Data-Sutructures-in-CPlusPlus

Data Structures with basically C++ OOP concepts. Containers are handled as in STL.

## İnstallation

Requirements :

-   CMake
-   MinGW Compiler

Installation steps:

-   Step 1 : Clone this repository..!

```sh
    git clone https://github.com/hun756/Data-Sutructures-in-CPlusPlus.git
```

-   Step 2 (Optional) : Use This CMake Configurations

```
.
├── include
│ ├── array.hpp
│ └── . . .
├── src
│ ├── array.cpp
│ └── . . .
├── resources
│ ├── addyourresource.cpp
│ └── addyourcodefiles.cpp
```

```cmake
set(PROJECT_RESOURCES

        # . . .
        
        ${PROJECT_RESOURCES_DIR}/addyourresource.cpp
        ${PROJECT_RESOURCES_DIR}/addyourcodefiles.cpp
   )
```

-   Step 2 : Configure your Cmake
    -   Copy include and src directories to your project.
    -   Add the following Cmake configuration.

```cmake
# ...

set(DS_INCLUDE_DIR ${PROJECT_DIR}/include)

# ...

include_directories(${DS_INCLUDE_DIR})
```

-   Step 3 : Build

      Run this code :

```sh
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
```

-   Step 3 : Run

      Run this code :

```sh
mingw32-make
```

## Containers

-   Array
-   TArray (Vector)
-   Lists
-   Deque
-   Queues
-   Stack
-   Binary Search Tree
-   AVL Tree
-   Read Black Tree
-   HashMap
-   Unordered Map
-   Unordered Set
-   Ordered Map
-   Ordered Set



## License
* * * 

MIT License