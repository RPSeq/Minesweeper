//Panel class

#ifndef PANEL_H
#define PANEL_H

#include <stdlib.h>
#include <iostream>

class panel
{
protected:
	std::string mark;  //for printing minefield. X = covered, 1-8 = proximal mines, blank = uncovered
    bool m_cleared;

public:
	panel();
	std::string print();
	void set_mark(char m) {mark = m;};
	void set_mark(int n);
	virtual ~panel();
    bool cleared() {return m_cleared;};
	virtual void clear() = 0;
	virtual bool mined() = 0;
	virtual void inc_adjacent() = 0;
	virtual int adjacent() = 0;
};

class safepanel : public panel
{
private:
	int adjacent_mines;
	
public:
	safepanel();
	virtual ~safepanel();
	virtual bool mined();
	virtual int adjacent() { return adjacent_mines;};
	virtual void inc_adjacent() {adjacent_mines++;};
	virtual void clear();
};

class minedpanel : public panel
{
public:
	minedpanel();
	virtual ~minedpanel();
	virtual bool mined();
	virtual int adjacent() {return 1;};
	virtual void inc_adjacent() {return;};
	virtual void clear() {return;};
};

#endif

	
	
