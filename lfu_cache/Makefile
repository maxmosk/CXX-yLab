.PHONY: all clean


CXXC=g++
CXXFLAGS=-Wall -Wextra -Weffc++ -Wunused -Wswitch-default -Wswitch-enum -Werror -Wundef -Wshadow -pedantic -std=c++20


SOURCEDIR=src/code
HEADERDIR=src/include
BUILDDIR=build
SOURCES=$(wildcard src/code/*.cpp)
SOURCES=$(wildcard $(SOURCEDIR)/*.cpp)
HEADFILES=$(wildcard $(HEADERDIR)/*.hpp)
OBJFILES=$(patsubst $(SOURCEDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))
EXECUTABLE=$(BUILDDIR)/lfu


all: dir $(EXECUTABLE)

debug: CXXFLAGS+= -ggdb3 -O0 -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined -pie -fcheck-new -fstack-check -fstack-protector -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -fPIE -lasan
debug: all

dir:
	mkdir $(BUILDDIR)

$(EXECUTABLE): $(OBJFILES)
	$(CXXC) $(CXXFLAGS) -o $@ $?

$(OBJFILES): $(BUILDDIR)/%.o : $(SOURCEDIR)/%.cpp $(HEADFILES)
	$(CXXC) -c $(CXXFLAGS) -I$(HEADERDIR) -o $@ $<


clean:
	rm -rf $(BUILDDIR)

