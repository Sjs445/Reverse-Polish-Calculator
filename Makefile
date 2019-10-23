all:
	g++ -o polish reversePolish.cpp
	./polish
clean:
	rm polish