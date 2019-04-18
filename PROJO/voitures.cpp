#include "voitures.hpp"

Voiture nouvelleVoiture( int &vitesse, int &freinage, int &position, char &caractere ) {
	Voiture voiture;
	voiture.vitesse = vitesse;
	voiture.freinage = freinage;
	voiture.position = position;
	voiture.symbole = caractere;
    return voiture;
}

void ralentir(vector<Voiture> &vect){
    for(int i=0; i<vect.size(); i++){
        if(vect[i].vitesse > 0){
            vect[i].vitesse--;
        }
    }
}

void acceleration( vector<Voiture> &vect){
    for(int i=0; i<vect.size(); i++){
        if( vect[i].vitesse < 5)vect[i].vitesse++;
    }
}

bool estArrettee(vector<Voiture> vect){
    for(int i=0; i<vect.size(); i++){
        if(vect[i].vitesse == 0){
            return true;
        } else {
            return false;
        }
    }
}

void freinageAleatoire( vector<Voiture> &vect){
    for(int i=0; i<vect.size(); i++){
        if(vect[i].freinage > rand()%100 && vect[i].vitesse > 0)vect[i].vitesse--;
    }
}

void calculerProbaFreinageVDR( vector<Voiture> &vect, int nash, int vdr){
    for(int i=0; i<vect.size(); i++){
        if(estArrettee(voits)){
            vect[i].freinage = vdr;
        } else {
            vect[i].freinage = nash;
        }
    }
}

void calculerProbaFreinageNASH( vector<Voiture> &vect, int nash){
  for(int i=0; i<vect.size(); i++){
    vect[i].freinage = nash;
  }
}
