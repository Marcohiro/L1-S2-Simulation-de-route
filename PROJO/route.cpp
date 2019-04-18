#include "route.hpp"
#include "voitures.hpp"

void nouvelleRoute( Route &r, int v, int l ) {
    r.limVitesse = v;
    r.longueur = l;
    r.valeur = vector< char >( l );
}

void routeVide( Route &r){
    for(int i=0; i<=r.longueur; i++){
        r.valeur[i] = ROAD;
    }
}

void AfficherRoute(Route &r, vector<Voiture> &vect){
    for(int i=0; i<=r.longueur; i++){
        for(int j=0; j<vect.size(); j++){
        if(i == vect[j].position) r.valeur[i] = vect[j].symbole;
        if( r.valeur[i] == 0 ) r.valeur[i] = ROAD;
        }
     cout << r.valeur[i];
    }
}

void supprimerVoiture(Route &r, vector<Voiture> &vect, int &nombreVoitures){
    for(int i=0; i<r.longueur; i++){
        if (i == vect[nombreVoitures].position){
            r.valeur[i] = ROAD;
            vect.erase(vect.begin() + nombreVoitures);
        }
    }
    nombreVoitures--;
}

bool estVide(Route &r, int position){
    for(int i=0; i<r.longueur; i++){
    if(i = position && r.valeur[i] != ROAD){
        return false;
        }else{
        return true;
        }
    }
}

int caseVideAleatoire(Route r){
    int caseVideAleatoire = rand()%r.longueur;
    bool vide;
    vide = estVide(r, caseVideAleatoire);
    if(vide) return caseVideAleatoire;
    else do{
        vide = estVide(r, caseVideAleatoire);
        caseVideAleatoire = rand()%r.longueur;
    }while(vide != true);
    return caseVideAleatoire;
}

void avancerCase( Route &r, vector<Voiture> &vect){
    for(int j=0; j<vect.size(); j++){
        r.valeur[vect[j].position] = ROAD;
        vect[j].position = vect[j].position + vect[j].vitesse;
        if(vect[j].position > (r.longueur-1)){
            vect[j].position = vect[j].position - r.longueur;
            }
    }
}

void freinageDistanceSecurite( Route &r, vector<Voiture> &vect){ //CECI n'est pas optimisé...
    for(int i=0; i<r.longueur; i++){
        for(int j=0; j<vect.size(); j++){
        if(r.valeur[i] == vect[j].symbole){
            if(r.valeur[vect[j].position+1] != ROAD && r.valeur[vect[j].position+1] != ' ') vect[j].vitesse = 0;
            else if(r.valeur[vect[j].position+1] == ROAD && r.valeur[vect[j].position+2] != ROAD  && r.valeur[vect[j].position+2] != ' ') vect[j].vitesse = 1;
            else if(r.valeur[vect[j].position+1] == ROAD && r.valeur[vect[j].position+2]  == ROAD && r.valeur[vect[j].position+3] != ROAD && r.valeur[vect[j].position+3] != ' ') vect[j].vitesse = 2;
            else if(r.valeur[vect[j].position+1] == ROAD && r.valeur[vect[j].position+2]  == ROAD && r.valeur[vect[j].position+3] == ROAD && r.valeur[vect[j].position+4] != ROAD && r.valeur[vect[j].position+4] != ' ') vect[j].vitesse = 3;
            else if(r.valeur[vect[j].position+1] == ROAD && r.valeur[vect[j].position+2]  == ROAD && r.valeur[vect[j].position+3] == ROAD && r.valeur[vect[j].position+4]  == ROAD && r.valeur[vect[j].position+5]  != ROAD && r.valeur[vect[j].position+5] != ' ') vect[j].vitesse = 4;
           //else if(r.valeur[vect[j].position+1] == ROAD && r.valeur[vect[j].position+2]  == ROAD && r.valeur[vect[j].position+3] == ROAD && r.valeur[vect[j].position+4]  == ROAD && r.valeur[vect[j].position+5]  == ROAD && r.valeur[vect[j].position+6] != ROAD && r.valeur[vect[j].position+6] != ' ') vect[j].vitesse = 5;
            }
        }
    }
}
