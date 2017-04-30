#pragma once
#include <vector>
#include "Tshirt.h"

class TshirtList {
private:
	std::vector<Tshirt> tshirts;
	int current;
public:
	//Default constructor
	TshirtList();
	/* Returns true if the playlist can start (is not empty) or false otherwise. */
	bool start();

	/* Returns true if the playlist can advance to the next tutorial (is not empty) or false otherwise.
	* Playlist is circular (when it reaches end, it starts again). */
	//bool next();

	void add(const Tshirt& tshirt);

	int getSize();
	Tshirt& getCurrent();
	void display();
	void displayNext();
	void clear();
};