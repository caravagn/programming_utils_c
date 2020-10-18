main:
	gcc main.c -o main

clean:
	rm main

test1: main
	bash check.sh ex1

