# Macros
COMPILER  = g++
DEBUG  = -g

# Default target: app (creates executable app)
app: Term.o TermArrayList.o TermDblLinkList.o TermSTLObjList.o app.o  
	$(COMPILER) -o app Term.o TermArrayList.o TermDblLinkList.o TermSTLObjList.o app.o $(DEBUG)

Term.o:  Term.cpp Term.h 
	$(COMPILER) -c Term.cpp $(DEBUG)

TermArrayList.o:  Term.h TermArrayList.cpp TermArrayList.h TermList.h 
	$(COMPILER) -c TermArrayList.cpp $(DEBUG)

TermSTLObjList.o: Term.h TermSTLObjList.cpp TermSTLObjList.h TermList.h
	$(COMPILER) -c TermSTLObjList.cpp $(DEBUG)	

TermDblLinkList.o: Term.h TermDblLinkList.cpp TermDblLinkList.h TermList.h
	$(COMPILER) -c TermDblLinkList.cpp $(DEBUG)

app.o:  TermArrayList.h TermList.h TermSTLObjList.h TermDblLinkList.h Term.h app.cpp 
	$(COMPILER) -c app.cpp $(DEBUG)

clean:
	rm -rf *.o testLL testLL.exe
