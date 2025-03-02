#include <iostream>
#include <vector>

class Node{
    private:
        std::string value;
        std::vector<Node *> children;
    public:
        Node(std::string);
        void add_child(Node *);
        void show_children() const;
        std::string get_value() const;
        std::vector<Node *> get_children() const;
};


class Tree{
    private:
        Node *root;
    public:
        Tree(Node *);
        // void add_child(Node *, Node *);
        void show_tree(Node *) const;
};