#include "panel.h"
#include <sstream>
#include <string>
//Panel ABC implementation
panel::panel()
{
	mark = "X";
    m_cleared = false;
}

std::string panel::print()
{
	return mark;
}

void panel::set_mark(int n)
{
    if(n == 0) {mark = " "; return;}
	std::ostringstream s;
	s << n;
	mark = s.str();
}

panel::~panel() {}

//safepanel derived class implementation
safepanel::safepanel() : panel()
{
//	mark = "X";  //do i need this?
}

safepanel::~safepanel() {}

void safepanel::clear()
{
    set_mark(adjacent());
    m_cleared = true;
    return;
    
}

bool safepanel::mined() { return false;}

//minedpanel derived class implementation
minedpanel::minedpanel() : panel()
{
//	mark = "#";  //do i need this?
}

minedpanel::~minedpanel() {}

bool minedpanel::mined() { return true;}




