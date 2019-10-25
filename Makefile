CC = gcc
CXX = g++
#CC = clang
#CXX = clang++
#CFLAGS += -Wall -g -O0
#CFLAGS += -Wall -g -O1 -fstack-protector-all
#CFLAGS += -Wall -g -O1 -D_FORTIFY_SOURCE=1 -fstack-protector-all
CFLAGS += -Wall -O3 -march=native
LDFLAGS = -s

TARGETS = make-eicar

all: $(TARGETS)

.PHONY: clean
clean:
	$(RM) $(TARGETS) *.o eicar.txt
