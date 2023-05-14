# include <iostream>

// function to reduce syntax for input
inline std::string input(std::string msg){
	std::string inp; // to store the input
	
	// asking user for the input
	std::cout << msg;
	std::cin >> inp;
	
	// returning the input
	return inp;
}

// getting the input from user about a bank user
int getInput(std::string &name){
	int bal, no; // variable declaration
	
	// asking for user details
	name = input("Enter the name: ");
	bal = std::stoi(input("Enter the bank balance: "));
	no = std::stoi(input("Enter the account number: "));
	
	// returning the balance
	return bal;		
}

// execution starts from here
int main(int argc, char** argv){
	// variable declaration
	int count = std::stoi(input("How many account holders you want? "));
	int lowest = 0, amt;
	std::string name;
	
	// looping for count times
	for(int i = 1; i <= count; i++){
		// asking for person details
		std::cout << "\nEnter the details for person " << i << ":\n";
		amt = getInput(name);
		
		// checking if it is the first iteration
		if(i != 1) lowest = std::min(lowest, amt);
		else lowest = amt;
	}
	
	// printing the guy with the lowest amount
	std::cout << "The lowest amount of cash holder the following is " << name << " with $" << lowest;
	return 0;
}
