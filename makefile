main: DtFecha.o DtMascota.o Gato.o Perro.o Socio.o Mascota.o Consulta.o main.o DtConsulta.o DtGato.o Dtperro.o
	g++ DtFecha.o DtMascota.o Gato.o Perro.o Socio.o Mascota.o Consulta.o main.o DtConsulta.o DtGato.o Dtperro.o -o main

DtFecha: DtFecha.cpp

DtMascota: DtMascota.cpp

Gato.o: Gato.cpp

Perro.o: Perro.cpp

Mascota.o: Mascota.cpp

Consulta.o: Consulta.cpp

Socio.o: Socio.cpp

main.o: main.cpp

DtConsulta.o: DtConsulta.cpp

DtGato.o: DtGato.cpp

Dtperro.o: Dtperro.cpp


clean-w:
	del /Q *.o
	del /Q main.exe

clean:
	rm -rf *.o main.exe
	clear 
