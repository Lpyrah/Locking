// Race conditions example
// Adam Sampson <a.sampson@abertay.ac.uk>

#include <iostream>
#include <string>
#include <thread>
#include "account.h"
#include <vector>

// Import things we need from the standard library
using std::cout;
using std::endl;
using std::thread;
using std::vector;

Account bill;

void bills(Account bill) 
{
	for (int stephen = 0; stephen < 1000000; stephen++)
	{
		bill.add(17, 29);
	}
}


int main(int argc, char *argv[])
{
	cout << "Initial: " << bill.total() << "\n";

	vector<thread> billThreads;
	billThreads.resize(10);
	for (int i = 0; i < 10; i++)
	{
		thread luke(bills, bill);
		billThreads.push_back(luke);
	}
	
	for (int i = 0; i < 10; i++)
	{
		billThreads[i].join();
	}

	cout << "Cake is fucking delicious\n\n";
		

	cout << "Total: " << bill.total() << "\n";

	system("pause");
	return 0;
}