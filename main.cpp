/*
    Tomer5469@gmail.com
    ****11541
*/


#include <SFML/Graphics.hpp>
#include "tree.hpp"
#include <queue>
#include <string>
#include <iostream>

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
    text.setString(std::to_string(node->key));
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setPosition(x + 10, y + 10);
    window.draw(text);

    // Draw the children nodes
    float childX = x - horizontalSpacing / 2;
    for (auto child : node->children) {
        // Draw a line from the current node to the child node
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x + 20, y + 20)),
            sf::Vertex(sf::Vector2f(childX + 20, y + verticalSpacing + 20))
        };
        window.draw(line, 2, sf::Lines);

        // Recursively draw the child node
        drawTree<T>(window, child, childX, y + verticalSpacing, horizontalSpacing / 2, verticalSpacing, font);
        childX += horizontalSpacing;
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tree Visualization");

    // Load font from the project directory
    sf::Font font;
    if (!font.loadFromFile("RobotoFlex-Regular.ttf")) {  // Ensure DejaVuSans.ttf is in the working directory
        std::cerr << "Error loading font 'DejaVuSans.ttf'. Ensure it is in the working directory." << std::endl;
        return -1;
    }

    // Create a sample tree
    Tree<int> tree(3);
    tree.addRoot(1);
    tree.addSubNode(1, 2);
    tree.addSubNode(1, 3);
    tree.addSubNode(1, 4);
    tree.addSubNode(2, 5);
    tree.addSubNode(2, 6);
    tree.addSubNode(3, 7);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        // Draw the tree starting from the root node
        drawTree<int>(window, tree.getRoot(), 400, 50, 300, 100, font);

        window.display();
    }

    return 0;
}
