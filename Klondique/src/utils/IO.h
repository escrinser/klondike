#ifndef UTILS_IO_H_
#define UTILS_IO_H_

#include <iostream>

using namespace std;

class IO {
private:
	IO(void);
	static IO* unique_instance;

	void writeError(string format);

public:
	~IO(void);

	static IO* getInstance()
	{
		if(unique_instance == nullptr)
		{
			unique_instance = new IO();
		}
		return unique_instance;
	}

	string readstring(string title);

	int readInt(string title);

	//char readChar(string title);

	void writeln();

	void write(string string);

	void writeln(string string);
};

#endif /* UTILS_IO_H_ */
