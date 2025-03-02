#include "tree.h"

int main(){
    Node root("root");
    Node child1("child1");
    Node child2("child2");
    Node child3("child3");
    Node child4("child4");
    Node child5("child5");
    Node child6("child6");
    Node child7("child7");
    root.add_child(&child1);
    root.add_child(&child2);
    root.add_child(&child4);
    child3.add_child(&child5);
    child1.add_child(&child3);
    Tree one(&root);
    one.show_tree(&root);
}
