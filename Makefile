.PHONEY:clean
main.out: main.o bank.o accountholder.o
	g++ -g -o main.out main.o bank.o accountholder.o

main.o: main.cpp
	g++ -g -c main.cpp

bank.o: bank.cpp
	g++ -g -c bank.cpp
	
accountholder.o: accountholder.cpp
	g++ -g -c accountholder.cpp

clean:
	rm *.o