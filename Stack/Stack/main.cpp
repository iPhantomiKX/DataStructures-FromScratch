#include "Stack.hpp"

int main() {
	Stack<int> stack;
	std::cout << "Stack Top " << stack.top() << std::endl;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);
	stack.push(6);
	stack.push(7);
	stack.push(8);
	stack.push(9);
	stack.push(10);
	stack.push(11);

	std::cout << "Stack Capacity " << stack.getCapacity() << std::endl;
	std::cout << "Stack Size " << stack.getSize() << std::endl;
	std::cout << "Stack Contents " << std::endl;
	stack.print();
	std::cout << "Stack Top " << stack.top() << std::endl;
}