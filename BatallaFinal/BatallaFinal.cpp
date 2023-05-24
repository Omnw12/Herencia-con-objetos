#include <iostream>
#include "FinalBoss.h";
#include <Windows.h>
#include "Enemigo.h";

Character::Character(int Hhp, int Ddmg, int sShield,  std::string Nname, int PpositionX, int PpositionY, bool aAlive) {
	hp = Hhp;
	dmg = Ddmg;
	shield = sShield;
	name = Nname;
	positionx = PpositionX;
	positiony = PpositionY;
	alive = aAlive;
}


int Character::getHp() {
	return hp;
}

int Character::getDmg() {
	return dmg;
}

int Character::getShield() {
	return shield;
}

int Character::getPositionX() {
	return positionx;
}

int Character::getPositionY() {
	return positiony;
}

bool Character::getLive() {
	return alive;
}

std::string Character::getName() {
	return name;
}

void Character::setHp(int Hhp) {
	hp = Hhp;
}

void Character::setDmg(int Ddmg) {
	dmg = Ddmg;
}

void Character::setName(std::string Nname) {
	name = Nname;
}

void Character::setShield(int Sshield) {
	shield = Sshield;
}

void Character::setLive(bool aAlive) {
	alive = aAlive;
}
void Character::setPositionX(int PpositionX) {
	positionx = PpositionX;
}

void Character::setPositionY(int PpositionY) {
	positiony = PpositionY;
}

void Character::chooseWeapon() {
	int opcion = 0;
	while (opcion != 1 && opcion != 2 && opcion != 3) {
		std::cout << "¿Que arma quieres escoger para pelear a los diferentes enemigos?" << "\n";
		std::cout << "1.Espada y escudo" << "    ""2.Mandoble" << "    " << "3.Martillo" << "\n";
		std::cout << "Dmg= 100" << "             " << "Dmg=200 " << "      "     "Dmg=150" << "\n";
		std::cout << "Shield = 100" << "          " << "Shield = 0" << "    " << "Shield = 50" << "\n";
		std::cout << "Elige una :"; std::cin >> opcion;

		if (opcion == 1) {
			setDmg(100);
			setShield(100);
			std::cout << "El heroe " << getName() << " dispondra de " << getHp() << " puntos de vida, " << getDmg() << " puntos de danyo y dispondra de un escudo ""\n";
			std::cout << "que podra parar " << getShield() << " puntos de danyo de los enemigos." << "\n";
		}
		else if (opcion == 2) {
			setDmg(200);
			setShield(0);
			std::cout << "El heroe " << getName() << " dispondra de " << getHp() << " puntos de vida, " << getDmg() << " puntos de danyo y no tendra escudo. ""\n";
		}
		else if (opcion == 3) {
			setDmg(150);
			setShield(50);
			std::cout << "El heroe " << getName() << " dispondra de " << getHp() << " puntos de vida, " << getDmg() << " puntos de danyo y dispondra de un escudo ""\n";
			std::cout << "que podra parar " << getShield() << " puntos de danyo de los enemigos." << "\n";
		}
	}
}

void Character::printInfoEnemy() {
	std::cout << "Te has cruzado con el enemigo " << getName() << ". Te enfrentaras a una batalla a muerte contra el.""\n";
	std::cout << "Dispone de " << getHp() << " puntos de vida y te inflingira " << getDmg()  << " puntos de danyo por cada golpe.""\n";
	std::cout << "Que comience el combate a muerte!""\n";
}

void Character::Fogata(int PpositionY) {
	if (PpositionY == 3 || PpositionY == 5 || PpositionY == 7 ) {
		std::cout << "Has llegado a una zona de descanso. ""\n";
		if (getHp() == 500) {
			std::cout << " Dispones de la vida maxima no puedes curarte" << "\n";
		}
		else if (getHp() >= 350) {
			setHp(500);
			std::cout << "Ahora tienes " << getHp() << " puntos de vida""\n";
		}
		else if(getHp()<350) {
			setHp(hp + 150);
			std::cout << "Tienes " << getHp() << " puntos de vida""\n";
		}
	}
}


