
#mingw32-make
#Basic MakeFile Jansen Craft

a.exe: commented_main.cc date.cc check.cc checkbook.cc
	g++ -Wall -Werror commented_main.cc date.cc check.cc checkbook.cc

clean: 
	rm -f *.o a.exe