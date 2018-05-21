#################################################################
# Graph DB path variables                                       #
#################################################################
GRAPHDB_PATH   := ..
GRAPHDB_INC    := $(GRAPHDB_PATH)/inc
GRAPHDB_CONFIG := $(GRAPHDB_PATH)/config
GRAPHDB_SRC    := $(GRAPHDB_CONFIG)/Sources.def
GRAPHDB_INC    := $(GRAPHDB_CONFIG)/Includes.def
SOURCES        := $(foreach SRC_FILE, $(shell cat ${GRAPHDB_SRC}), $(basename $(SRC_FILE)))
SOURCES_O      := $(foreach SRC_FILE, $(shell cat ${GRAPHDB_SRC}), $(basename $(SRC_FILE)).o)
INC            := $(foreach INC_FILE, $(shell cat ${GRAPHDB_INC}), "-I"$(GRAPHDB_PATH)/$(INC_FILE))
TARGET_DST     := _out
TARGET_SO      := $(TARGET_DST)/libgraphdb.so
TARGET_O       := $(TARGET_DST)/libgraphdb.o

#################################################################
# System variables                                              #
#################################################################
CC       := g++ 
FLAGS    := -std=c++11
CFLAGS   := -Wall -g -O -c  -fPIC 
CFLAGSLD := -Wl,--export-dynamic -rdynamic
LDFLAGS  := -shared
RM       := @rm -rf
MKDIR    := @mkdir
ECHO     := @echo
FIND 	 := @find

.PHONY: all clean test

all: clean
	$(ECHO) ================================================================================ 
	$(ECHO) = Building Graph DB Project. This generates libgraphdb.so file _OUT directory  = 
	$(ECHO) = Copy this so file and compile a test programs with -ldl and -lgraphdb flags  = 
	$(ECHO) ================================================================================ 
	$(MKDIR) $(TARGET_DST)
	@$(foreach FNAME, $(SOURCES), $(CC) $(FLAGS) $(CFLAGS) $(FNAME).cpp $(INC) -o $(FNAME).o;)
	@$(CC) $(LDFLAGS) $(CFLAGSLD) $(SOURCES_O) -o $(TARGET_SO)
clean:
	$(RM) $(TARGET_DST)
	$(FIND) -name "*.o" -delete
test:
	$(CC) $(FLAGS) $(INC)  test/test.cpp -ldl -g -pedantic -L_out -lgraphdb -o $(TARGET_DST)/test.out

