OBJS	= Clustering.o Dianisma.o Ektiposeis.o HashFunction.o main.o PinakaPinakon.o Pinakas.o PinakasAnathesewn.o PinakasDianismaton.o PinakasKentron.o Randoms.o Sinartiseis.o cluster.o
SOURCE	= Clustering.cpp Dianisma.cpp Ektiposeis.cpp HashFunction.cpp main.cpp PinakaPinakon.cpp Pinakas.cpp PinakasAnathesewn.cpp PinakasDianismaton.cpp PinakasKentron.cpp Randoms.cpp Sinartiseis.cpp cluster.cpp
HEADER	= cluster.h Clustering.h Dianisma.h Ektiposeis.h HashFunction.h PinakaPinakon.h Pinakas.h PinakasAnathesewn.h PinakasDianismaton.h PinakasKentron.h Randoms.h Sinartiseis.h Statheres.h Typoi.h cluster.h
OUT	= cluster
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

Clustering.o: Clustering.cpp
	$(CC) $(FLAGS) Clustering.cpp -std=c++11

Dianisma.o: Dianisma.cpp
	$(CC) $(FLAGS) Dianisma.cpp -std=c++11

Ektiposeis.o: Ektiposeis.cpp
	$(CC) $(FLAGS) Ektiposeis.cpp -std=c++11

HashFunction.o: HashFunction.cpp
	$(CC) $(FLAGS) HashFunction.cpp -std=c++11

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c++11

PinakaPinakon.o: PinakaPinakon.cpp
	$(CC) $(FLAGS) PinakaPinakon.cpp -std=c++11

Pinakas.o: Pinakas.cpp
	$(CC) $(FLAGS) Pinakas.cpp -std=c++11

PinakasAnathesewn.o: PinakasAnathesewn.cpp
	$(CC) $(FLAGS) PinakasAnathesewn.cpp -std=c++11

PinakasDianismaton.o: PinakasDianismaton.cpp
	$(CC) $(FLAGS) PinakasDianismaton.cpp -std=c++11

PinakasKentron.o: PinakasKentron.cpp
	$(CC) $(FLAGS) PinakasKentron.cpp -std=c++11

Randoms.o: Randoms.cpp
	$(CC) $(FLAGS) Randoms.cpp -std=c++11

Sinartiseis.o: Sinartiseis.cpp
	$(CC) $(FLAGS) Sinartiseis.cpp -std=c++11

cluster.o: cluster.cpp
	$(CC) $(FLAGS) cluster.cpp -std=c++11


clean:
	rm -f $(OBJS) $(OUT)
