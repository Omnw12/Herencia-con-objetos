#include <iostream>
#include "FinalBoss.h";
#include "Enemigo.h";

int tablero [10][5];
std::string Name;
int life = 500;
std::string w;
int height = 10;
int width = 5;
int positionx = 0;
int positiony = 0;
bool muerte = false;
bool juegofinal = true;


void introgame() {
	std::cout << "Bienvenido Heroe a la Prueba de la perdicion." << "\n";
	std::cout << "La prueba consistira en un tablero donde te podras enfrentar a diferentes enemigos. Deberas llegar al final de la cueva para poder pasar la prueba" << "\n";
}

void comenzarJuego(){
	std::cout << "Escribe w para adentrarte en la cueva" << "\n";
	std::cin >> w;
}
int randomposicion(int positionX) {
    positionX = rand() % 5;
    return positionX;
}
bool acabarpelea(bool enemigovivo) {
    enemigovivo = false;
    return enemigovivo;
}
int peleaEnemigo(bool enemigovivo,int heroevida, int enemigovida, int dmgvillano,int dDmgheroe, int sShield, std::string enemyName) {
    while (enemigovivo && juegofinal) {
        std::cout << "Atacas primero.""\n";
        enemigovida = enemigovida - dDmgheroe;
        std::cout << "Le zurras una hostia y lo dejas a " << enemigovida << " puntos de vida""\n";
        if (enemigovida > 0) {
            std::cout << "El enemigo te va a atacar. Protegete""\n";
            if (sShield > 0) {
                heroevida = (heroevida + sShield) - dmgvillano;
                std::cout << "El enemigo te ataca y te deja a " << heroevida << " puntos de vida""\n";
            }
            else if (sShield == 0) {
                heroevida = heroevida - dmgvillano;
                std::cout << "No te puedes proteger. El ataque te da de lleno y te deja a " << heroevida << " puntos de vida""\n";

            }
        }
        else if (enemigovida <= 0) {
            std::cout << "Has derrotado al enemigo " << enemyName << "\n";
            enemigovivo = false;
            return heroevida;
        }
        if (heroevida <= 0) {
            std::cout << "Has sido derrotado y no has superado la Prueba de la perdicion""\n";
            std::cout << "GAME OVER""\n";
            juegofinal=false;
        }
   } 
}
void printBoard(int playerX, int playerY, int enemigoX, int enemigoY, int enemigo1X, int enemigo1Y, int enemigo2X, int enemigo2Y, int enemigo3X, int enemigo3Y,  bool enemigovivo, bool enemigo1vivo, bool enemigo2vivo, bool enemigo3vivo) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (x == playerX && y == playerY) {
                std::cout << "H ";  
            }
            else if (x == enemigoX && y == enemigoY) {
                if (enemigovivo) {
                    std::cout << "C ";
                }
            }
            else if (x == enemigo1X && y == enemigo1Y) {
                if (enemigo1vivo) {
                    std::cout << "M ";
                }
            }
            else if (x == enemigo2X && y == enemigo2Y) {
                if (enemigo2vivo) {
                    std::cout << "K ";
                }
            }
            else if (x == enemigo3X && y == enemigo3Y) {
                if (enemigo3vivo) {
                    std::cout << "A ";
                }
            }
            else {
                std::cout << "  "; 
            }
        }
        std::cout << "\n";
    }
}


std::string askName() {
	std::cout << "Cual es tu nombre?" << "\n";
	std::cin >> Name;
	return Name;

}

int main() {
    Character Heroe(life, 0, 0, askName(), positionx, positiony, true);
    Character Villano1(300, 100, 0, "El Caballero del Sol", 2, 2, true);
    Character Villano2(450, 150, 0, "Manus", 4, 4, true);
    Character Villano3(600, 200, 0, "Maliketh", 1, 6, true);
    Character Villano4(850, 250, 0, "Artorias ", 0, 8, true);
    FinalBoss ElMandamas(1000, 50, 100, "Gwyn Senyo de Cinder ", 0, 0, 300, 150, true);
    srand(time(NULL));
    introgame();

    Heroe.chooseWeapon();
    do {
        comenzarJuego();
    } while (w != ("w"));
    char move;
    while (juegofinal) {
        printBoard(Heroe.getPositionX(), Heroe.getPositionY(), Villano1.getPositionX(), Villano1.getPositionY(), Villano2.getPositionX(), Villano2.getPositionY(), Villano3.getPositionX(), Villano3.getPositionY(), Villano4.getPositionX(), Villano4.getPositionY(), Villano1.getLive(), Villano2.getLive(), Villano3.getLive(), Villano4.getLive());

        std::cout << "Ingresa una dirección de movimiento (w/a/s/d) ";
        std::cin >> move;

        switch (move) {
        case 'w':
            if (Heroe.getPositionY() > 0) {
                positiony--;
                Heroe.setPositionY(positiony);
            }
            break;
        case 'a':
            if (Heroe.getPositionX() > 0) {
                positionx--;
                Heroe.setPositionX(positionx);
            }
            break;
        case 's':
            if (Heroe.getPositionY() < height - 1) {
                positiony++;
                Heroe.setPositionY(positiony);
            }
            break;
        case 'd':
            if (Heroe.getPositionX() < width - 1) {
                positionx++;
                Heroe.setPositionX(positionx);
            }
            break;
        default:
            std::cout << "Dirección inválida. Intenta nuevamente." << std::endl;
            break;
        }
        std::cout << "Tu posicion es " << Heroe.getPositionX() << ", " << (Heroe.getPositionY()) << "\n";
        Heroe.Fogata(Heroe.getPositionY());
        Villano1.setPositionX(randomposicion(Villano1.getPositionX()));
        Villano2.setPositionX(randomposicion(Villano2.getPositionX()));
        Villano3.setPositionX(randomposicion(Villano3.getPositionX()));
        Villano4.setPositionX(randomposicion(Villano4.getPositionX()));
        if (Heroe.getPositionX() == Villano1.getPositionX() && Heroe.getPositionY() == Villano1.getPositionY()) {
            Villano1.printInfoEnemy();
            //peleaEnemigo(enemigo1vivo, Heroe.getHp(), Villano1.getHp(), Villano1.getDmg(), Heroe.getDmg(), Heroe.getShield(), Villano1.getName());
            Heroe.setHp(peleaEnemigo(Villano1.getLive(), Heroe.getHp(), Villano1.getHp(), Villano1.getDmg(), Heroe.getDmg(), Heroe.getShield(), Villano1.getName()));
            Villano1.setLive(false);
        }
        else if (Heroe.getPositionX() == Villano2.getPositionX() && Heroe.getPositionY() == Villano2.getPositionY()) {
            Villano2.printInfoEnemy();
            //peleaEnemigo(enemigo2vivo, Heroe.getHp(), Villano2.getHp(), Villano2.getDmg(), Heroe.getDmg(), Heroe.getShield(), Villano2.getName());
            Heroe.setHp(peleaEnemigo(Villano2.getLive(), Heroe.getHp(), Villano2.getHp(), Villano2.getDmg(), Heroe.getDmg(), Heroe.getShield(), Villano2.getName()));
            Villano2.setLive(false);
        }
        else if (Heroe.getPositionX() == Villano3.getPositionX() && Heroe.getPositionY() == Villano3.getPositionY()) {
            Villano3.printInfoEnemy();
            //peleaEnemigo(enemigo3vivo, Heroe.getHp(), Villano3.getHp(), Villano2.getDmg(), Heroe.getDmg(), Heroe.getShield(), Villano3.getName());
            Heroe.setHp(peleaEnemigo(Villano3.getLive(), Heroe.getHp(), Villano3.getHp(), Villano2.getDmg(), Heroe.getDmg(), Heroe.getShield(), Villano3.getName()));
        }
        else if (Heroe.getPositionX() == Villano4.getPositionX() && Heroe.getPositionY() == Villano4.getPositionY()) {
            Villano4.printInfoEnemy();
            //peleaEnemigo(enemigo4vivo, Heroe.getHp(), Villano4.getHp(), Villano4.getDmg(), Heroe.getDmg(), Heroe.getShield(), Villano4.getName());
            Heroe.setHp(peleaEnemigo(Villano4.getLive(), Heroe.getHp(), Villano4.getHp(), Villano4.getDmg(), Heroe.getDmg(), Heroe.getShield(), Villano4.getName()));

        }
        if (Heroe.getPositionY() == 9) {
            juegofinal = false;
            std::cout << "Has llegado al ultimo desafio. La Batalla Final""\n";
            std::cout << "Para poder superar la Prueba de la perdicion tendras que superar el ultimo combate""\n";
            ElMandamas.printInfoEnemy();
            Heroe.setHp(peleaEnemigo(ElMandamas.getLive(), Heroe.getHp(), ElMandamas.getHp(), ElMandamas.getDmg(), Heroe.getDmg(), Heroe.getShield(),ElMandamas.getName()));
        }
    }

    return 0;
}