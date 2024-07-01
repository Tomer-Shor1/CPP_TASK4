
/*
    Tomer5469@gmail.com
    ****11541
*/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.hpp"
#include "tree.hpp"
#include <queue>
#include <string>

// Test case for adding root
TEST_CASE("Add Root") {
    Tree<int> tree(3);
    tree.addRoot(1);
    CHECK(tree.getRoot()->key == 1);
}

// Test case for adding sub-nodes
TEST_CASE("Add SubNodes") {
    Tree<int> tree(3);
    tree.addRoot(1);
    tree.addSubNode(1, 2);
    tree.addSubNode(1, 3);
    tree.addSubNode(1, 4);

    auto root = tree.getRoot();
    REQUIRE(root != nullptr);
    CHECK(root->key == 1);
    REQUIRE(root->children.size() == 3);
    CHECK(root->children[0]->key == 2);
    CHECK(root->children[1]->key == 3);
    CHECK(root->children[2]->key == 4);
}

// Test case for exceeding max children
TEST_CASE("Exceed Max Children") {
    Tree<int> tree(2);
    tree.addRoot(1);
    tree.addSubNode(1, 2);
    tree.addSubNode(1, 3);

    CHECK_THROWS_AS(tree.addSubNode(1, 4), std::runtime_error);
}

// Test case for finding non-existing parent
TEST_CASE("Non-existing Parent") {
    Tree<int> tree(3);
    tree.addRoot(1);
    CHECK_THROWS_AS(tree.addSubNode(2, 3), std::runtime_error);
}

// Test case for deep tree structure
TEST_CASE("Deep Tree Structure") {
    Tree<int> tree(2);
    tree.addRoot(1);
    tree.addSubNode(1, 2);
    tree.addSubNode(2, 3);
    tree.addSubNode(3, 4);
    tree.addSubNode(4, 5);

    auto root = tree.getRoot();
    REQUIRE(root != nullptr);
    CHECK(root->key == 1);
    CHECK(root->children[0]->key == 2);
    CHECK(root->children[0]->children[0]->key == 3);
    CHECK(root->children[0]->children[0]->children[0]->key == 4);
    CHECK(root->children[0]->children[0]->children[0]->children[0]->key == 5);
}

// Test case for multiple children
TEST_CASE("Multiple Children") {
    Tree<int> tree(3);
    tree.addRoot(1);
    tree.addSubNode(1, 2);
    tree.addSubNode(1, 3);
    tree.addSubNode(1, 4);
    tree.addSubNode(2, 5);
    tree.addSubNode(2, 6);
    tree.addSubNode(3, 7);
    tree.addSubNode(3, 8);
    tree.addSubNode(3, 9);

    auto root = tree.getRoot();
    REQUIRE(root != nullptr);
    CHECK(root->key == 1);
    CHECK(root->children[0]->key == 2);
    CHECK(root->children[1]->key == 3);
    CHECK(root->children[2]->key == 4);
    CHECK(root->children[0]->children[0]->key == 5);
    CHECK(root->children[0]->children[1]->key == 6);
    CHECK(root->children[1]->children[0]->key == 7);
    CHECK(root->children[1]->children[1]->key == 8);
    CHECK(root->children[1]->children[2]->key == 9);
}

// Test case for tree traversal
TEST_CASE("Tree Traversal") {
    Tree<int> tree(3);
    tree.addRoot(1);
    tree.addSubNode(1, 2);
    tree.addSubNode(1, 3);
    tree.addSubNode(1, 4);
    tree.addSubNode(2, 5);
    tree.addSubNode(2, 6);
    tree.addSubNode(3, 7);

    auto root = tree.getRoot();
    REQUIRE(root != nullptr);
    CHECK(root->key == 1);

    std::vector<int> preOrderKeys;
    for (auto it = tree.beginPreOrder(); it != tree.endPreOrder(); ++it) {
        preOrderKeys.push_back((*it)->key);
    }
    std::vector<int> expectedPreOrder = {1, 2, 5, 6, 3, 7, 4};
    CHECK(preOrderKeys == expectedPreOrder);

    std::vector<int> postOrderKeys;
    for (auto it = tree.beginPostOrder(); it != tree.endPostOrder(); ++it) {
        postOrderKeys.push_back((*it)->key);
    }
    std::vector<int> expectedPostOrder = {5, 6, 2, 7, 3, 4, 1};
    CHECK(postOrderKeys == expectedPostOrder);

    std::vector<int> inOrderKeys;
    for (auto it = tree.beginInOrder(); it != tree.endInOrder(); ++it) {
        inOrderKeys.push_back((*it)->key);
    }
    std::vector<int> expectedInOrder = {5, 2, 6, 1, 7, 3, 4};
    CHECK(inOrderKeys == expectedInOrder);

    std::vector<int> bfsKeys;
    for (auto it = tree.beginBfsScan(); it != tree.endBfsScan(); ++it) {
        bfsKeys.push_back((*it)->key);
    }
    std::vector<int> expectedBfs = {1, 2, 3, 4, 5, 6, 7};
    CHECK(bfsKeys == expectedBfs);

    std::vector<int> dfsKeys;
    for (auto it = tree.beginDfsScan(); it != tree.endDfsScan(); ++it) {
        dfsKeys.push_back((*it)->key);
    }
    std::vector<int> expectedDfs = {1, 2, 5, 6, 3, 7, 4};
    CHECK(dfsKeys == expectedDfs);
}



// Test case for tree with complex numbers
TEST_CASE("Tree with Complex Numbers") {
    Tree<Complex> tree(3);
    tree.addRoot(Complex(1.0, 1.0));
    tree.addSubNode(Complex(1.0, 1.0), Complex(2.0, 2.0));
    tree.addSubNode(Complex(1.0, 1.0), Complex(3.0, 3.0));
    tree.addSubNode(Complex(1.0, 1.0), Complex(4.0, 4.0));

    auto root = tree.getRoot();
    REQUIRE(root != nullptr);
    CHECK(root->key == Complex(1.0, 1.0));
    REQUIRE(root->children.size() == 3);
    CHECK(root->children[0]->key == Complex(2.0, 2.0));
    CHECK(root->children[1]->key == Complex(3.0, 3.0));
    CHECK(root->children[2]->key == Complex(4.0, 4.0));
}




// Test case for handling empty tree
TEST_CASE("Empty Tree") {
    Tree<int> tree(3);
    CHECK(tree.getRoot() == nullptr);
}

// Test case for maxDepth calculation
TEST_CASE("Max Depth Calculation") {
    Tree<int> tree(3);
    tree.addRoot(1);
    tree.addSubNode(1, 2);
    tree.addSubNode(1, 3);
    tree.addSubNode(1, 4);
    tree.addSubNode(2, 5);
    tree.addSubNode(2, 6);
    tree.addSubNode(3, 7);

    CHECK(tree.maxDepth(tree.getRoot()) == 3);
}

// Test case for large tree
TEST_CASE("Large Tree") {
    Tree<int> tree(50);
    tree.addRoot(1);
    for (int i = 2; i <= 50; ++i) {
        tree.addSubNode(1, i);
    }

    auto root = tree.getRoot();
    REQUIRE(root != nullptr);
    CHECK(root->key == 1);
    REQUIRE(root->children.size() == 49);
}

// Test case for adding duplicate keys
TEST_CASE("Add Duplicate Keys") {
    Tree<int> tree(10);
    tree.addRoot(1);
    tree.addSubNode(1, 2);
    tree.addSubNode(1, 2);  // Duplicate key

    auto root = tree.getRoot();
    REQUIRE(root != nullptr);
    CHECK(root->key == 1);
    REQUIRE(root->children.size() == 2);
    CHECK(root->children[0]->key == 2);
    CHECK(root->children[1]->key == 2);
}

// Test case for BFS traversal on large tree
TEST_CASE("BFS Traversal on Large Tree") {
    Tree<int> tree(10);
    tree.addRoot(1);
    for (int i = 2; i <= 10; ++i) {
        tree.addSubNode(1, i);
    }

    std::vector<int> bfsKeys;
    for (auto it = tree.beginBfsScan(); it != tree.endBfsScan(); ++it) {
        bfsKeys.push_back((*it)->key);
    }

    std::vector<int> expectedBfs;
    for (int i = 1; i <= 10; ++i) {
        expectedBfs.push_back(i);
    }

    CHECK(bfsKeys == expectedBfs);
}

// Test case for DFS traversal on large tree
TEST_CASE("DFS Traversal on Large Tree") {
    Tree<int> tree(10);
    tree.addRoot(1);
    for (int i = 2; i <= 10; ++i) {
        tree.addSubNode(1, i);
    }

    std::vector<int> dfsKeys;
    for (auto it = tree.beginDfsScan(); it != tree.endDfsScan(); ++it) {
        dfsKeys.push_back((*it)->key);
    }

    std::vector<int> expectedDfs = {1};
    for (int i = 2; i <= 10; ++i) {
        expectedDfs.push_back(i);
    }

    CHECK(dfsKeys == expectedDfs);
}
