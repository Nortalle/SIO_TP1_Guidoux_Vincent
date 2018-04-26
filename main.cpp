/*
 ------------------------------------------------------------------------------
 Labo        : TP1
 Fichier     : main.cpp
 Auteur      : Vincent Guidoux
 Date        : 24.04.2018

 but         : Classe Main, elle charge un fichier dans un graphe
                le colorie

 commentaires: Il s'agit des vestiges d'un laboratoire d'ASD
 ------------------------------------------------------------------------------
*/

#include <cstdlib>
#include <iostream>
#include <ctime>
#include "GraphUsingAdjacencyLists.h"
#include "SmallestLast.h"

using namespace std;

int main(int argc, char **argv) {

    string path = argv[1];

    cout << "Chargement du graphe (" << path << ")" << endl;

    clock_t begin = clock();

    GraphUsingAdjacencyLists g = GraphUsingAdjacencyLists(path);

    clock_t end = clock();

    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

    cout << "Fin du chargement(" << elapsed_secs << "s)" << endl;

    cout << "Début Coloration " << endl;

    begin = clock();

    SmallestLast sl = SmallestLast(g);

    end = clock();

    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

    cout << "Fin Coloration (" << elapsed_secs << "s)" << endl;

    sl.calculNombreCouleur();

    cout << "nombre de couleurs : " << sl.nombreCouleurs();

    cout << "Début Ecriture fichier solution " << endl;

    begin = clock();
    string solution = "solution_" + path;

    sl.creationSolution(solution);

    end = clock();

    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

    cout << "Fin Ecriture fichier solution (" << elapsed_secs << "s)" << endl;


    return EXIT_SUCCESS;
}

