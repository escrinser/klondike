/*
 * Controller.cpp
 *
 *  Created on: 10 nov. 2017
 *      Author: eseogaz
 */

#include "Controller.h"

#include "../models/State.h"
#include "../models/Game.h"

Controller::Controller(shared_ptr<Game> theGame) {
	game = theGame;
}

Controller::~Controller() {
	// TODO Auto-generated destructor stub
}

State Controller::getState() {
	return game->getState();
}

void Controller::setState(State state) {
	game->setState(state);
}

//TODO: clear game
void Controller::clear() {
	game->clear();
}

bool Controller::hasWon() {
	return game->hasWon();
}

shared_ptr<Game> Controller::getGame() {
	return game;
}
