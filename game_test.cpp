# include <iostream>
# include <random>


class Game{
	private:
		// bugs -> records the total number of bugs int the game
		// healthy -> returns whether the game is currently healthy or not
		int bugs;
		bool healthy;
		
	public:
		Game(); // constructor for the class
		void getReport(); // get the printed report of the game
		void addBug(); // adds a bug to the game
		void removeBug(); // removes a bug from the game
		int Bugs(); // returns the total number of bugs in the game
		void setBugs(int bug); // sets the amount of bugs for the game
};

// the following are the member function initialization for game class

void Game::setBugs(int bug){
	bugs = bug; // setting the new bugs count	
}

Game::Game(){
	// variables initialized
	bugs = 0;
	healthy = true;	
}

void Game::getReport(){
	// printing the game report
	healthy = (bugs < 3); // updating the health
	std::cout << "Total number of bugs are " << bugs << std::endl;		
	std::cout << ((healthy)? "The game is healthy" : "The game is not healthy" ) << std::endl;
}

void Game::addBug(){
	bugs++; // adding a bug
	if(bugs > 2) healthy = false; // if too many bugs, the game isnt healthy	
}

void Game::removeBug(){
	bugs--; // reducing a bug	
	if(bugs < 3) healthy = true; // if too less bugs, the game is healthy
}

int Game::Bugs(){
	return bugs; // returning the total bug count	
}

// game class ends here

Game game; // game variable in global scope

// runs the test cases for the game
void runTest(){
	// setting up the random seeds and the random gens
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(1, 8);
	// calculated amount of total number of bugs
	int bugs = (game.Bugs() == 0)? dist(mt) : game.Bugs();
	
	// looping through all the test cases
	for(int i = 0, b = bugs; i < 14; i++){
		std::cout << "Test case " << i + 1;
		
		// checking if the game passes a test case or not
		if(mt() % 2 && b != 0){
			std::cout << " failed";
			b--;
		}
		else{
			std::cout << " passed";
		}
		std::cout << std::endl;
	}
	
	// checking if there are bugs outside of test cases
	if(bugs != 0) std::cout << "the other tests failed....";
	else std::cout << "the other tests passed.....";
	
	// updating bugs if there are none
	if(game.Bugs() == 0) game.setBugs(bugs);
	std::cout << std::endl;
}

// fixes bugs in the game
void fixBugs(){
	// only removing bugs if it exists
	if(game.Bugs() != 0){
		std::cout << "Successfully fixed one bug.\n";
		game.removeBug();
	}
}

// execution starts from here
int main(int argc, char** argv){
	int choice; // for user choice
	
	// running the main prog
	do{
		// printing menu and asking user for choice
		std::cout << "\nGame testing panel:\n";
		std::cout << "1. Run Tests\n2. Generate Reports\n3. Track Bugs\n4. Exit\n>> ";
		std::cin >> choice;
		std::cout << std::endl;
		
		// cases based on user choice
		switch(choice){
			case 1:{ // run tests
				runTest();
				break;
			}	
			
			case 2:{ // generate report
				game.getReport();
				break;
			}	
			
			case 3:{ // track bugs
				fixBugs();
				break;
			}	
			
			case 4:{ // exit
				break;
			}
			
			default:{ // not matching with a value
				std::cout << "Invalid choice!";	
			}
		}
	} while(choice != 4 && choice != 0);
	
	return 0;
}
