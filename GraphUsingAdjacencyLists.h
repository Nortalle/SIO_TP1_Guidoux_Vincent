/*
 ------------------------------------------------------------------------------
 Labo        : TP1
 Fichier     : GraphUsingAdjacencyLists.h
 Auteur      : Vincent Guidoux
 Date        : 24.04.2018

 but         :  Descriptions des différntes fonctions qui permettent : la lecture
                d'un fichier de données et de le transcrire en graphe, setters
                et getters.
 commentaires: Il s'agit des vestiges d'un laboratoire d'ASD
 ------------------------------------------------------------------------------
*/

#ifndef SIO_TP1_GUIDOUX_VINCENT_GRAPHUSINGADJACENCYLISTS_H
#define SIO_TP1_GUIDOUX_VINCENT_GRAPHUSINGADJACENCYLISTS_H

#include <string>
#include <vector>
#include <list>
#include "DoubleLinkedList.h"

using namespace std;

class GraphUsingAdjacencyLists {
public:
    /**
     * Constructeur
     * @param path chemin où se trouve le fichier à lire
     */
    GraphUsingAdjacencyLists(const string &path);

    /**
     *
     * @return le nombre de sommets
     */
    size_t nbrDeSommets() const;

    /**
     *
     * @return Delta
     */
    size_t degreMaximum() const;

    /**
     *
     * @return le degré minimum
     */
    size_t degreMinimum() const;


    /**
     *
     * @param v somme duquel nous voulons les adjacents
     * @return la liste d'adjacence du sommet donné
     */
    DoubleLinkedList *adjacent(int v) const;

private:

    /**
     * ajoute une arête au graphe
     *
     * @param v sommet 1 de l'arête
     * @param w  sommet 2 de l'arête
     */
    void addEdge(size_t v, size_t w);

    size_t *tabDegres;

    size_t degreMax = 0;
    size_t degreMin;
    size_t nbrSommets = 0;
    size_t nbrAretes = 0;
    DoubleLinkedList *adjencyLists;

};

#endif //SIO_TP1_GUIDOUX_VINCENT_GRAPHUSINGADJACENCYLISTS_H
