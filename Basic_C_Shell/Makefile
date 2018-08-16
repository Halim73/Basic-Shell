lab5:	cscd340Lab5.c ./tokenize/makeArgs.o ./utils/myUtils.o ./process/process.o ./Pipes/Pipes.o ./Alias/alias.o ./linkedlist/linkedList.o ./linkedlist/listUtils.o ./Histories/histories.o
	gcc -g cscd340Lab5.c ./tokenize/makeArgs.o ./utils/myUtils.o ./process/process.o ./Pipes/Pipes.o ./Alias/alias.o ./linkedlist/linkedList.o ./linkedlist/listUtils.o ./Histories/histories.o -o lab5

makeArgs.o:	./tokenize/makeArgs.c ./tokenize/makeArgs.h
	gcc -g -c ./tokenize/makeArgs.c

myUtils.o:	./utils/myUtils.o ./utils/myUtils.h
	gcc -g -c ./utils/myUtils.c

process.o:	./process/process.c ./process/process.h
	gcc -g -c ./process/process.c	

Pipes.o:	./Pipes/Pipes.c ./Pipes/Pipes.h
	gcc -g -c ./Pipes/Pipes.c

listUtils.o:	./linkedlist/listUtils.c listUtils.h
	gcc  -g -c ./linkedlist/listUtils.c

linkedlist.o:	./linkedlist/linkedList.h ./linkedlist/linkedList.c
	gcc -g -c ./linkedlist/linkedList.c

alias.o:	./Alias/alias.h ./Alias/alias.c
	gcc -g -c ./Alias/alias.c

histories.o:	./Histories/histories.h ./Histories/histories.c
	gcc -g -c ./Histories/histories.c

clean:
	rm ./tokenizez/makeArgs.o
	rm ./utils/myUtils.o
	rm ./process/process.o
	rm ./Pipes/pipes.o
	rm ./linkedlist/listUtils.o
	rm ./linkedlist/linkedlist.o
	rm ./alias/alias.o
	rm lab5
    