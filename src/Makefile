CC     = gcc
CFLAGS = -g -Wall
LFLAGS = -lglfw3 -lGL -lm -lX11 -lpthread -lXi -lXrandr -ldl
IFLAGS = -Iinc/

.PHONY: all clean re

TGT  = main
SRCS = main.c pixel.c
OBJS = $(SRCS:.c=.o)

all: $(TGT)


$(TGT): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) $(IFLAGS) -o $(TGT)

%.o: %.c
	$(CC) $(CFLAGS) $(LFLAGS) $(IFLAGS) -c $^ -o $@ 

clean:
	@rm -f $(TGT) $(OBJS)
	@echo "clean"

re: clean all
