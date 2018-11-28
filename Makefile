io : io.cpp
	g++ io.cpp -std=c++11 -Wall -o io
mmio : mmio.cpp
	g++ mmio.cpp -std=c++11 -Wall -o mmio
clean:
	rm io mmio -f
