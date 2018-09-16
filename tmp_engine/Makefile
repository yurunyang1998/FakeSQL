CXX = g++
CFLAGES = -std=c++11 -Wall -g

OBJS = test.o main.o

all: $(OBJS)
	$(CXX) -o a.out $(OBJS)

test.o:
	$(CXX) $(CFLAGES) -c -o test.o test.cc

main.o:
	$(CXX) $(CFLAGES) -c -o main.o main.cc

.PHONY: clean

clean:
	rm *.o

