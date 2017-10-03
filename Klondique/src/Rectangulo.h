/*
 * Rectangulo.h
 *
 *  Created on: 3 oct. 2017
 *      Author: Ana
 */

#ifndef RECTANGULO_H_
#define RECTANGULO_H_

class Rectangulo {
public:
	Rectangulo();
	virtual ~Rectangulo();
	Rectangulo (int,int);
	int area () {return (width*height);}
  private:
	int width, height;
};

#endif /* RECTANGULO_H_ */
