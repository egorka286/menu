all: libmenu.a libmenu.so


libmenu.a: menu.o
	ar rc libmenu.a menu.o
	ranlib libmenu.a

menu.o: menu.cpp menu.h
	g++ -c menu.cpp

libmenu.so: menu_d.o
	g++ -shared -o libmenu.so menu_d.o

menu_d.o: menu.cpp menu.h
	g++ -fPIC -c menu.cpp -o menu_d.o

clean:
	rm -f *.a *.so *.o
