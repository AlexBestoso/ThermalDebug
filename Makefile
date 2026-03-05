# Generate the software version string.
VERSION = Alphicus 0.0.
HASH=$(shell git log -1 --pretty=format:"%H" | cut -c1-8)
$(shell echo "const char *VERISON = \"$(VERSION)$(HASH)\";" > version.h)
$(shell sed -i 's/^Version:.*$$/Version: $(VERSION)$(HASH)/g' README.md)


all:
	g++ main.cc -o tdbg

clean: 
	rm tdbg 
	rm testTedGen 
tests:
	g++ testTedGen.cc -o testTedGen
