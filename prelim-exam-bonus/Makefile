all: bonus

bonus.o: bonus.cpp
	g++ -c bonus.cpp

bonus: bonus.o
	g++ -o bonus bonus.o

test:
	./bonus < bonus.in > bonus.out

clean:
	rm -rf bonus
	rm -rf *.o