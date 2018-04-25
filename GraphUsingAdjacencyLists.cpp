/*
 ------------------------------------------------------------------------------
 Labo        : TP1
 File        : DoubleLinkedList.h
 Author(s)   : Vincent Guidoux
 Date        : 18.04.2018

 Goal        : List doublement chainées

 Commentaire : Labo POO2
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

    tabDegres = new size_t[nbrSommets];

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
        tabDegres[sommet] = adjencyLists[sommet].size();
    }

    cout << "min" << degreMin << " max" <<  degreMax;


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

size_t GraphUsingAdjacencyLists::degreSommet(size_t sommet) const {
    return tabDegres[sommet];
}

size_t GraphUsingAdjacencyLists::degreMinimum() const {
    return degreMin;
}









