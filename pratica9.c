#include <stdio.h>
#include <stdlib.h>

typedef struct Guerreiro {
	int ataque;
	int defesa;
	int carisma;
	int pontos_vida;
	int id_guerreiro;
} Guerreiro;

int rolaDado() {
    int temp = 1+rand()%6;
	return temp;
}
int rolaDados() {
	int valor = rolaDado() + rolaDado() + rolaDado();
	return valor;
}
void imprimeGuerreiro(Guerreiro g) {
	printf("Pontos de vida restantes: %d", g.pontos_vida);
}
int random_vida() {
	return rolaDados() + rolaDados() + rolaDados();
}
int random_ataque() {
	return rolaDados();
}
int random_defesa() {
	return rolaDados();
}
int random_carisma() {
	return rolaDados();
}

int bonusCarisma(int vc) {
	int bc = 0;
	switch (vc){

		case 18:
			bc = 3;
			return bc;
			break;

		case 17:
		case 16:
			bc = 2;
			return bc;
			break;

		case 15:
		case 14:
			bc = 1;
			return bc;
			break;

		case 6:
		case 7:
			bc = -1;
			return bc;
			break;

		case 4:
		case 5:
			bc = -2;
			return bc;
			break;

		case 3:
			bc = -3;
			return bc;
			break;

		default:
			bc = 0;
			return bc;
			break;
	}
}

void criaGuerreiro(Guerreiro *g, int id_guerreiro) {
	g->ataque = random_ataque();
	g->defesa = random_defesa();
	g->carisma = random_carisma();
	g->pontos_vida = random_vida();
	g->id_guerreiro = id_guerreiro;		
}

void ataca(Guerreiro *g1, Guerreiro *g2) {
	int golpe = rolaDados() + g1->ataque + bonusCarisma(g1->carisma);
	int escudo = rolaDados() + g2->defesa + bonusCarisma(g2->carisma);
	int dano = golpe - escudo;
	
	if(dano > 0) {
		g2->pontos_vida -= dano;
	}
}

void jogo(Guerreiro guerreiros[]){
    criaGuerreiro(&guerreiros[0], 1);
    criaGuerreiro(&guerreiros[1], 2);
	while(guerreiros[0].pontos_vida > 0 && guerreiros[1].pontos_vida > 0) {
		ataca(&guerreiros[0], &guerreiros[1]);
		ataca(&guerreiros[1], &guerreiros[0]);
	}
	if(guerreiros[0].pontos_vida <=0) {
			printf("\nVencedor: %d\n", guerreiros[1].id_guerreiro);
			imprimeGuerreiro(guerreiros[1]);
	}else if (guerreiros[1].pontos_vida <=0){
		printf("\nVencedor: %d\n", guerreiros[0].id_guerreiro);
		imprimeGuerreiro(guerreiros[0]);
	}
}
	
