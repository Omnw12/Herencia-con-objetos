#pragma once
#include <iostream>
#include "Enemigo.h";

class FinalBoss : public Character{
private:
	int fireball;
	int thunder;

public:
	FinalBoss(int Hhp, int Ddmg, int sShield, std::string Nname, int PpositionX, int PpositionY, bool aAilve, int fFireball, int tThunder);

	int getFireball();

	int getThunder();

	void setFireball(int fFireball);

	void setThunder(int tThunder);

};