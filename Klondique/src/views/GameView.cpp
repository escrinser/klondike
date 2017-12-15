#include <GameView.h>

#include "../controllers/GameController.h"

#include "../utils/LimitedInDialog.h"

#include "BoardView.h"

GameView::GameView() {

}

GameView::~GameView() {
}

void
GameView::interact(GameController* gameController)
{
	LimitedInDialog cardDialog ("Card Number?", MIN_NUMBER_OF_CARDS, MAX_NUMBER_OF_CARDS);

	LimitedInDialog pileDialog ("Pile Number?", MIN_NUMBER_OF_PILES, MAX_NUMBER_OF_PILES);

	int movement;

	int pileNumberOrigin;
	int pileNumberDestination;
	int pileNumberOriginNumber = 0;

	LimitedInDialog mainMenuDialog ("Chose one option:\n\n"
			"1  Deal\n"
			"2  Move a card between Waste Pile to Pile\n"
			"3  Move a card between Piles\n"
			"4  Move a card between Pile to Foundation\n"
			"5  Move a card between Waste Pile to Foundation\n"
			"6  Undo\n"
			"7  Menu\n"
			"Enter your choice and press return:", MENU_OPTION_1, MENU_OPTION_7);

	do
	{
		BoardView(gameController).showBoard();
		movement = mainMenuDialog.read();
		switch (movement)
		{
		   case 1:
			   cout << "Deal a card"<<endl;
			   gameController->deal();
			   break;

		   case 2:
			   cout << "Move a card between Waste Pile to Pile"<<endl;
			   gameController->moveBetweenWastePileAndPile(pileDialog.read());
			   break;

		   case 3:
		   {
			   cout << "Move card/cards between Piles"<<endl;
			   cout << "Origin Pile"<<endl;
			   pileNumberOrigin = pileDialog.read();

			   cout << "\nIs the last card? (yes/no)";
			   string lastCard;

			   cin >> lastCard;
			   if (lastCard == "no")
			   {
				   cout << "\nPile Origin Card Number: ";
				   pileNumberOriginNumber = cardDialog.read();
			   }
			   else
			   {
				   pileNumberOriginNumber = 0;
			   }

			   cout << "Destination Pile"<<endl;
			   pileNumberDestination = pileDialog.read();
			   if (pileNumberOriginNumber != 0)
			   {
				   cout << "Pile Origin: " << pileNumberOrigin << " number: " << pileNumberOriginNumber <<" Pile Destination: " << pileNumberDestination  << endl;
			   }
			   else
			   {
				   cout << "Pile Origin: " << pileNumberOrigin << " Pile Destination: " << pileNumberDestination  << endl;
			   }

			   if (pileNumberOrigin == pileNumberDestination)
			   {
				   cout << "Impossible movement, the same pile. Pile Origin: " << pileNumberOrigin << " and Pile Destination: " << pileNumberDestination  << endl;
				   break;
			   }

			   gameController->moveBetweenPiles(pileNumberOrigin, pileNumberDestination, pileNumberOriginNumber);
			   break;
		   }
		   case 4:
		   {
			   cout << "Move a card between Pile and Foundation"<<endl;
			   gameController->moveBetweenPileAndFoundation(pileDialog.read());

			   break;
		   }
		   case 5:
		   {
			   cout << "Move a card between Waste Pile and Foundation"<<endl;
			   gameController->moveBetweenWastePileAndFoundation();
			   break;
		   }
		   case 6:
		   {
			   cout << "GameView::Undo"<<endl;
			   gameController->undo();
			   break;
		   }
		   case 7:
		   {
			   cout << "GameView::Redo"<<endl;
			   gameController->redo();
			   break;
		   }
		   case 8:
			   break;

		   default:
			   break;
		}
	}
	while ((movement != MENU_OPTION_8) && (!gameController->hasWon()));

	if (gameController->hasWon())
	{
		cout << "You win!!" << endl;
	}

	gameController->setState(State::FINAL);
}


