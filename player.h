//Player class
#include <iostream>
#include <stdlib.h>

class player
{
private:
	std::string m_name;
	
public:
	player() {};
	~player() {};
	void set_name(std::string name) {m_name = name;};
	std::string name() {return m_name;};
};
