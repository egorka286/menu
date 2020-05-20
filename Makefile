libmenu.a: menu.o
	ar rc libmenu.a menu.o
	ranlib libmenu.a

menu.o: menu.cpp menu.h
	g++ -c menu.cpp

clean:
	rm -f *.[ao]
