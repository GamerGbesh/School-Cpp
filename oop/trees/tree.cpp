#include "tree.h"

Node::Node(std::string value): value(value){}

void Node::add_child(Node * node){
    children.push_back(node);
}

void Node::show_children() const{
    for (auto i: children){
        Node out = *i; 
        std::cout << out.value << std::endl;
    }
}

std::string Node::get_value() const {
    return this->value;
}

std::vector<Node *> Node::get_children() const {
    return this->children;
}

Tree::Tree(Node * root): root(root){}

void Tree::show_tree(Node * node) const{
    std::cout << node->get_value() << std::endl << "\t";
    for (auto i: node->get_children()){
        Tree::show_tree(i); 
    }
}