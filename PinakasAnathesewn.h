/*
Chavellas Christos
AM: 1115201300196
 */

#ifndef PINAKASANATHESEWN_H
#define PINAKASANATHESEWN_H

class PinakasAnathesewn {
public:
    PinakasAnathesewn(int N);
    virtual ~PinakasAnathesewn();

    void setAnathesi(unsigned int i, unsigned cluster_id) ;
    int getAnathesi(unsigned int i) ;
    int getAndCheckAnathesi(unsigned int i);
    int getN();

     void setEfedrikiAnathesi(unsigned int i, unsigned cluster_id) ;
    int getEfedrikiAnathesi(unsigned int i) ;
    int getAndCheckEfedrikiAnathesi(unsigned int i);
    
private:
    int N;
    int * anatheseis;
    int * efedrikesanatheseis;
};

#endif /* PINAKASANATHESEWN_H */

