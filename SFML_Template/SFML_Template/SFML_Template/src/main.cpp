//Adding in additional libraries.
#include "../include/Game.h"

//Main.
int main()
{
	//Using a random seed.
	srand(static_cast<unsigned int>(time(0)));
	//int iRandomNumber = rand();
	//cout << iRandomNumber << endl;

	//Sets up a game.
	Game game;

	//Runs game.
	game.run();

	//End of application.
	return 0;
}