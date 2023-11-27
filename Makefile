pocketwordle: board.o cell.o cursor.o game.o render.o row.o word.o main.o
	g++ -std=c++11 board.o cell.o cursor.o game.o render.o row.o word.o main.o -o pocketwordle -Wall -Werror -lncurses

board.o: ./src/board/board.cpp ./src/board/board.h
	g++ -std=c++11 -c ./src/board/board.cpp -o board.o -Wall -Werror

cell.o: ./src/cell/cell.cpp ./src/cell/cell.h
	g++ -std=c++11 -c ./src/cell/cell.cpp -o cell.o -Wall -Werror

cursor.o: ./src/cursor/cursor.cpp ./src/cursor/cursor.h
	g++ -std=c++11 -c ./src/cursor/cursor.cpp -o cursor.o -Wall -Werror

game.o: ./src/game/game.cpp ./src/game/game.h
	g++ -std=c++11 -c ./src/game/game.cpp -o game.o -Wall -Werror

render.o: ./src/render/render.cpp ./src/render/render.h
	g++ -std=c++11 -c ./src/render/render.cpp -o render.o -Wall -Werror

row.o: ./src/row/row.cpp ./src/row/row.h
	g++ -std=c++11 -c ./src/row/row.cpp -o row.o -Wall -Werror

word.o: ./src/word/word.cpp ./src/word/word.h
	g++ -std=c++11 -c ./src/word/word.cpp -o word.o -Wall -Werror

main.o: ./src/main.cpp
	g++ -std=c++11 -c ./src/main.cpp -o main.o -Wall -Werror

clean:
	rm -f *.o pocketwordle