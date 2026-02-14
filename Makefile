
all:
	g++ main.cc -o tdbg
clean: 
	rm tdbg 
	rm testTedGen 
tests:
	g++ testTedGen.cc -o testTedGen
