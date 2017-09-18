//
//  game.cpp
//  
//
//  Created by Ryan Smith on 12/18/13.
//
//

#include <iostream>
#include "game.h"

game::game()
{	
	m_moves = 0;
	m_running = false;
	m_player = player();
}

bool game::start()
{	
	m_running = true;
	std::string in;
	std::cout << "Welcome to Minesweeper, please enter your name: ";
	std::getline(std::cin, in);
	m_player.set_name(in);

	int mines;
	std::cout << std::endl << "Enter number of mines on 9x9 grid, between 2 and 40: ";
	std::cin >> mines;
	std::cout << std::endl;
	m_field = new grid(7,7,mines);

	while(m_running)
	{	
		int x;
		int y;
		m_field->display();
		std::cout << "Enter row: ";
		std::cin >> y;
		std::cout << std::endl << "Enter column: ";
		std::cin >> x;
		if((x < m_field->get_width() && x >= 1) && (y < m_field->get_height() && y >= 1))
		{
			m_field->uncover(x-1,y-1);
		}
		m_field->display();
		m_moves++;
		
		std::string buf;
		if(m_field->win())
		{
			std::cout << "Congrats " << m_player.name();
			std::cout << ", you cleared " << mines << " mines in " << m_moves;
			std::cout << " moves!" << std::endl;
			m_moves = 0;
			m_running = false;
			
			std::cout << "Play again? Y/N: ";
			std::cin >> buf;
			if(buf == "Y" || buf == "y") {return true;}
			if(buf == "N" || buf == "n") 
			{
				std::cout << std::endl << "Goodbye, " << m_player.name();
				delete m_field;
				return false;
			}
		}

		if(m_field->lose())
		{
			std::cout << "BOOM! After " << m_moves << " moves, " << m_player.name();
			std::cout << " is dead! Sorry.";
			m_moves = 0;
			m_running = false;
			
			std::cout << "Play again? Y/N: ";
			std::cin >> buf;
			if(buf == "Y" || buf == "n") {return true;}
			if(buf == "N" || buf == "n") 
			{
				std::cout << std::endl << "Goodbye, " << m_player.name();
				delete m_field;
				return false;
			}
		}
		
		
	}
}
		
		

	
	

	
	


	
	

	
