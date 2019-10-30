/*
 * Room.h
 *
 *  Created on: Sep 15, 2019
 *      Author: jasondykstra
 */

#ifndef ROOM_H_
#define ROOM_H_

#include <cstdlib>
#include <iostream>

class Room {
public:
	int treasure;
	bool hasBeenVisited;
	Room();
	virtual ~Room();
	bool hasTreasure();
	void wasVisited();
	bool getVisited();
};

#endif /* ROOM_H_ */
