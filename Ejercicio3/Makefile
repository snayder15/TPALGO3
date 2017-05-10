# Macross

#
# 'make depend' uses makedepend to automatically generate dependencies 
#               (dependencies are added to end of Makefile)
# 'make'        build executable file 'mycc'
# 'make clean'  removes all .o and executable files
#

# define the C compiler to use
CC = g++

# define any compile-time flags
CFLAGS = -Wall -g -std=c++11

# define the C source files
SRCS = ejercicio3.cpp 

#librerias personales

LIBS= agm.cpp uds_listas.cpp aristas.cpp

# define the C object files 
OBJS = $(SRCS:.c=.o)

OBJLIBS = $(LIBS:.c=.o)

# define the executable file 
MAIN = eje3
	
.PHONY: depend clean all

all:	$(MAIN)
		
$(MAIN):	$(OBJS) $(OBJLIBS)
		$(CC) $(CFLAGS) -o $(MAIN) $(OBJS) $(OBJLIBS) $(LFLAGS)


.c.o:
		$(CC) $(CFLAGS) -c $<  -o $@

clean:
		$(RM) *.o *~ $(MAIN)