#include <IO.h>

IO* IO::unique_instance = nullptr;

IO::IO(void)
{
}
IO::~IO(void)
{
}

string
IO::readstring(string title)
{
	string input;
	bool ok = false;
	do {
		write(title);
		try {
			cin >> input;
			ok = true;
		} catch (int error) {
			writeError("of chain of characters");
		}
	} while (!ok);
	return input;
}

int
IO::readInt(string title) {
	int input = 0;
	bool ok = false;
	do {
		try
		{
			input = atoi(readstring(title).c_str());
			ok = true;
		}
		catch (int error) {
			writeError("integer");
		}
	} while (!ok);
	return input;
}

void
IO::writeln()
{
	cout << endl;
}

void
IO::write(string string)
{
	cout << string ;
}

void
IO::writeln(string string)
{
	cout << string << endl;
}

void
IO::writeError(string format)
{
	cout << "FORMAT ERROR! Introduce a value with format " << format << "." << endl;
}
