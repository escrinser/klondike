/*
 * Play.h
 *
 *  Created on: 9 oct. 2017
 *      Author: eseogaz
 */

#ifndef PLAY_H_
#define PLAY_H_

class Board;

class Play {
public:
	Play();
	virtual ~Play();

	void startPlay();

	bool hasWon(Board theBoard);
};

#endif /* PLAY_H_ */
