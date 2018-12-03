/*
Chavellas Christos
AM: 1115201300196
 */

#ifndef CLUSTER_H

void loadconfiguration(char* arxeio_config, int& h_functions, int &pinakes_katakermatismou, int &plithos_systades);

int loadfile(char* arxeio_eisodou, AlgorithmosEktelesis & algorithmos_ektelesis, PinakasDianismaton * & pinakasDianismatwn, unsigned int & d); 

int run_clustering(char* arxeio_eisodou, char* arxeio_exodou, char* arxeio_config, int h_functions,int pinakes_katakermatismou, bool leptomeries,AlgorithmosEktelesis algorithmos_ektelesis );

#endif /* CLUSTER_H */