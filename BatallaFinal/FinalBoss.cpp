#include "FinalBoss.h";
#include <iostream>
#include <Windows.h>
#include "Enemigo.h";

FinalBoss::FinalBoss(int Hhp, int Ddmg, int sShield, std::string Nname, int PpositionX, int PpositionY, bool aAlive, int fFireball, int tThunder) :Character
(Hhp, Ddmg, sShield, Nname, aAlive, PpositionX, PpositionY)
{
	fireball = fFireball;
	thunder = tThunder;
}

int FinalBoss::getFireball() {
	return fireball;
}

int FinalBoss::getThunder() {
	return thunder;
}

void FinalBoss::setFireball(int fFireball) {
	fireball = fFireball;
}

void FinalBoss::setThunder(int tThunder) {
	thunder = tThunder;
}
void FinalBoss::lanzarRayodeSol(int bosshp) {
	if (bosshp <= 0) {
		std::cout << "" "\n";
	}
}

