#include <iostream>
#include "FinalBoss.h";
#include "Enemigo.h";
#include <windows.h>

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
	std::cout << "La prueba consistira en una cueva donde varios desafios te aguardan. Deberas llegar al final de la cueva para poder pasar la prueba." << "\n";
}

void comenzarJuego(){
	std::cout << "Escribe w para adentrarte en la cueva." << "\n";
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
        std::cout << "Le zurras una hostia y lo dejas a " << enemigovida << " puntos de vida.""\n";
        if (enemigovida > 0) {
            std::cout << "El enemigo te va a atacar. Protegete.""\n";
            if (sShield > 0) {
                heroevida = (heroevida + sShield) - dmgvillano;
                std::cout << "El enemigo te ataca y te deja a " << heroevida << " puntos de vida.""\n";
            }
            else if (sShield == 0) {
                heroevida = heroevida - dmgvillano;
                std::cout << "No te puedes proteger. El ataque te da de lleno y te deja a " << heroevida << " puntos de vida.""\n";

            }
        }
        else if (enemigovida <= 0) {
            std::cout << "Has derrotado al enemigo " << enemyName << ".\n";
            enemigovivo = false;
            return heroevida;
        }
        if (heroevida <= 0) {
            std::cout << "Has sido derrotado y no has superado la Prueba de la perdicion.""\n";
            std::cout << "GAME OVER""\n";
            juegofinal=false;
        }
        Sleep(3000);
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
    Character Villano2(400, 125, 0, "Manus", 4, 4, true);
    Character Villano3(450, 150, 0, "Maliketh", 1, 6, true);
    Character Villano4(500, 175, 0, "Artorias", 0, 8, true);
    FinalBoss ElMandamas(2000,100,50, "Gwyn Senyor de Cinder ",0,9,true,300,150);
    srand(time(NULL));
    introgame();
    Sleep(2000);
    Heroe.chooseWeapon();
    Sleep(2000);
    do {
        comenzarJuego();
    } while (w != ("w"));
    system("cls");
    char move;
   
    while (juegofinal) {
        printBoard(Heroe.getPositionX(), Heroe.getPositionY(), Villano1.getPositionX(), Villano1.getPositionY(), Villano2.getPositionX(), Villano2.getPositionY(), Villano3.getPositionX(), Villano3.getPositionY(), Villano4.getPositionX(), Villano4.getPositionY(), Villano1.getLive(), Villano2.getLive(), Villano3.getLive(), Villano4.getLive());
        Sleep(3000);
        std::cout << "Ingresa una dirección de movimiento (w/a/s/d): ";
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
        Heroe.Fogata(Heroe.getPositionY());
       
        Villano1.setPositionX(randomposicion(Villano1.getPositionX()));
        Villano2.setPositionX(randomposicion(Villano2.getPositionX()));
        Villano3.setPositionX(randomposicion(Villano3.getPositionX()));
        Villano4.setPositionX(randomposicion(Villano4.getPositionX()));
        if (Heroe.getPositionX() == Villano1.getPositionX() && Heroe.getPositionY() == Villano1.getPositionY()) {
            system("cls");
            Villano1.printInfoEnemy();
            Heroe.setHp(peleaEnemigo(Villano1.getLive(), Heroe.getHp(), Villano1.getHp(), Villano1.getDmg(), Heroe.getDmg(), Heroe.getShield(), Villano1.getName()));
            
            Villano1.setLive(false);
        }
        else if (Heroe.getPositionX() == Villano2.getPositionX() && Heroe.getPositionY() == Villano2.getPositionY()) {
            system("cls");
            Villano2.printInfoEnemy();
            Heroe.setHp(peleaEnemigo(Villano2.getLive(), Heroe.getHp(), Villano2.getHp(), Villano2.getDmg(), Heroe.getDmg(), Heroe.getShield(), Villano2.getName()));
            
            Villano2.setLive(false);
        }
        else if (Heroe.getPositionX() == Villano3.getPositionX() && Heroe.getPositionY() == Villano3.getPositionY()) {
            system("cls");
            Villano3.printInfoEnemy();
            Heroe.setHp(peleaEnemigo(Villano3.getLive(), Heroe.getHp(), Villano3.getHp(), Villano2.getDmg(), Heroe.getDmg(), Heroe.getShield(), Villano3.getName()));
            
            Villano3.setLive(false);
        }
        else if (Heroe.getPositionX() == Villano4.getPositionX() && Heroe.getPositionY() == Villano4.getPositionY()) {
            system("cls");
            Villano4.printInfoEnemy();
            Heroe.setHp(peleaEnemigo(Villano4.getLive(), Heroe.getHp(), Villano4.getHp(), Villano4.getDmg(), Heroe.getDmg(), Heroe.getShield(), Villano4.getName()));
            Sleep(3000);
            Villano4.setLive(false);

        }
        if (Heroe.getPositionY() == 9) {
            system("cls");
            juegofinal = false;
            std::cout << "Has conseguido salir de la mazmorra victorioso y has llegado al ultimo desafio. LA BATALLA FINAL.""\n";
            Sleep(2000);
            std::cout << "Para poder superar la Prueba de la perdicion tendras que superar el ultimo combate.""\n";
            Sleep(2000);
            Heroe.setHp(1500);
            Heroe.setDmg(300);
            int option;
            std::cout << "Se te aumenta la vida a 1500 y se te aumenta el danyo en 100 puntos.""\n";
            Sleep(2000);
            std::cout << "Empieza el combate.""\n";
            Sleep(2000);
            system("cls");
            while (ElMandamas.getLive()== true) {
                option = rand() % 10;
                std::cout << ElMandamas.getName() << " atacara primero.""\n";
                if (ElMandamas.getHp() > 0) {
                    if (option >= 0 && option <=6) {
                        Heroe.setHp((Heroe.getHp() + Heroe.getShield()) - ElMandamas.getThunder());
                        std::cout << "El enemigo te invoca un rayo del cielo que te deja a " << Heroe.getHp() << " puntos de vida.""\n";
                    }
                    else if (option > 6 && option <=9) {
                        Heroe.setHp((Heroe.getHp() + Heroe.getShield()) - ElMandamas.getFireball());
                        std::cout << "El enemigo invoca una lluvia de meteoritos que te deja a " << Heroe.getHp() << " puntos de vida.""\n";
                    }
                    std::cout << "Es tu turno Heroe. ""\n";
                    ElMandamas.setHp((ElMandamas.getHp()+ ElMandamas.getShield()) - Heroe.getDmg());
                    std::cout << "Golpeas a " << ElMandamas.getName() << " y le dejas a " << ElMandamas.getHp() << " puntos de vida.""\n";
                }
                else if (ElMandamas.getHp() <= 0) {
                    std::cout << "Has derrotado al enemigo " << ElMandamas.getName() << ".\n";
                    ElMandamas.setLive(false);
                }
                if (Heroe.getHp() <= 0) {
                    std::cout << "Has sido derrotado y no has superado la Prueba de la perdicion.""\n";
                    std::cout << "GAME OVER""\n";
                    ElMandamas.setLive(false);
                }
                Sleep(3000);
            }
            
        }
        system("cls");
  
    }

    return 0;
}