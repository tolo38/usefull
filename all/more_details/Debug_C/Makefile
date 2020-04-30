CC=clang
CFLAGS=-std=c99 -Wall -Wextra 
FSANITIZE=-fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer -O0

#edition de lien
LDFLAGS= -g

#$1 #nom du programe
EXEC=$1

all: $(EXEC) $(EXEC)_fsanitize

$(EXEC): $(EXEC).c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

$(EXEC)_fsanitize: $(EXEC).c
	$(CC) -o $@ $^ $(CFLAGS) $(FSANITIZE) $(LDFLAGS)

.PHONY: clean
clean:
	rm -f *~ *.o $(EXEC) $(EXEC)_fsanitize
