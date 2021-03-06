#include "Grid.h"


Grid::Grid(){
	
	GameBoard = new int* [10];
	
	for (unsigned i =  0; i < 10; i++){
		
		GameBoard[i] = new int [10];
		memset(GameBoard[i], 0, 10 * sizeof(int));
		
		
	}
	
	
	
	
	
	std:: cout << "Class Array location: " << this->GameBoard << std:: endl;
	
	/*GameBoard[0][0] = 0;
	for(int i = 0; i < 10; ++i){
		for(int j = 0; j < 10; ++j){
			this->GameBoard[i][j] = 0;
		}
	}*/

//	std::cout << GameBoard[0][0] << std::endl;

	// for(int i = 0; i < 10; ++i){
	// 	for(int j = 0; j < 10; ++j){
	// 		std::cout << GameBoard[i][j] << ' ';
	// 	}
	// 	std::cout << std::endl;
	// }



}

Grid::~Grid(){
}

bool Grid::setShip(Ship S, int x1, int y1, int x2, int y2){
	if(!isValid(S, x1, y1, x2, y2)){
		return false;
	}
	
	if(abs(x1 - x2)){           //Vertical Placement
		for(int i = std::min(x1, x2); i <= std::max(x1, x2); ++i){
			GameBoard[i][y1] = 1;
			
		}
	}
	else {						//Horizontal Placement
		for(int i = std::min(y1, y2); i <= std::max(y1, y2); ++i){
			GameBoard[x1][i] = 1;
			
		}
	}
	return true;
		
}

bool Grid::setHit(int x, int y){
	if(x < 0 || x > 9 || y < 0 || y > 9){
		std::cout << "Invalid Shot" << std::endl;
		return false;
	}
	if(GameBoard[x][y] == 2){
		std::cout << "Already Fired" << std::endl;
		return false;
	}

	if(GameBoard[x][y] == 1){
		std::cout << "HIT!" << std::endl;
		--health;
	}
	else{
		std::cout << "MISS" << std::endl;
	}

	GameBoard[x][y] = 2;

	return true;

}

void Grid::printBoard(){
	system("clear");
	std::cout << "--------------------------------------------------" << std::endl;
	for(int i = 0; i < 10; ++i){
		for(int j = 0; j < 10; ++j){
			std::cout << '|';
			if(GameBoard[i][j] == 0){
				std::cout << " 0 |";
			}
			else if(GameBoard[i][j] == 1){
				std::cout << " ~ |";
			}
			else {
				std::cout << " X |";
			}
		}
		std::cout << std::endl << "--------------------------------------------------" << std::endl;
	}
	//std:: cout << GameBoard[0][0] << std::endl;
	//std:: cout << "Address attempted to output: " << GameBoard << std:: endl;
}


bool Grid::isValid(Ship S, int x1, int y1, int x2, int y2){
	if(x1 < 0 || x1 > 9 || x2 < 0 || x2 > 9 || y1 < 0 || y1 > 9 || y2 < 0 || y2 > 9){
		std::cout << "Coordinates out of range" << std::endl;
		return false;
	}
	else if(x1 != x2  && y1 != y2){
		std::cout << "Place ship in straightline pls" << std::endl;
		return false;
	}
	else if(std::max(abs(x1 - x2), abs(y1 - y2)) != S.getSize()){
		std::cout<< "Coordinates do not match size of ship" << std::endl;
		return false;
	}
	if(abs(x1 - x2)){           //Vertical Placement
		for(int i = std::min(x1, x2); i <= std::max(x1, x2); ++i){
			if(GameBoard[i][y1] != 0){
				std:: cout << "Ship collision" << std:: endl;
				return false;
			}
		}
	}
	else {						//Horizontal Placement
		for(int i = std::min(y1, y2); i <= std::max(y1, y2); ++i){
			if(GameBoard[x1][i] != 0){
				std:: cout << "Ship collision" << std:: endl;
				return false;
			}
		}
	}
	
	return true;

}
