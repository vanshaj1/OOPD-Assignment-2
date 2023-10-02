all: debug optimization
		

debug:
		g++ -g solution.cpp -o debug

optimization:
		g++ -O solution.cpp -o optimized