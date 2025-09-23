PREFIX := /usr/local

.PHONY: all clean install

all:
	$(MAKE) -C src

clean:
	$(MAKE) -C src clean
	rm -rf obj lib bin

install: all
	# Create required directories
	sudo mkdir -p $(PREFIX)/bin
	sudo mkdir -p $(PREFIX)/share/man/man1
	sudo mkdir -p $(PREFIX)/share/man/man3

	# Install the binary
	sudo cp bin/client $(PREFIX)/bin/

	# Install man pages for functions
	sudo cp man/man3/*.1 $(PREFIX)/share/man/man3/

	# Update man database
	sudo mandb

