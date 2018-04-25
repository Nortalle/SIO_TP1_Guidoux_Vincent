//
// Created by Vincent Guidoux on 23.04.2018.
//

#ifndef TP1_LEXICOGRAPHIC_H
#define TP1_LEXICOGRAPHIC_H


#include <cstddef>
#include "GraphUsingAdjacencyLists.h"

class Lexicographic {
private:
    size_t nbrSommets = 0;
    int*   colors;

public:
    Lexicographic(const GraphUsingAdjacencyLists & graph){

        //nous sauvegardons la taille du tableau de couleur
        nbrSommets = graph.nbrDeSommets();

        //D'après ce que nous avons vu en classe, le nombre de couleurs ne doit pas dépasser delta + 1
        size_t nbrCouleurMax = graph.degreMaximum();





    }


    size_t size() const ;

    int* colorTab() const ;

};

#endif //TP1_LEXICOGRAPHIC_H
