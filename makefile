all:
	gcc server.cpp -o server
	gcc update.cpp -o update
clean:
	rm -f server update
