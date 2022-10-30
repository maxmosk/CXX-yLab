.PHONY: all clean tests docker_tests

include ../CXXMakefile

#Compiler flags
CXXFLAGS=$(CXXFLAGS_WARNINGS) $(CXXFLAGS_FLAGS) $(CXXFLAGS_SYNTAX) $(CXXFLAGS_DEBUG)
LDFLAGS=$(CXXFLAGS_LINK)


SOURCEDIR=src/code
HEADERDIR=src/include
BUILDDIR=build
SOURCES=$(wildcard src/code/*.cpp)
SOURCES=$(wildcard $(SOURCEDIR)/*.cpp)
HEADFILES=$(wildcard $(HEADERDIR)/*.hpp)
OBJFILES=$(patsubst $(SOURCEDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))
EXECUTABLE=$(BUILDDIR)/lfu


all: dir $(EXECUTABLE)

dir:
	mkdir $(BUILDDIR)

$(EXECUTABLE): $(OBJFILES)
	$(CXXC) $(CXXFLAGS) $(LDFLAGS) -o $@ $?

$(OBJFILES): $(BUILDDIR)/%.o : $(SOURCEDIR)/%.cpp $(HEADFILES)
	$(CXXC) -c $(CXXFLAGS) -I$(HEADERDIR) -o $@ $<


clean:
	rm -rf $(BUILDDIR)
