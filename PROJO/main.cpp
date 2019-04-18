#include <iostream>
#include <time.h>
#include <windows.h> //pour windows
#include <conio.h>   //pour windows
#include <stdio.h>
#include <unistd.h>
//#include <termios.h> //pour linux
#include <fcntl.h>
#include <set>
#include <iomanip>
#include "route.hpp"
#include "voitures.hpp"

using namespace std;

//Variables globales
Route route1;
vector< Voiture > voits;
int p = 10;                     //La probabilité de freinage dans le mode NASH.
int q = 50;                     //La probabilité q dans le mode de freinage VDR.
int s = 1;                      //Le nombre d'étapes lors de l'affichage.
string n;                       //Chaine de caractère permettant de déterminer quel est le mode utilisé
int pause;                      //Déclaration de l'entier permettant la pause.
bool estOcuppe = false;

enum Mode{NASH, VDR} m;         //Type énuméré permettant de déterminer le mode utilisé.

int main(){
    srand(time(NULL));
  	nouvelleRoute( route1, 5, 79 ); //Initialisation de la route.
  	routeVide(route1);              //Initialisation de la route.
  	int compteur;                   //Pour le nombre de voitures au départ.
  	int nombreVoitures = 0;         //Permet de compter le nombre de voitures sur la route.
    vector<int> positions;
  	positions = vector<int> (80);
  	cout << "Appuyez sur H pour afficher l'aide" << endl;
  	cout << endl;
    cout << "Saisir le nombre positif de voitures a faire apparaitre" << endl;
    cin >> compteur;
    voits = vector< Voiture > (route1.longueur); //Initialisation du vecteur de voitures.
    char frappe;                                 //Initialisation de la variable touche, pour le programme.
    int vit = 5;                                 //Initialisation de la vitesse pour toutes les voitures.
    int frei = p;                                //Probabilité de freinage pour toutes les voitures.
    s = 1;                                       //Nombre d'étapes initialisée à 1.
    for(int i=0; i<compteur; i++){               //Boucle for pour initialiser toutes les voitures.
         int pos = caseVideAleatoire(route1);
         positions[nombreVoitures] = pos;
         char charr = 'A' + rand()%26;
         voits[nombreVoitures] = nouvelleVoiture( vit, frei, pos, charr);
         nombreVoitures++;
         AfficherRoute(route1, voits);
    }
    cout << "Le mode de base est le modele NASH" << endl;
    cout << "Info variables :" << endl << "(Probabilite p) (Probabilite Q) (Mode) (Nombre d etapes affichees) (Nombre de voitures)" << endl << endl;
    m = NASH;                                     //Le mode de base est NASH.
    n = "NASH";
    while(1){                                     //Boucle infinie pour l'affichage de la route.
          if(kbhit()){
            frappe = getchar();
          } else {
            frappe = 0;
            }
            switch(frappe){
            case 'H':
                cout << "Bienvenue dans le mode d'emploi de ce programme " << endl;
                cout << "Appuyez sur N pour ajouter une voiture" << endl;
                cout << "Appuyez sur n pour retirer une voiture" << endl;
                cout << "Appuyez sur P pour augmenter la probabilite p" << endl;
                cout << "Appuyez sur p pour diminuer la probabilite p" << endl;
                cout << "Appuyez sur Q pour augmenter la probabilite q" << endl;
                cout << "Appuyez sur q pour diminuer la probabilite q" << endl;
                cout << "Appuyez sur S pour augmenter le nombre d etapes affichees  NE MARCHE PAS" << endl;
                cout << "Appuyez sur s pour diminuer le nombre d etapes affichees NE MARCHE PAS" << endl;
                cout << "Appuyez sur M pour passer en mode NASH" << endl;
                cout << "Appuyez sur m pour passer en mode VDR" << endl;
                cout << "Appuyez sur ESPACE pour mettre le programme en pause. Redemarre si le programme est deja en pause" << endl;
                cout << "Appuyez sur . pour arretter le programme" << endl;

            case ' ':
                while(frappe != ' '){
                    pause = 10000;
                }
                if(frappe == ' ') pause = 0;
                Sleep(pause);
                break;

            case 'N':{
                    int pos = caseVideAleatoire(route1);
                    char charr = 'A' + rand()%26;
                    for(int i=0; i<nombreVoitures; i++){
                        do{
                            pos = caseVideAleatoire(route1);
                        }while(pos == voits[i].position);
                    }
                    voits[nombreVoitures] = nouvelleVoiture(vit, frei, pos, charr);
                    nombreVoitures++;
                    break;
            }

            case 'n':
                supprimerVoiture(route1, voits, nombreVoitures); break;

            case 'P':
                p = p+10; break;

            case 'p':
                p = p-10; break;

            case 'Q':
                q = q+10; break;

            case 'q':
                q = q-10; break;

            case 'S':
                s++; break;

            case 's':
                s--; break;

            case 'M':
                m = NASH;
                n = "NASH";
                calculerProbaFreinageNASH(voits, p);
                break;

            case 'm':
                m = VDR;
                n = "VDR";
                calculerProbaFreinageVDR(voits, p, q);
                break;

            case '.':
                exit(1);
                break;

            }
                Sleep (2000);// pour windows
                //usleep(500000);//pour linux
                acceleration(voits);

                switch(m){

                case NASH:
                    calculerProbaFreinageNASH(voits, p);
                    n = "NASH";
                    break;

                case VDR:
                    calculerProbaFreinageVDR(voits, p, q);
                    n = "VDR";
                    break;

                }
                freinageAleatoire( voits );
                if(m == 0) calculerProbaFreinageNASH(voits, p);
                else if(m == 1) calculerProbaFreinageVDR(voits, p, q);
                freinageDistanceSecurite( route1, voits);
                avancerCase( route1, voits );
                AfficherRoute( route1, voits );
                cout << endl;
                cout << "\r";
                cout << "p(" << setw( 2 ) << p << ") "
                     << "q(" << setw( 2 ) << q << ") "
                     << "m(" << setw( 2 ) << m << ") "
                     << "s(" << setw( 2 ) << s << ") "
                     << "n(" << setw( 2 ) << nombreVoitures << ") : ";
                cout << endl;
        }
    return 0;
}

