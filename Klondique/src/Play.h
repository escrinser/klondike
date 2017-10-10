/*
 * Play.h
 *
 *  Created on: 9 oct. 2017
 *      Author: eseogaz
 */

#ifndef PLAY_H_
#define PLAY_H_

class Play {
public:
	Play();
	virtual ~Play();

	void startPlay();
	int chooseMovement(int thePileNumberOrigin, int thePileNumberDestination);
};

#endif /* PLAY_H_ */
