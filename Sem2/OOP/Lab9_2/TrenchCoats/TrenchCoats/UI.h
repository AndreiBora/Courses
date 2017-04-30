#pragma once
#include "Controller.h"
#include <vector>

class UI
{
private:
	Controller ctrl;
public:
	UI(const Controller& c) :ctrl(c) {}
	void run();
	
private:
	static void printMenu();
	static void printRepositoryMenu();
	static void printUserMenu();
	static void printPlayListMenu();

	void addTshirtUI();
	void deleteTshirtUI();
	void displayAllTshirtsUI();
	void updateTshirtUI();
	void seeTshirtBySizeUI();
	void seeShoppingBasketUI();
	void displayTshirtsByLengthUI();
	void saveShoppingBaskettoFileUI();

};