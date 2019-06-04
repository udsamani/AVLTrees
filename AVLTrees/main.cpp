//
//  main.cpp
//  AVLTrees
//
//  Created by Udit Samani on 6/3/19.
//  Copyright © 2019 Udit Samani. All rights reserved.
//

#include "AVLTree.cpp"
#include <string>

int main(int argc, const char * argv[]) {
    // insert code here...
    const std::string ITEM_NOT_FOUND = "";
    AVLTree<std::string> tree(ITEM_NOT_FOUND);
    tree.insert("a");
    tree.insert("b");
    tree.insert("c");
    //tree.insert("d");
    //tree.insert("e");
    //tree.insert("f");
    tree.printTreeDepth();
   // std::cout << tree.find(6) <<std::endl;
}
