clean: 
	rm tdbg 
	rm testTedGen 
all:
	g++ main.cc -o tdbg
tests:
	g++ testTedGen.cc -o testTedGen
