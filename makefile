bin/experimento: src/experimento/main.cpp bin/DNI.o
	g++ -g -fPIC src/experimento/main.cpp bin/DNI.o -o bin/experimento

bin/DNI.o: include/DNI.hpp src/DNI.cpp
	g++ -c -g src/DNI.cpp -o bin/DNI.o



bin/estTest: include/DNI.hpp src/test/estTest.cpp
	g++ -g src/test/estTest.cpp -o bin/estTest

bin/dniTest: bin/DNI.o src/test/dniTest.cpp
	g++ -g bin/DNI.o src/test/dniTest.cpp -o bin/dniTest

bin/tablaTest: bin/DNI.o include/Tabla.hpp src/test/tablaTest.cpp
	g++ -fPIC -g src/test/tablaTest.cpp bin/DNI.o -o bin/tablaTest

bin/cellTest: include/Celda.hpp src/test/cellTest.cpp
	g++ -fPIC -g src/test/cellTest.cpp -o bin/cellTest


.PHONY:
clean:
	rm bin/*
