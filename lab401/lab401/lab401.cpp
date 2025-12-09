#include <iostream>
#include <string>

using namespace std;

int main() {

	cout << " **** for **** " << endl;
	for (int i = 1; i <= 10; i++) {
		cout << i << " " << endl;
	}

	cout << " **** while **** " << endl;

	int i = 1;
	while (i <= 10) {
		cout << i << " " << endl;
		i++;
	}

	cout << " **** do-while **** " << endl;

	i = 1;
	do {
		cout << i << " " << endl;
		i++;
	} while (i <= 10);

	return 0;
}


