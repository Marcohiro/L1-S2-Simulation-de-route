#ifndef ROUTE_HPP_INCLUDED
#define ROUTE_HPP_INCLUDED

	#include <iostream>
	#include <cmath>
	#include <cstdlib>
	#include <vector>
	#include "voitures.hpp"

	/** Infrastructure minimale de test **/
	#define ASSERT( test ) if (!(test)) std::cout << "Test failed in file " << __FILE__ \ << " line " << __LINE__ << ": " #test << std::endl
	#define ROAD 			'-'

    int const distanceSecurite = 4;

	using namespace std;

	//Structure pour la route
	struct Route {
        int limVitesse;
		int longueur;
		vector< char > valeur;
	};

	/** Liste des fonctions **/

	/**
	 * Déclaration d'une nouvelle route
	 * @param[in] la vitesse limite v, la longueur de la route l
	 * @param[out] une nouvelle route r
	 **/
	void nouvelleRoute( Route &r, int v, int l );

	/**
     *  Initialise une route vide, composée uniquement du caractere ROAD
     *  @param[in/out] une route r
     **/
	void routeVide(Route &r);

    /**
 	 * Affiche la route et les voitures
 	 * @param[in] une route r
 	 * @param[in] un vecteur de voitures vect
	 **/
    void AfficherRoute(Route &r, vector<Voiture> &vect);

    /**
     *  Permet de supprimer la dernière voiture dans le vecteur de voiture
     *  Diminue aussi le nombre de voitures
     *  @param[in/out] une route r
     *  @param[in/out] yn vecteur de voitures vect
     *  @param[in/out] le nombre de voiture dans le vecteur voiture
     **/
	 void supprimerVoiture(Route &r, vector<Voiture> &vect, int &nombreVoitures);

    /**
     *  Détermine si une case est vide ou occupée
     *  @param[in] une route r et une position
     *  @return true si la case est vide
     *  @return false si la case est occupée
     **/
	bool estVide(Route &r, int position);

    /**
     *  Cherche si une case aléatoire sur la route est vide
     *  @param[in] une route r
     *  @return une case vide aléatoire sur le vecteur route
     **/
	int caseVideAleatoire(Route r);

    /**
     *  Permet de faire avancer une voiture sur une route
     *  @param[in/out] une route r et une position, qui est modifiée en fonction de la vitesse
     *  @param[in] la vitessse de la voiture
     *  @param[in] le caractere de la voiture
     **/
    void avancerCase(Route &r, vector<Voiture> &vect);

    /**
     * Fait ralentir des voitures si la distance par rapport à la suivante est trop courte par rapport à la vitesse de la voiture
     à @param[in] une route r
     * @param[in/out] un vecteur de voitures
     **/
    void freinageDistanceSecurite( Route &r, vector<Voiture> &vect);

#endif
