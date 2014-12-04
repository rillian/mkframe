PROGS := mk2frame

CFLAGS := -g -Wall -O2

all: $(PROGS)

check: all

clean:
	$(RM) $(PROGS)
