OBJS = stockticker.o stockmarket.o main.o
CC = g++
DEBUG =
INC_DIR = ./
CFLAGS = -Werror -c $(DEBUG) -I$(INC_DIR)
LFLAGS = -Werror $(DEBUG)


p1 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o p1

main.o: main.cpp container.h trnx_error.h
	$(CC) $(CFLAGS) main.cpp

stockindex.o: stockindex.cpp stock.h trnx_error.h
	$(CC) $(CFLAGS) stockindex.cpp

stockmarket.o: stockmarket.cpp stock.h trnx_error.h
	$(CC) $(CFLAGS) stockmarket.cpp

stockticker.o: stockticker.cpp stock.h trnx_error.h
	$(CC) $(CFLAGS) stockticker.cpp

clean:
	\rm *.o *~ p1
