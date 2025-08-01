CC = g++

avoEditor: avoEditor.cpp gapBuffer.o
	$(CC) avoEditor.cpp gapBuffer.o -o avoEditor -Wall -Wextra -Iinclude

gapBuffer.o: gapBuffer.cpp include/gapBuffer.h
	$(CC) -c gapBuffer.cpp -o gapBuffer.o -Wall -Wextra -Iinclude

clean:
	rm -f avoEditor gapBuffer.o