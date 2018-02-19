VPATH	=	./src
CXXFLAGS=	-I "./include"



program1:Top.o Test.o
	g++ Test.o		Top.o 	-o	program1


Top.o:Top.cpp
	g++ -c $(CXXFLAGS) $<
Test.o:Test.cpp
	g++ -c $(CXXFLAGS) $<