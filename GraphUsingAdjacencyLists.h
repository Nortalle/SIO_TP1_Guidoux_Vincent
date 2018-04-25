//
// Created by Nortalle on 12.04.2018.
//

#ifndef SIO_TP1_GUIDOUX_VINCENT_GRAPHUSINGADJACENCYLISTS_H
#define SIO_TP1_GUIDOUX_VINCENT_GRAPHUSINGADJACENCYLISTS_H

#include <string>
#include <vector>
#include <list>
#include "DoubleLinkedList.h"

using namespace std;

class GraphUsingAdjacencyLists {
public:
    GraphUsingAdjacencyLists(const string &path);

    size_t nbrDeSommets() const;

    size_t degreMaximum() const;

    size_t degreMinimum() const;

    size_t degreSommet(size_t sommet) const;

private:


    void addEdge(size_t v, size_t w);

    DoubleLinkedList *adjacent(int v) const;

    size_t *tabDegres;

    size_t degreMax = 0;
    size_t degreMin;
    size_t nbrSommets = 0;
    size_t nbrAretes = 0;
    DoubleLinkedList *adjencyLists;

};

#endif //SIO_TP1_GUIDOUX_VINCENT_GRAPHUSINGADJACENCYLISTS_H
