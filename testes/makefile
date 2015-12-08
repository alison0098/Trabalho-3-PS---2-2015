make all: prog

prog: main.o Palestra.o Nodo_Palestra.o Fila_Palestra.o Palestra_Manager.o Local.o Nodo_Local.o Fila_Local.o Local_Manager.o Palestrante.o Nodo_Palestrante.o Fila_Palestrante.o Palestrante_Manager.o Disponibilidade.o Calendario.o Calendario_Manager.o Organizer.o
	gcc main.o Palestra.o Nodo_Palestra.o Fila_Palestra.o Palestra_Manager.o Local.o Nodo_Local.o Fila_Local.o Local_Manager.o Palestrante.o Nodo_Palestrante.o Fila_Palestrante.o Palestrante_Manager.o Disponibilidade.o Calendario.o Calendario_Manager.o Organizer.o -o prog
	rm *.o

main.o: Sources/main.c
	gcc -c Sources/main.c

Palestra.o: Sources/Palestra.c
	gcc -c Sources/Palestra.c

Nodo_Palestra.o: Sources/Nodo_Palestra.c
	gcc -c Sources/Nodo_Palestra.c

Fila_Palestra.o: Sources/Fila_Palestra.c
	gcc -c Sources/Fila_Palestra.c

Palestra_Manager.o: Sources/Palestra_Manager.c
	gcc -c Sources/Palestra_Manager.c

Local.o: Sources/Local.c
	gcc -c Sources/Local.c

Nodo_Local.o: Sources/Nodo_Local.c
	gcc -c Sources/Nodo_Local.c

Fila_Local.o: Sources/Fila_Local.c
	gcc -c Sources/Fila_Local.c

Local_Manager.o: Sources/Local_Manager.c
	gcc -c Sources/Local_Manager.c

Palestrante.o: Sources/Palestrante.c
	gcc -c Sources/Palestrante.c

Nodo_Palestrante.o: Sources/Nodo_Palestrante.c
	gcc -c Sources/Nodo_Palestrante.c

Fila_Palestrante.o: Sources/Fila_Palestrante.c
	gcc -c Sources/Fila_Palestrante.c

Palestrante_Manager.o: Sources/Palestrante_Manager.c
	gcc -c Sources/Palestrante_Manager.c

Disponibilidade.o: Sources/Disponibilidade.c
	gcc -c Sources/Disponibilidade.c

Calendario.o: Sources/Calendario.c
	gcc -c Sources/Calendario.c

Calendario_Manager.o: Sources/Calendario_Manager.c
	gcc -c Sources/Calendario_Manager.c

Organizer.o: Sources/Organizer.c
	gcc -c Sources/Organizer.c

clean:
	rm prog
