#include "Game.h"

int main()
{
	/*Program Entry Point*/

	Game game;										//Reference to Class

	while (!game.GetWindow()->IsDone()) 
	{
		/*Game Loop*/

		game.HandleInput();							// Check for Events
		game.Update();								//Update
		game.Render();								//Render
		game.RestartClock();						// Restart Clock


	}
	
}