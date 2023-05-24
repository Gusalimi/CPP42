#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
	Base* ret;
	int random;

	srand((unsigned) time(NULL));
	random = rand() % 3;
	if (random == 0)
		ret = new A;
	else if (random == 1)
		ret = new B;
	else
		ret = new C;
	return (ret);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Incorrect type" << std::endl;
}

void identify(Base& p)
{
	if (dynamic_cast<A*>(&p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(&p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(&p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Incorrect type" << std::endl;
}

int main()
{
	Base* ap = new A;
	Base* bp = new B;
	Base* cp = new C;

	Base& ar = *ap;
	Base& br = *bp;
	Base& cr = *cp;

	Base* random = generate();

	std::cout << "Pointers:" << std::endl;
	identify(ap);
	identify(bp);
	identify(cp);

	std::cout << std::endl;

	std::cout << "References:" << std::endl;
	identify(ar);
	identify(br);
	identify(cr);

	std::cout << std::endl;

	std::cout << "Random:" << std::endl;
	identify(random);
	identify(*random);

	std::cout << std::endl;
	delete ap;
	delete bp;
	delete cp;
}