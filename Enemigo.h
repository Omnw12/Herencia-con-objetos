#pragma once
#include <iostream>

class Character {
private:
	int hp;
	int dmg;
	int shield;
	std::string name;
	int positionx;
	int positiony;
	bool alive;

public:
	Character(int Hhp, int Ddmg, int sShield, std::string Nname, int PpositionX, int PpositionY, bool alive);

	int getHp();

	int getDmg();

	int getShield();

	int getPositionX();

	int getPositionY();

	std::string getName();

	bool getLive();

	void setHp(int Hhp);

	void setDmg(int Ddmg);

	void setShield(int Sshield);

	void setName(std::string Nname);

	void setLive(bool alive);

	void setPositionX(int PpositionX);

	void setPositionY(int PpositionY);

	void chooseWeapon();

	void printInfoEnemy();

	void Fogata(int PpositionY);

};