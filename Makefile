.PHONEY:clean
main.out: main.o bank.o accountholder.o
	g++ -o main.out main.o bank.o accountholder.o

main.o: main.cpp
	g++ -c main.cpp

bank.o: bank.cpp
	g++ -c bank.cpp
	
accountholder.o: accountholder.cpp
	g++ -c accountholder.cpp

clean:
	rm *.o