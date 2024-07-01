/*
    Tomer5469@gmail.com
    ****11541
*/

#ifndef TREE_HPP
#define TREE_HPP

#include <vector>
#include <iostream>
#include <queue>
#include <cmath>

// Generic k-ary tree class
template <typename T>
class Tree
{
public:
    struct Node
    {
        T key;
        std::vector<Node *> children;
        Node(const T &key) : key(key) {}
    };

private:
    Node *root;
    int maxChildren;

    static void preOrder(Node *node, std::vector<Node *> &nodes);
    static void postOrder(Node *node, std::vector<Node *> &nodes);
    static void inOrder(Node *node, std::vector<Node *> &nodes);
    static void bfs(Node *node, std::vector<Node *> &nodes);
    static void dfs(Node *node, std::vector<Node *> &nodes);

public:
    Tree(int k = 2);
    ~Tree();

    Node *getRoot() const;
    void addRoot(const T &key);
    void addSubNode(const T &parentKey, const T &childKey);

    int maxDepth(Node *node) const;

    class PreOrderIterator
    {
    protected:
        std::vector<Node *> nodes;
        size_t index;

    public:
        PreOrderIterator(Node *root);

        Node *operator*() const;

        PreOrderIterator &operator++();

        bool operator!=(const PreOrderIterator &other) const;

        void setToEnd();
    };

    PreOrderIterator beginPreOrder() const;
    PreOrderIterator endPreOrder() const;

    class PostOrderIterator
    {
    protected:
        std::vector<Node *> nodes;
        size_t index;

    public:
        PostOrderIterator(Node *root);

        Node *operator*() const;

        PostOrderIterator &operator++();

        bool operator!=(const PostOrderIterator &other) const;

        void setToEnd();
    };

    PostOrderIterator beginPostOrder() const;
    PostOrderIterator endPostOrder() const;

    class InOrderIterator
    {
    protected:
        std::vector<Node *> nodes;
        size_t index;

    public:
        InOrderIterator(Node *root);

        Node *operator*() const;

        InOrderIterator &operator++();

        bool operator!=(const InOrderIterator &other) const;

        void setToEnd();
    };

    InOrderIterator beginInOrder() const;
    InOrderIterator endInOrder() const;

    class BFSIterator
    {
    protected:
        std::vector<Node *> nodes;
        size_t index;

    public:
        BFSIterator(Node *root);

        Node *operator*() const;

        BFSIterator &operator++();

        bool operator!=(const BFSIterator &other) const;

        void setToEnd();
    };

    BFSIterator beginBfsScan() const;
    BFSIterator endBfsScan() const;

    class DFSIterator
    {
    protected:
        std::vector<Node *> nodes;
        size_t index;

    public:
        DFSIterator(Node *root);

        Node *operator*() const;

        DFSIterator &operator++();

        bool operator!=(const DFSIterator &other) const;

        void setToEnd();
    };

    DFSIterator beginDfsScan() const;
    DFSIterator endDfsScan() const;

    void myHeap();
    void print() const;

private:
    void deleteTree(Node *node);
};

// Complex number class
class Complex
{
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    bool operator>(const Complex &other) const
    {
        return std::sqrt(real * real + imag * imag) > std::sqrt(other.real * real + other.imag * other.imag);
    }

    bool operator==(const Complex &other) const
    {
        return real == other.real && imag == other.imag;
    }

    friend std::ostream &operator<<(std::ostream &os, const Complex &c)
    {
        os << c.real << " + " << c.imag << "i";
        return os;
    }
};

// Implementation of Tree class functions
template<typename T>
Tree<T>::Tree(int k) : root(nullptr), maxChildren(k) {}

template<typename T>
Tree<T>::~Tree() {
    deleteTree(root);
}

template<typename T>
void Tree<T>::addRoot(const T& key) {
    if (root) deleteTree(root);
    root = new Node(key);
}

template<typename T>
void Tree<T>::addSubNode(const T& parentKey, const T& childKey) {
    if (!root) return;

    std::queue<Node*> queue;
    queue.push(root);

    while (!queue.empty()) {
        Node* current = queue.front();
        queue.pop();

        if (current->key == parentKey) {
            if (current->children.size() < static_cast<std::size_t>(maxChildren)) {
                current->children.push_back(new Node(childKey));
                return;
            } else {
                throw std::runtime_error("Maximum children limit reached for this node");
            }
        }

        for (Node* child : current->children) {
            queue.push(child);
        }
    }

    throw std::runtime_error("Parent node not found");
}

// Template function to calculate the maximum depth of the tree
template<typename T>
int Tree<T>::maxDepth(Node* node) const {
    if (!node) return 0;
    int max_depth = 0;
    for (auto child : node->children) {
        max_depth = std::max(max_depth, maxDepth(child));
    }
    return 1 + max_depth;
}

// Print the tree in a visually appealing way
template<typename T>
void Tree<T>::print() const {
    if (!root) return;

    int depth = maxDepth(root);

    std::queue<Node*> nodes;
    nodes.push(root);

    int level = 0;
    int count = 1;

    while (!nodes.empty()) {
        int next_count = 0;
        std::vector<Node*> level_nodes;

        while (count > 0 && !nodes.empty()) {
            Node* current = nodes.front();
            nodes.pop();
            level_nodes.push_back(current);

            for (auto child : current->children) {
                nodes.push(child);
                next_count++;
            }

            count--;
        }

        int space_between = std::pow(2, depth - level) - 1;
        std::string space = std::string(space_between, ' ');

        std::cout << std::string(space_between / 2, ' ');
        for (auto node : level_nodes) {
            if (node) {
                std::cout << node->key << space;
            } else {
                std::cout << " " << space;
            }
        }
        std::cout << std::endl;

        count = next_count;
        level++;
    }
}

// PreOrder iterator implementation
template<typename T>
Tree<T>::PreOrderIterator::PreOrderIterator(Node* root) : index(0) {
    if (root) {
        Tree::preOrder(root, nodes);
    }
}

template<typename T>
typename Tree<T>::Node* Tree<T>::PreOrderIterator::operator*() const {
    return nodes[index];
}

template <typename T>
typename Tree<T>::Node* Tree<T>::getRoot() const {
    return root;
}

template<typename T>
typename Tree<T>::PreOrderIterator& Tree<T>::PreOrderIterator::operator++() {
    ++index;
    return *this;
}

template<typename T>
bool Tree<T>::PreOrderIterator::operator!=(const PreOrderIterator& other) const {
    return index != other.index;
}

template<typename T>
void Tree<T>::PreOrderIterator::setToEnd() {
    index = nodes.size();
}

template<typename T>
typename Tree<T>::PreOrderIterator Tree<T>::beginPreOrder() const {
    return PreOrderIterator(root);
}

template<typename T>
typename Tree<T>::PreOrderIterator Tree<T>::endPreOrder() const {
    PreOrderIterator it(root);
    it.setToEnd();
    return it;
}

// PostOrder iterator implementation
template<typename T>
Tree<T>::PostOrderIterator::PostOrderIterator(Node* root) : index(0) {
    if (root) {
        Tree::postOrder(root, nodes);
    }
}

template<typename T>
typename Tree<T>::Node* Tree<T>::PostOrderIterator::operator*() const {
    return nodes[index];
}

template<typename T>
typename Tree<T>::PostOrderIterator& Tree<T>::PostOrderIterator::operator++() {
    ++index;
    return *this;
}

template<typename T>
bool Tree<T>::PostOrderIterator::operator!=(const PostOrderIterator& other) const {
    return index != other.index;
}

template<typename T>
void Tree<T>::PostOrderIterator::setToEnd() {
    index = nodes.size();
}

template<typename T>
typename Tree<T>::PostOrderIterator Tree<T>::beginPostOrder() const {
    return PostOrderIterator(root);
}

template<typename T>
typename Tree<T>::PostOrderIterator Tree<T>::endPostOrder() const {
    PostOrderIterator it(root);
    it.setToEnd();
    return it;
}

// InOrder iterator implementation
template<typename T>
Tree<T>::InOrderIterator::InOrderIterator(Node* root) : index(0) {
    if (root) {
        Tree::inOrder(root, nodes);
    }
}

template<typename T>
typename Tree<T>::Node* Tree<T>::InOrderIterator::operator*() const {
    return nodes[index];
}

template<typename T>
typename Tree<T>::InOrderIterator& Tree<T>::InOrderIterator::operator++() {
    ++index;
    return *this;
}

template<typename T>
bool Tree<T>::InOrderIterator::operator!=(const InOrderIterator& other) const {
    return index != other.index;
}

template<typename T>
void Tree<T>::InOrderIterator::setToEnd() {
    index = nodes.size();
}

template<typename T>
typename Tree<T>::InOrderIterator Tree<T>::beginInOrder() const {
    return InOrderIterator(root);
}

template<typename T>
typename Tree<T>::InOrderIterator Tree<T>::endInOrder() const {
    InOrderIterator it(root);
    it.setToEnd();
    return it;
}

// BFS iterator implementation
template<typename T>
Tree<T>::BFSIterator::BFSIterator(Node* root) : index(0) {
    if (root) {
        Tree::bfs(root, nodes);
    }
}

template<typename T>
typename Tree<T>::Node* Tree<T>::BFSIterator::operator*() const {
    return nodes[index];
}

template<typename T>
typename Tree<T>::BFSIterator& Tree<T>::BFSIterator::operator++() {
    ++index;
    return *this;
}

template<typename T>
bool Tree<T>::BFSIterator::operator!=(const BFSIterator& other) const {
    return index != other.index;
}

template<typename T>
void Tree<T>::BFSIterator::setToEnd() {
    index = nodes.size();
}

template<typename T>
typename Tree<T>::BFSIterator Tree<T>::beginBfsScan() const {
    return BFSIterator(root);
}

template<typename T>
typename Tree<T>::BFSIterator Tree<T>::endBfsScan() const {
    BFSIterator it(root);
    it.setToEnd();
    return it;
}

// DFS iterator implementation
template<typename T>
Tree<T>::DFSIterator::DFSIterator(Node* root) : index(0) {
    if (root) {
        Tree::dfs(root, nodes);
    }
}

template<typename T>
typename Tree<T>::Node* Tree<T>::DFSIterator::operator*() const {
    return nodes[index];
}

template<typename T>
typename Tree<T>::DFSIterator& Tree<T>::DFSIterator::operator++() {
    ++index;
    return *this;
}

template<typename T>
bool Tree<T>::DFSIterator::operator!=(const DFSIterator& other) const {
    return index != other.index;
}

template<typename T>
void Tree<T>::DFSIterator::setToEnd() {
    index = nodes.size();
}

template<typename T>
typename Tree<T>::DFSIterator Tree<T>::beginDfsScan() const {
    return DFSIterator(root);
}

template<typename T>
typename Tree<T>::DFSIterator Tree<T>::endDfsScan() const {
    DFSIterator it(root);
    it.setToEnd();
    return it;
}

// Convert a binary tree to a min-heap
template<typename T>
void Tree<T>::myHeap() {
    if (!root) return;

    std::vector<Node*> nodes;
    Tree::bfs(root, nodes);

    std::make_heap(nodes.begin(), nodes.end(), [](Node* a, Node* b) {
        return a->key > b->key;
    });

    root = nodes[0];
    std::queue<Node*> queue;
    queue.push(root);

    size_t index = 1;
    while (!queue.empty() && index < nodes.size()) {
        Node* current = queue.front();
        queue.pop();

        current->children.clear();
        for (int i = 0; i < maxChildren && index < nodes.size(); ++i, ++index) {
            current->children.push_back(nodes[index]);
            queue.push(nodes[index]);
        }
    }
}

template<typename T>
void Tree<T>::deleteTree(Node* node) {
    if (!node) return;
    for (Node* child : node->children) {
        deleteTree(child);
    }
    delete node;
}

// Utility functions for iterators
template<typename T>
void Tree<T>::preOrder(Node* node, std::vector<Node*>& nodes) {
    if (!node) return;
    nodes.push_back(node);
    for (Node* child : node->children) {
        preOrder(child, nodes);
    }
}

template<typename T>
void Tree<T>::postOrder(Node* node, std::vector<Node*>& nodes) {
    if (!node) return;
    for (Node* child : node->children) {
        postOrder(child, nodes);
    }
    nodes.push_back(node);
}

template<typename T>
void Tree<T>::inOrder(Node* node, std::vector<Node*>& nodes) {
    if (!node) return;
    if (!node->children.empty()) {
        inOrder(node->children[0], nodes);
    }
    nodes.push_back(node);
    for (size_t i = 1; i < node->children.size(); ++i) {
        inOrder(node->children[i], nodes);
    }
}

template<typename T>
void Tree<T>::bfs(Node* node, std::vector<Node*>& nodes) {
    if (!node) return;
    std::queue<Node*> queue;
    queue.push(node);
    while (!queue.empty()) {
        Node* current = queue.front();
        queue.pop();
        nodes.push_back(current);
        for (Node* child : current->children) {
            queue.push(child);
        }
    }
}

template<typename T>
void Tree<T>::dfs(Node* node, std::vector<Node*>& nodes) {
    if (!node) return;
    nodes.push_back(node);
    for (Node* child : node->children) {
        dfs(child, nodes);
    }
}

// Explicit instantiations for the types we intend to use
template class Tree<int>;
template class Tree<double>;
template class Tree<Complex>;

#endif // TREE_HPP
