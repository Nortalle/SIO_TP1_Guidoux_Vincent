/*
 ------------------------------------------------------------------------------
 Labo        : TP1
 Fichier     : SmallestLast.h
 Auteur      : Vincent Guidoux
 Date        : 24.04.2018

 but         :  Implementation de l'algorithme de coloration smallest-last
 commentaires: d'après algorithme rendu au TT1
 ------------------------------------------------------------------------------
*/

#ifndef SIO_TP1_GUIDOUX_VINCENT_SMALLESTLAST_H
#define SIO_TP1_GUIDOUX_VINCENT_SMALLESTLAST_H

#include <fstream>


class SmallestLast {
private:
    const GraphUsingAdjacencyLists g;
    size_t *tabCouleurs;
    size_t nombreCouleur;
    size_t nbrSommetsTries;

public:
    SmallestLast(const GraphUsingAdjacencyLists &g) : g(g) {

        //conteneur pour le tri casier
        DoubleLinkedList *tabDegre = new DoubleLinkedList[g.degreMaximum() + 1];

        //Tableau de référence sur tabDegre afin de gagner du temps au niveau des suppressions
        DoubleLinkedList::Node **TabReference = new DoubleLinkedList::Node *[g.nbrDeSommets()];

        //tableau de tous les degrés des sommet (deg[0] retourne le degré du sommet 1
        size_t *deg = new size_t[g.nbrDeSommets()];
        size_t degreMin = g.degreMinimum();

        nbrSommetsTries = 0;
        //Stock l'ordre inverse dans lequel nous allons devoir colorer les sommets
        size_t *ordreSommets = new size_t[g.nbrDeSommets()];

        /**
         * Initialisation
         *
         * Le tabDegre est rempli de tous les noeuds du graphe.
         * les noeuds de degré 1 se trouve dans tabDegre[1]
         */
        for (size_t i = 0; i < g.nbrDeSommets(); ++i) {
            deg[i] = g.adjacent(i)->size();
            TabReference[i] = tabDegre[deg[i]].push(i);
        }


        size_t v;
        //Vérifier que tabDegre soit vide n'était pas une bonne idée
        //Maintenant, nous attendons d'avoir passer tous les sommets
        while (nbrSommetsTries != g.nbrDeSommets()) {

            //Si ce casier est vide, nous passons au suivant
            if (tabDegre[degreMin].size() == 0) {
                ++degreMin;
            } else {
                // Sinon, nous avons un sommet à mettre dans la file de coloration
                v = tabDegre[degreMin].pop();
                ordreSommets[nbrSommetsTries] = v;
                nbrSommetsTries++;

                //Maintenant, il faut mettre à jour les voisins de ce sommet

                DoubleLinkedList *adjacents = g.adjacent(v);

                DoubleLinkedList::Node *suivant = adjacents->front();

                while (suivant != nullptr) {

                    size_t value = suivant->element;
                    //Nous prenons un voisin dans son casier
                    DoubleLinkedList::Node *adjacent = TabReference[value];

                    //s'il n'a pas encore été mis dans la file de coloration
                    if (adjacent != nullptr) {

                        size_t degAdj = deg[value];
                        tabDegre[degAdj].remove(adjacent);

                        size_t tmp = deg[value];
                        deg[value] = tmp--;
                        //Nous le mettons au casier inférieur
                        TabReference[value] = tabDegre[deg[value]].push(value);

                        //Si le voisin est descendu d'un casier en dessous v :
                        if (degreMin > deg[value]) {
                            degreMin = deg[value];
                        }
                    }
                    suivant = suivant->next;
                }
                //Ce noeuds est traité
                TabReference[v] = nullptr;
            }
        }

        //Coloration


        //initialisation
        size_t largeur = g.degreMaximum() + 1;
        tabCouleurs = new size_t[g.nbrDeSommets()];
        int **estColoreAvec = new int *[g.nbrDeSommets()];

        for (int i = 0; i < g.nbrDeSommets(); i++) {
            estColoreAvec[i] = new int[largeur];
            for (int j = 0; j < largeur; ++j) {
                estColoreAvec[i][j] = true;
            }
        }

        size_t sommetCourant;
        for (int i = g.nbrDeSommets() - 1; i >= 0; --i) {
            sommetCourant = ordreSommets[i];

            for (int j = 0; j < largeur; ++j) {
                //Si la couleur est encore disponible, nous colorons
                if (estColoreAvec[sommetCourant][j]) {
                    tabCouleurs[sommetCourant] = j;
                    break;
                }
            }
            //La couleur utilisée est inutilisable pour le voisin du sommet courant
            DoubleLinkedList *adjacents = g.adjacent(sommetCourant);
            DoubleLinkedList::Node *suivant = adjacents->front();

            while (suivant != nullptr) {
                estColoreAvec[suivant->element][tabCouleurs[sommetCourant]] = false;

                suivant = suivant->next;
            }
        }

    }

    /**
     * Calcule le nombre de couleur dans ce graphe
     */
    void calculNombreCouleur() {
        nombreCouleur = 0;

        for (int i = 0; i < nbrSommetsTries; ++i) {
            if (tabCouleurs[i] > nombreCouleur) {
                nombreCouleur = tabCouleurs[i];
            }
        }
    }

    /**
     *
     * @return le nombre de couleur de se graphe
     */
    size_t nombreCouleurs() const {
        return nombreCouleur;
    }

    void creationSolution(const string &path) const {

        ofstream solution(path);

        solution << nbrSommetsTries << " " << nombreCouleur << endl;

        for(size_t i = 0; i < nbrSommetsTries; ++i){
            solution << (i+1) << " " << (tabCouleurs[i] + 1) << endl;
        }

        solution.close();
    }
};


#endif //SIO_TP1_GUIDOUX_VINCENT_SMALLESTLAST_H
