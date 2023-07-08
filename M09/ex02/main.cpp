#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	(void)argc;
	try {
		PmergeMe pm;
		pm.run(argv);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}