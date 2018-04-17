OBJECTS = card.o deck.o rank.o pokerhand.o main.o SortedLinkedList.o
HEADERS = card.h deck.h rank.h pokerhand.h SortedLinkedList.h
TESTOBJS = card.o deck.o rank.o pokerhand.o SortedLinkedList.o testPA2.o
CS216PA2: $(OBJECTS)#make main CS216PA2 
	g++ $^ -o $@
testPA2: $(TESTOBJS)	#make testPA2
	g++ $^ -o $@
%.o: %.cpp $(HEADERS)	#track changes
	g++ -c $< -o $@
clean:					#clean, ask for permission
	rm -i *.o CS216PA2	
