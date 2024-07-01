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

#endif // TREE_HPP
