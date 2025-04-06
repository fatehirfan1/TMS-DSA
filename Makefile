all: ./a.out

compRun:
	g++ -std=c++11 main.cpp Ticket.cpp History.cpp CategoryTree.cpp TicketManager.cpp -o r.out
run: clean compRun; ./r.out
clean:
	rm -f *.out
