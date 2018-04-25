//
// Created by Nortalle on 25.04.2018.
//

#ifndef SIO_TP1_GUIDOUX_VINCENT_SMALLESTLAST_H
#define SIO_TP1_GUIDOUX_VINCENT_SMALLESTLAST_H


class SmallestLast {
private:
    const GraphUsingAdjacencyLists g;

public:
    SmallestLast(const GraphUsingAdjacencyLists &g) : g(g){

        DoubleLinkedList* tabDegre= new DoubleLinkedList[g.degreMaximum() + 1];
        Node** TabReference = new Node*[g.nbrDeSommets()];

        size_t degreMin = g.degreMinimum();
        size_t degreMax = g.degreMaximum();
        size_t nbrSommetsTries = g.nbrDeSommets();
        size_t ordreSommets = new size_t[g.nbrDeSommets()];

        size_t sommetCourant;


        for(size_t i = 0; i < g.nbrDeSommets(); ++i){
            TabReference[i] = tabDegre[g.degreSommet(i)].push(i);
        }

        //Vérifier que tabDegre soit vide n'était pas une bonne idée. celle là est mieux
        while(nbrSommetsTries != 0){

            if(tabDegre[degreMin].size() = 0){
                ++degreMin;
            } else {
                v = tabDegre[degreMin].pop();
                ordreSommets[nbrSommetsTries] = v;
                nbrSommetsTries++;

                remove(TabReference[v]);

                for()
            }



        }




    }
};


#endif //SIO_TP1_GUIDOUX_VINCENT_SMALLESTLAST_H
