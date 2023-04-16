#include "mylist.h"
#include <iostream>
#include <eh.h>

using namespace std;

int main() {
	{
		Mylist<int> a;
		for (size_t i = 0; i < 5; i++) {
			a.push_back(i);
		}
	}
	
}