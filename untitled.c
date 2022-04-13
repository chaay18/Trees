
// noeud fils
static void noeudFils (GrapheMat * graphe, int parent, Liste* fils ){
    int nMax = graphe->nMax;
    for(int i=0 ;i < graphe->n; i++ ){
        if (graphe->element[parent*nMax+i] == true){
            Objet* fil = (Objet*) i;
            insererEnFinDeListe(fils,fil);
        }
    }
    
// non informe : profondeur limite
static int trouve = faux;
//static int flag = faux;
static void EPL_recursive(GrapheMat* graphe, int pos, int limit, NomSom but){

    if(!trouve && !graphe->marque[pos]){
        graphe->marque[pos] = vrai;
        printf("%s", graphe->nomS[pos]);

        if(strcmp(graphe->nomS[pos], but) == 0){
            trouve = vrai;
            printf("\n vertex found  \n ");
            return;
        }else if(   limit > 0 ){
            Liste* fils =creerListe(0,NULL, NULL);
            noeudFils(graphe, pos, fils);
            while(!listeVide(fils)){
                int fil = (int) ((size_t)extraireEnTeteDeListe(fils));
                EPL_recursive(graphe, fil, limit-1, but);
            }
//            flag = true;
        }
    }
}

int profondeurLimite(GrapheMat* graphe, int limit, NomSom but){
    initMarque(graphe);
    for( int i = 0 ; i < graphe->n ; i++ ){
        if(!graphe->marque[i]){
            EPL_recursive(graphe, i, limit, but);
        }
        break;
    }
    if( !trouve ){
        printf("\n Noeud Introuvable\n");
        return faux;
    }
    trouve = faux;
    return vrai;
//    trouve = faux; if i use the void

}



// non informe : exploration iterative en profondeur
void iterativeProfondeur(GrapheMat* graphe, int limit, NomSom but){
    int found = faux;
    for(int d =0; d <= limit; d++){
        initMarque(graphe);
        printf ("\n limit = %d \n", d);
        found = profondeurLimite(graphe, d, but);
        if (found)
        {
            printf("\n vertex found in limit %d \n",d );
            break;
        }
    }
    if(!found){
        printf("\n vertex unfounded \n");
    }

}