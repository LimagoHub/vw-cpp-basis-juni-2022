#include <iostream>
#include <memory>
#include "ListeClient.h"
#include "linked_list_impl.h"
#include "Schwein.h"

using namespace std;


int main()
{
	linked_list_impl<shared_ptr<Schwein>> liste;
	ListeClient client{ liste };
	client.run();
	std::cout << "Hello World!\n";
}