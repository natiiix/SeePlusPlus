./bin/spp: $(shell find ./src/ -type f)
	gcc -std=c++17 -lstdc++ -Wall -Wextra -pedantic -o ./bin/spp $(shell find ./src/ -iname '*.cpp')

clean:
	rm -rfv ./bin/*
