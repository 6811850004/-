#include <iostream>
#include <string>

using namespace std;

int main() {

	cout << " **** for **** " << endl;

	for (int i = 2; i <= 20; i += 2) {
		cout << "i: " << i << endl;
	}

	cout << " **** while **** " << endl;

	int i = 2;
	while (i <= 20) {
		cout << i << "\n";
		i += 2;
	}

	cout << " **** do-while **** " << endl;

	int j = 2;
	do {
		cout << j << "\n";
		j += 2;
	} while (j <= 20);

	return 0;
}

