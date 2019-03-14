// Race conditions example
// Adam Sampson <a.sampson@abertay.ac.uk>

#include <iostream>
#include <string>
#include <thread>
#include "account.h"
#include <vector>
#include <mutex>

// Import things we need from the standard library
using std::cout;
using std::endl;
using std::thread;
using std::vector;
using std::mutex;

Account bill;

void bills() 
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
	for (int i = 0; i < 10; i++)
	{
		billThreads.push_back(std::thread(bills));
	}


	for (int i = 0; i < billThreads.size(); i++) {
		billThreads[i].join();
	}

	cout << "Total: " << bill.total() << "\n";

	system("pause");
	return 0;
}