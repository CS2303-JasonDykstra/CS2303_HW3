/*
 * FloorPlan.cpp
 *
 *  Created on: Sep 15, 2019
 *      Author: jasondykstra
 */

#include "FloorPlan.h"

FloorPlan::FloorPlan() {
	// TODO Auto-generated constructor stub
	Production prod;
	edges = prod.readFile().floorPlan;
	nRooms = prod.readFile().numRooms;
	position = 0;
	treasureFound = 0;
	roomsVisited = 0;



	rooms[0].wasVisited();
}

FloorPlan::~FloorPlan() {
	// TODO Auto-generated destructor stub
}

void FloorPlan::listPossibleMoves(){
	cout << "Currently in room: " << position << endl;
	cout << "Possible moves include room(s): ";
	for(int i = 0; i < nRooms; i++){
		if(edges -> isEdge(position, i)){
			cout << i << " ";
		}
	}
	cout << endl;
}

void FloorPlan::moveRooms(){

	int nextRoom = 0;

	cout << "Which room would you like to move to?: ";
	cin >> nextRoom;

	//make sure its a possible move
	bool legal = false;
	for(int i = 0; i < nRooms; i++){
		if(edges -> isEdge(position, nextRoom)){
			legal = true;
		}
	}

	if(legal){
		position = nextRoom;
		if(!rooms[position].getVisited()){
			treasureFound += rooms[position].treasure;
			rooms[position].wasVisited();
			roomsVisited++;
			cout << "You found " << rooms[position].treasure << " treasure in this room!" << endl;
		} else {
			cout << "No treasure found, you've already visited this room." << endl;
		}
		cout << "Total treasure so far: " << treasureFound << endl;
		cout << "Total rooms visited: " << roomsVisited << endl;
	} else {
		cout << "You can not move to this room, please pick a different room." << endl;
	}



}
