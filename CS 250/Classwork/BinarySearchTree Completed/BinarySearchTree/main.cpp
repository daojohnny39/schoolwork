#include "BinarySearchTree.hpp"
#include <iostream>
#include <string>


void display(int& anItem)
{
	std::cout << "Displaying item - " << anItem << std::endl;
}  // end display

int main()
{
	auto tree1 = std::make_shared<BinarySearchTree<int>>();

	std::cout << "tree1->add(50): " << tree1->add(50) << " [should be 1]" << std::endl;
	std::cout << "tree1->add(80): " << tree1->add(80) << " [should be 1]" << std::endl;
	std::cout << "tree1->add(30): " << tree1->add(30) << " [should be 1]" << std::endl;
	std::cout << "tree1->add(10): " << tree1->add(10) << " [should be 1]" << std::endl;
	std::cout << "tree1->add(60): " << tree1->add(60) << " [should be 1]" << std::endl;
	std::cout << "tree1->add(20): " << tree1->add(20) << " [should be 1]" << std::endl;
	std::cout << "tree1->add(70): " << tree1->add(70) << " [should be 1]" << std::endl;
	std::cout << "tree1->add(40): " << tree1->add(40) << " [should be 1]" << std::endl;
	std::cout << "tree1->add(90): " << tree1->add(90) << " [should be 1]" << std::endl;
	std::cout << "tree1->add(100): " << tree1->add(100) << " [should be 1]" << std::endl;
	std::cout << std::endl;

	std::cout << "tree1->getHeight(): " << tree1->getHeight() << " [should be 4]" << std::endl;
	std::cout << "tree1->getNumberOfNodes(): " << tree1->getNumberOfNodes() << " [should be 10]" << std::endl;
	std::cout << "tree1->contains(10): " << tree1->contains(10) << " [should be 1]" << std::endl;
	std::cout << "tree1->contains(90): " << tree1->contains(90) << " [should be 1]" << std::endl;
	std::cout << "tree1->contains(15): " << tree1->contains(15) << " [should be 0]" << std::endl;
	std::cout << "tree1->getEntry(10): " << tree1->getEntry(10) << " [should be 10]" << std::endl;
	std::cout << "tree1->getEntry(90): " << tree1->getEntry(90) << " [should be 90]" << std::endl;
	std::cout << std::endl;

	std::cout << "Using overloaded = to copy tree1 to tree2..." << std::endl << std::endl;
	BinarySearchTree<int> tree2 = *tree1;

	std::cout << "Remove 20, no children: " << tree1->remove(20) << " [should be 1]" << std::endl;
	std::cout << "Remove 20 again: " << tree1->remove(20) << " [should be 0]" << std::endl;
	std::cout << "Remove 60, 1 child: " << tree1->remove(60) << " [should be 1]" << std::endl;
	std::cout << "Remove 80, 2 children: " << tree1->remove(80) << " [should be 1]" << std::endl;
	std::cout << std::endl;

	std::cout << "tree1->getHeight(): " << tree1->getHeight() << " [should be 3]" << std::endl;
	std::cout << "tree1->getNumberOfNodes(): " << tree1->getNumberOfNodes() << " [should be 7]" << std::endl;
	std::cout << std::endl;

	std::cout << "Tree 1 Inorder: Should be 10 30 40 50 70 90 100\n";
	tree1->inorderTraverse(display);
	std::cout << std::endl;

	std::cout << "Running tree1->clear()..." << std::endl;
	tree1->clear();
	std::cout << "tree1->getHeight(): " << tree1->getHeight() << " [should be 0]" << std::endl;
	std::cout << "tree1->getNumberOfNodes(): " << tree1->getNumberOfNodes() << " [should be 0]" << std::endl;
	std::cout << std::endl;

	std::cout << "Copy of original tree1, tree2:" << std::endl;
	std::cout << "tree2.getHeight(): " << tree2.getHeight() << " [should be 4]" << std::endl;
	std::cout << "tree2.getNumberOfNodes(): " << tree2.getNumberOfNodes() << " [should be 10]" << std::endl;
	std::cout << std::endl;


	return 0;
}  // end main
