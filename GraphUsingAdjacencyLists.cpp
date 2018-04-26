/*
 ------------------------------------------------------------------------------
 Labo        : TP1
 Fichier     : GraphUsingAdjacencyLists.cpp
 Auteur      : Vincent Guidoux
 Date        : 24.04.2018

 but         :  Implémente les différntes fonctions qui permettent : la lecture
                d'un fichier de données et de le transcrire en graphe, setters
                et getters.
 commentaires: Il s'agit des vestiges d'un laboratoire d'ASD
 ------------------------------------------------------------------------------
*/

#include <fstream>
#include <string>
#include <list>

#include "GraphUsingAdjacencyLists.h"

GraphUsingAdjacencyLists::GraphUsingAdjacencyLists(const string &path) {

    std::ifstream s(path);

    s >> nbrSommets >> nbrAretes;

    degreMin = nbrAretes;

    adjencyLists = new DoubleLinkedList[nbrSommets];

    for (size_t i = 0; i < nbrAretes; i++) {
        size_t v, w;
        s >> v >> w;
        addEdge(v - 1, w - 1);
    }
    s.close();

    for (size_t sommet = 0; sommet < nbrSommets; sommet++) {
        degreMax = degreMax < adjencyLists[sommet].size() ? adjencyLists[sommet].size() : degreMax;
        degreMin = degreMin > adjencyLists[sommet].size() ? adjencyLists[sommet].size() : degreMin;
    }
}

void GraphUsingAdjacencyLists::addEdge(size_t v, size_t w) {
    adjencyLists[v].push(w);
    if (v != w)
        adjencyLists[w].push(v);
}

DoubleLinkedList *GraphUsingAdjacencyLists::adjacent(int v) const {
    return &adjencyLists[v];
}

size_t GraphUsingAdjacencyLists::nbrDeSommets() const {
    return nbrSommets;
}


size_t  GraphUsingAdjacencyLists::degreMaximum() const {
    return degreMax;
}


size_t GraphUsingAdjacencyLists::degreMinimum() const {
    return degreMin;
}









