/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Nortalle
 *
 * Created on 15. mars 2018, 15:12
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include "GraphUsingAdjacencyLists.h"
#include "SmallestLast.h"

using namespace std;

int main(int argc, char **argv) {

    string path = "VLSI1.txt";

    cout << "Chargement du graphe (" << path << ")" << endl;

    clock_t begin = clock();

    GraphUsingAdjacencyLists g = GraphUsingAdjacencyLists(path);

    clock_t end = clock();

    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

    cout << "Fin du chargement(" << elapsed_secs << ")" << endl;

    cout << "Coloration " << endl;

    begin = clock();

    SmallestLast sl = SmallestLast(g);

    end = clock();

    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

    cout << "Coloration " << endl;

    return EXIT_SUCCESS;
}

