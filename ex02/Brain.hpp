#include <iostream>
#include <string>
#pragma once

class Brain {

	private:
		std::string ideas[100];

	public:
		Brain();
		Brain(const Brain &src);
		~Brain( void );

		Brain &operator=(const Brain &src);
		std::string	getIdea(int i) const;
		void setIdea(int index, std::string idea);
};
