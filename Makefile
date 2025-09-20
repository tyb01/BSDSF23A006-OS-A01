# Top-level Makefile - recursive approach
.PHONY: all clean

all:
	$(MAKE) -C src

clean:
	$(MAKE) -C src clean
	rm -rf obj
