C = gcc
CFLAGS = -march=native -O3 -mno-avx -D_XOPEN_SOURCE=600 -D_GNU_SOURCE -std=c99 \
		          -W -Wall -Werror
LDFLAGS = -lrt -lpthread

TARGETS = tlb run 

all: bench
bench: $(TARGETS)

clean:
		rm -f $(TARGETS)

.PHONY: all bench
