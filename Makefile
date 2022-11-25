NAME	=	cpp-common-lib
EXENAME = ccl
LANG	=	ja_JP.utf8

CXX     = c++
CXXFLAGS_DEBUG = -Wall -Werror -g -O0
CXXFLAGS_RELEASE =
CXXFLAGS = -std=c++17 $(CXXFLAGS_DEBUG)

SRCDIR   = ./src
INCLUDE  = ./include
EXEDIR   = ./bin
OBJDIR   = $(EXEDIR)/obj

SRCDIRS  = $(shell find $(SRCDIR) -type d)
SOURCES  = $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.cpp))
OBJDIRS  = $(SOURCES:$(SRCDIR)/%=%)
OBJECTS  = $(addprefix $(OBJDIR)/, $(OBJDIRS:.cpp=.o))

# debug
# $(warning )

ifeq ($(OS),Windows_NT)
  EXEEXT = .exe
else
	ifeq ($(OS),)
  	EXEEXT = 
	endif
endif

$(EXENAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) -o $@$(EXEEXT) $(OBJECTS)

$(OBJDIR)/%.o:$(SRCDIR)/%.cpp
	-@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) -o $@ -c $<

.PHONY: all
all: $(EXENAME)

.PHONY: lint
lint:
	cpplint --filter=-legal,-build/c++11,-build/include_subdir --exclude=include --recursive src/

.PHONY: directories
directories:
	-@mkdir -p $(EXEDIR)
	-@mkdir -p $(OBJDIRS)

#make clean
.PHONY: clean
clean: 
	-@rm -r $(EXEDIR)/* ./$(EXENAME)$(EXEEXT)

#make test
.PHONY: test
test: lint all
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) -o $@ccl-test $(OBJECTS)
