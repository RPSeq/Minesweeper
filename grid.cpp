//
//  grid.cpp
//  
//
//  Created by Ryan Smith on 12/16/13.
//
//
#include <iostream>
#include <stdlib.h>
#include "grid.h"

grid::grid(){}

grid::grid(int x, int y, int n)
{   //grid constructor
	width = x;
	height = y;
	mines = n;
	cleared_count = 0;
	m_win = false;

    array.resize(x*y);
	for(int i = 0; i < x*y; i++)
	{	//this should work, as array[h] should be a panel*
		array[i] = new safepanel();
	}

	srand(unsigned(time(0)));

	for(int i = 0; i < mines; i++)  //place mines on board
	{
		bool set = false;
		while(!set)
		{
			int index = rand() % (x*y);
			
			if(!(array[index]->mined()))	//if the panel isn't mined, make it a minedpanel.
			{
				delete array[index];
				array[index] = new minedpanel();
				set = true;
			}
		}
	}
	
	//count mines next to safe panels
	for(int i=0; i<width; i++)
	{
		for(int j=0; j<height; j++)
		{
			minecount(i,j);
		}
	}
}

grid::~grid()
{
	for(int k = 0; k < width*height; k++)
	{
		delete array[k];
	}
}

panel* grid::index(int x, int y)
{   try {
    if(x < 0 || x > width || y < 0 || y > width) { throw "index_fault";}
    } catch (const char * error) { std::cout << error << std::endl;}
    return array[x * width + y];
}

void grid::minecount(int x, int y)
{
	panel* current = index(x,y);
    if(x >= width || y >= height) {return;}
	if(current->mined()) {return;}
	
    if(x > 0 && y > 0) 
	{
        if(index(x-1,y-1)->mined()) {current->inc_adjacent();}
    }
	
    if(y > 0) 
	{
        if(index(x,y-1)->mined()) {current->inc_adjacent();}
    }
	
    if(x < width-1 && y > 0)
	{
        if(index(x+1,y-1)->mined()) {current->inc_adjacent();}
    }
	
    if(x > 0) 
	{
        if(index(x-1,y)->mined()) {current->inc_adjacent();}
    }
	
    if(x < width-1) 
	{
        if(index(x+1,y)->mined()) {current->inc_adjacent();}
    }
	
    if(x > 0 && y < height-1) 
	{
        if(index(x-1,y+1)->mined()) {current->inc_adjacent();}
    }
	
    if(y < height-1) 
	{
        if(index(x,y+1)->mined()) {current->inc_adjacent();}
    }
	
    if(x < width-1 && y < height-1) 
	{
        if(index(x+1,y+1)->mined()) {current->inc_adjacent();}
    }
    return;
}

void grid::uncover(int x, int y)
{
	if(index(x,y)->mined()){ index(x,y)->set_mark('#'); m_lose = true; return;}
    if(index(x,y)->cleared())
    {
        std::cout << "Panel has already been cleared!";
        return;  //need an exception object here.
    }
    expand(x,y);
	if(cleared_count >= (width*height) - mines) { m_win = true;};
    return;
}

void grid::expand(int x, int y)
{
    if((x < 0 || x > width-1) || (y < 0 || y > height-1)) {return;}
    if(index(x,y)->cleared()) {return;}
    if(index(x,y)->mined()) {return;}
    
    index(x,y)->clear();
	cleared_count++;
    
    if((index(x,y)->adjacent()) == 0)
    {
        expand(x-1,y);
        expand(x-1,y-1);
        expand(x-1,y+1);
        expand(x,y-1);
        expand(x,y+1);
        expand(x+1,y);
        expand(x+1,y+1);
        expand(x+1,y-1);
    }
    return;
}

void grid::display()
{
	std::cout << "   ";
    for(int x = 0; x < width; x++) {
        std::cout << (x + 1) << " ";
    }
    std::cout << std::endl << "";
    for(int x = 0; x < width; x++) {
        std::cout << "";
    }
    std::cout << std::endl;
    for(int y = 0; y < height; y++)
	{
        std::cout << (y + 1) << "  ";
        for(int x = 0; x < width; x++)
		{
			std::cout << (index(x,y)->print()) << " ";
        }
 
        std::cout << std::endl;
    }
	std::cout << std::endl;
}







