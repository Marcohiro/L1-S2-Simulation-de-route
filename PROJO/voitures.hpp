#ifndef VOITURES_HPP_INCLUDED
#define VOITURES_HPP_INCLUDED

	#include <iostream>
	#include <cmath>
	#include <cstdlib>
	#include <vector>
	#include <sstream>
    #include <string.h>

    int const VMAX = 5;
    int const nash = 50;
    int const vdr = 10;

	using namespace std;

	/**
	 * Structure de la voiture
	 **/
	struct Voiture {
		int vitesse;
		int freinage;
		char symbole;
		int position;
	};

	/** LISTE DES FONCTIONS **/

	/**
	 * Déclaration d'une nouvelle voiture
	 * @param vitesse[in] : Vitesse de la voiture
	 * @param freinage[in] : Proba. de freinage de la voiture
	 * @param position[in] : Position de la coiture sur la route
	 * @param caractere[in] : caractere de la voiture
	 * @return Une nouvelle voiture
	  **/
	Voiture nouvelleVoiture( int &vitesse, int &freinage, int &position, char &caractere );

	/**
	 *  Fait ralentir une ou plusieurs voiture si leur vitesse est supérieure à 0
	 *  @param[in/out] un vecteur de voitures
	 **/
	void ralentir( vector<Voiture> &vect);

	/**
      * Fait accélérer une ou plusieurs voitures
      * @param[in/out] un vecteur de voitures vect
      **/
      void acceleration ( vector<Voiture> &vect);

    /**
     *  Détermine si une voiture est arrêttée
     *  @param[in] un vecteur de voitures vect
     *  @return true si la vitesse d'au moins une voiture est nulle
     *  @ return false sinon
     **/
    bool estArrettee( vector<Voiture> vect);

    /**
     *  Freine une ou plusieurs voitures de manière aléatoire
     *  @param[in/out] un vecteur de voitures vect
     **/
     void freinageAleatoire ( vector<Voiture> &vect);

    /**
     *  Calcule la probabilité de freinage dans le modèle vdr
     *  si la voiture est arrêttée, alors sa probabilité de freinage est égale à vdr
     *  sinon, elle est égale à la probabilité de freinage dans le modèle vdr
     *  @param[in/out] un vecteur de voitures v
     *  @param[in] la probabilité de freinage nash
     *  @param[in] la probabilité de freinage vdr
     **/
    void calculerProbaFreinageVDR( vector<Voiture> &vect, int nash, int vdr);

    /**
     *  Freine une voiture dans le modèle nash
     *  @param[in/out] un vecteur de voitures v
     *  @param[in] la probabilité de freinage dans le modèle NASH
     **/
    void calculerProbaFreinageNASH( vector<Voiture> &vect, int nash);

#endif // VOITURES_HPP_INCLUDED
