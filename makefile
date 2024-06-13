CC = clang++
CFLAGS = -Wall -std=c++17

SRCS = Board.cpp Catan.cpp Path.cpp Player.cpp Position.cpp Tile.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
OUT = Catan

all: $(OUT)

$(OUT): $(OBJS)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(OUT)
