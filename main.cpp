/*
    Tomer5469@gmail.com
    ****11541
*/



#include <SFML/Graphics.hpp>
#include "tree.hpp"
#include <queue>
#include <string>
#include <iostream>

// Function to calculate the depth of the tree
template<typename T>
int calculateDepth(typename Tree<T>::Node* node) {
    if (!node) return 0;
    int max_depth = 0;
    for (auto child : node->children) {
        max_depth = std::max(max_depth, calculateDepth<T>(child));
    }
    return 1 + max_depth;
}

// Function to draw the tree
template<typename T>
void drawTree(sf::RenderWindow &window, typename Tree<T>::Node* node, float x, float y, float horizontalSpacing, float verticalSpacing, const sf::Font& font) {
    if (!node) return;

    // Draw the node as a circle
    sf::CircleShape circle(20);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(x, y);
    window.draw(circle);

    // Draw the node's key as text
    sf::Text text;
    text.setFont(font);
    std::string displayText = std::to_string(node->key);
    text.setString(displayText);
    text.setCharacterSize(14);
    text.setFillColor(sf::Color::Black);

    // Ensure the text fits within the circle
    sf::FloatRect textBounds = text.getLocalBounds();
    while (textBounds.width > circle.getRadius() * 1.8) {
        if (displayText.size() <= 3) break;
        displayText = displayText.substr(0, displayText.size() - 4) + "...";
        text.setString(displayText);
        textBounds = text.getLocalBounds();
    }
    text.setPosition(x + circle.getRadius() - textBounds.width / 2, y + circle.getRadius() - textBounds.height / 2);

    window.draw(text);

    // Draw the children nodes
    float childX = x - horizontalSpacing * (node->children.size() - 1) / 2;
    for (auto child : node->children) {
        // Draw a line from the current node to the child node
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x + 20, y + 20)),
            sf::Vertex(sf::Vector2f(childX + 20, y + verticalSpacing + 20))
        };
        window.draw(line, 2, sf::Lines);

        // Recursively draw the child node
        drawTree<T>(window, child, childX, y + verticalSpacing, horizontalSpacing / node->children.size(), verticalSpacing, font);
        childX += horizontalSpacing;
    }
}

template<>
void drawTree<std::string>(sf::RenderWindow &window, typename Tree<std::string>::Node* node, float x, float y, float horizontalSpacing, float verticalSpacing, const sf::Font& font) {
    if (!node) return;

    // Draw the node as a circle
    sf::CircleShape circle(20);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(x, y);
    window.draw(circle);

    // Draw the node's key as text
    sf::Text text;
    text.setFont(font);
    std::string displayText = node->key;
    text.setString(displayText);
    text.setCharacterSize(14);
    text.setFillColor(sf::Color::Black);

    // Ensure the text fits within the circle
    sf::FloatRect textBounds = text.getLocalBounds();
    while (textBounds.width > circle.getRadius() * 1.8) {
        if (displayText.size() <= 3) break;
        displayText = displayText.substr(0, displayText.size() - 4) + "...";
        text.setString(displayText);
        textBounds = text.getLocalBounds();
    }
    text.setPosition(x + circle.getRadius() - textBounds.width / 2, y + circle.getRadius() - textBounds.height / 2);

    window.draw(text);

    // Draw the children nodes
    float childX = x - horizontalSpacing * (node->children.size() - 1) / 2;
    for (auto child : node->children) {
        // Draw a line from the current node to the child node
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x + 20, y + 20)),
            sf::Vertex(sf::Vector2f(childX + 20, y + verticalSpacing + 20))
        };
        window.draw(line, 2, sf::Lines);

        // Recursively draw the child node
        drawTree<std::string>(window, child, childX, y + verticalSpacing, horizontalSpacing / node->children.size(), verticalSpacing, font);
        childX += horizontalSpacing;
    }
}

template<typename T>
void showTree(Tree<T>& tree, const sf::Font& font) {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tree Visualization");

    // Calculate the depth of the tree for spacing adjustments
    int depth = calculateDepth<T>(tree.getRoot());

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        drawTree<T>(window, tree.getRoot(), 400, 50, 300 / depth, 100, font);
        window.display();
    }
}

int main() {
    sf::Font font;
    if (!font.loadFromFile("RobotoFlex-Regular.ttf")) {
        std::cerr << "Error loading font 'RobotoFlex-Regular.ttf'. Ensure it is in the working directory." << std::endl;
        return -1;
    }

    // Create the trees
    Tree<int> tree1(3);
    tree1.addRoot(1);
    tree1.addSubNode(1, 2);
    tree1.addSubNode(1, 3);
    tree1.addSubNode(1, 4);
    tree1.addSubNode(2, 5);
    tree1.addSubNode(2, 6);
    tree1.addSubNode(3, 7);

    Tree<int> tree2(2);
    tree2.addRoot(10);
    tree2.addSubNode(10, 20);
    tree2.addSubNode(10, 30);
    tree2.addSubNode(20, 40);
    tree2.addSubNode(20, 50);

    Tree<int> tree3(4);
    tree3.addRoot(100);
    tree3.addSubNode(100, 200);
    tree3.addSubNode(100, 300);
    tree3.addSubNode(100, 400);
    tree3.addSubNode(100, 500);
    tree3.addSubNode(200, 600);
    tree3.addSubNode(300, 700);

    Tree<int> tree5(3);
    tree5.addRoot(1);
    tree5.addSubNode(1, 2);
    tree5.addSubNode(1, 3);
    tree5.addSubNode(1, 4);
    tree5.addSubNode(2, 5);
    tree5.addSubNode(2, 6);
    tree5.addSubNode(2, 7);
    tree5.addSubNode(3, 8);
    tree5.addSubNode(3, 9);
    tree5.addSubNode(4, 10);
    tree5.addSubNode(4, 11);
    tree5.addSubNode(5, 12);
    tree5.addSubNode(6, 13);
    tree5.addSubNode(7, 14);

    Tree<std::string> tree4(2);
    tree4.addRoot("Root");
    tree4.addSubNode("Root", "Child1");
    tree4.addSubNode("Root", "Child2");
    tree4.addSubNode("Child1", "Grandchild1");
    tree4.addSubNode("Child1", "Grandchild2");
    tree4.addSubNode("Grandchild1", "VeryLongNameThatExceedsNodeSize");

    Tree<std::string> tree6(3);
    tree6.addRoot("Root");
    tree6.addSubNode("Root", "Child1");
    tree6.addSubNode("Root", "Child2");
    tree6.addSubNode("Root", "Child3");
    tree6.addSubNode("Child1", "Grandchild1");
    tree6.addSubNode("Child1", "Grandchild2");
    tree6.addSubNode("Child1", "Grandchild3");
    tree6.addSubNode("Child2", "Grandchild4");
    tree6.addSubNode("Child2", "Grandchild5");
    tree6.addSubNode("Child3", "Grandchild6");

    // Additional complex trees
    Tree<int> tree7(5);
    tree7.addRoot(1);
    tree7.addSubNode(1, 2);
    tree7.addSubNode(1, 3);
    tree7.addSubNode(1, 4);
    tree7.addSubNode(1, 5);
    tree7.addSubNode(1, 6);
    tree7.addSubNode(2, 7);
    tree7.addSubNode(2, 8);
    tree7.addSubNode(3, 9);
    tree7.addSubNode(3, 10);
    tree7.addSubNode(4, 11);
    tree7.addSubNode(4, 12);
    tree7.addSubNode(5, 13);
    tree7.addSubNode(5, 14);
    tree7.addSubNode(6, 15);

    Tree<int> tree8(3);
    tree8.addRoot(100);
    tree8.addSubNode(100, 200);
    tree8.addSubNode(100, 300);
    tree8.addSubNode(100, 400);
    tree8.addSubNode(200, 500);
    tree8.addSubNode(200, 600);
    tree8.addSubNode(300, 700);
    tree8.addSubNode(300, 800);
    tree8.addSubNode(400, 900);
    tree8.addSubNode(400, 1000);
    tree8.addSubNode(500, 1100);
    tree8.addSubNode(600, 1200);
    tree8.addSubNode(700, 1300);
    tree8.addSubNode(800, 1400);

    Tree<std::string> tree9(4);
    tree9.addRoot("Start");
    tree9.addSubNode("Start", "Alpha");
    tree9.addSubNode("Start", "Beta");
    tree9.addSubNode("Start", "Gamma");
    tree9.addSubNode("Start", "Delta");
    tree9.addSubNode("Alpha", "Alpha1");
    tree9.addSubNode("Alpha", "Alpha2");
    tree9.addSubNode("Beta", "Beta1");
    tree9.addSubNode("Beta", "Beta2");
    tree9.addSubNode("Gamma", "Gamma1");
    tree9.addSubNode("Gamma", "Gamma2");
    tree9.addSubNode("Delta", "Delta1");
    tree9.addSubNode("Delta", "Delta2");

    // Show the trees one by one
    showTree(tree1, font);
    showTree(tree2, font);
    showTree(tree3, font);
    showTree(tree5, font);
    showTree(tree4, font);
    showTree(tree6, font);
    showTree(tree7, font);
    showTree(tree8, font);
    showTree(tree9, font);

    return 0;
}
