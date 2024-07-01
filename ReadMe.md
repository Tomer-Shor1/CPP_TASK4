# **Tree Visualization and Testing**

This project implements a generic k-ary tree in C++ using templates, provides various traversal methods, and visualizes the tree using the SFML library. Additionally, it includes comprehensive tests using the `doctest` library to ensure the correctness of the tree implementation.

## **Table of Contents**

- [Introduction](#introduction)
- [Project Structure](#project-structure)
- [Detailed Code Explanation](#detailed-code-explanation)
  - [Tree Class](#tree-class)
  - [Complex Class](#complex-class)
  - [Tree Traversal](#tree-traversal)
  - [Tree Visualization](#tree-visualization)
- [Usage Instructions](#usage-instructions)
  - [Compiling the Program](#compiling-the-program)
  - [Running the Program](#running-the-program)
  - [Running the Tests](#running-the-tests)
- [Dependencies](#dependencies)
- [Conclusion](#conclusion)

## **Introduction**

This project demonstrates the implementation of a generic k-ary tree with support for various data types using C++ templates. It provides functions to add nodes, traverse the tree in multiple ways, and visualize the tree structure using the SFML graphics library. The project also includes a set of tests to verify the functionality and correctness of the tree implementation.

## **Project Structure**

The project consists of the following files:

- `main.cpp`: Entry point for the tree visualization application.
- `tree.hpp`: Header file defining the `Tree` class template and the `Complex` class.
- `tree_impl.hpp`: Header file containing the implementation of the `Tree` class template.
- `tree.cpp`: Source file for the `Tree` class template instantiation.
- `test_tree.cpp`: Test file using `doctest` to verify the functionality of the `Tree` class.
- `doctest.h`: Header file for the `doctest` library.
- `DejaVuSans.ttf`: Font file used in the visualization.

## **Detailed Code Explanation**

### **Tree Class**

The `Tree` class is a generic k-ary tree implemented using C++ templates. It allows creating trees with any data type as the node key. The tree supports various operations such as adding a root, adding sub-nodes, and different traversal methods.

#### **Template Usage**

Using templates allows the `Tree` class to be flexible and handle different data types. The template is defined as follows:

```cpp
template <typename T>
class Tree {
    ...
};
