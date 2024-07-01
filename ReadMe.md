# k-ary Tree and Complex Number Operations

## Overview
This project provides an implementation of a generic k-ary tree and a complex number class in C++. The k-ary tree supports various traversal methods and operations, while the complex number class supports basic arithmetic and comparison operations.

## Files
- `tree.hpp`: Header file containing the declaration of the `Tree` class and the `Complex` class.
- `tree.cpp`: Implementation file containing the definitions of the member functions of the `Tree` class.

## Tree Class
The `Tree` class is a template class that represents a k-ary tree. The tree can be instantiated with any data type and allows for various operations such as adding nodes, tree traversal, and printing.

### Main Functions

- **Tree(int k = 2)**: Constructor that initializes an empty tree with a specified maximum number of children per node (default is 2).
- **~Tree()**: Destructor that recursively deletes all nodes in the tree.
- **void addRoot(const T &key)**: Adds a root node to the tree. If the tree already has a root, the existing tree is deleted.
- **void addSubNode(const T &parentKey, const T &childKey)**: Adds a child node to a specified parent node. Throws an error if the parent node is not found or the maximum number of children is exceeded.
- **int maxDepth(Node *node) const**: Calculates the maximum depth of the tree.
- **void print() const**: Prints the tree in a visually appealing way.
- **void myHeap()**: Converts the tree into a min-heap using the keys of the nodes.

### Iterators
- **PreOrderIterator**: Supports pre-order traversal of the tree.
- **PostOrderIterator**: Supports post-order traversal of the tree.
- **InOrderIterator**: Supports in-order traversal of the tree (more meaningful for binary trees).
- **BFSIterator**: Supports breadth-first traversal of the tree.
- **DFSIterator**: Supports depth-first traversal of the tree.

## Complex Class
The `Complex` class represents complex numbers and supports basic arithmetic and comparison operations.

### Main Functions

- **Complex(double r = 0, double i = 0)**: Constructor that initializes a complex number with specified real and imaginary parts (default is 0).
- **bool operator>(const Complex &other) const**: Compares two complex numbers based on their magnitude.
- **bool operator==(const Complex &other) const**: Checks if two complex numbers are equal.
- **friend std::ostream &operator<<(std::ostream &os, const Complex &c)**: Overloads the output stream operator to print complex numbers in the form `a + bi`.

## Usage
### Building the Project
To compile the project, use a C++ compiler like `g++`. To compile, use make and then ./test or ./main

