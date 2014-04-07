all:
	@echo "Make all of scgen."
	mkdir -p build/
	cd build/ && cmake ../

	make compile

compile:
	cd build/ && make

