compile runme: program.c
	@gcc -o runme -g program.c

run: runme
	@./runme

clean:
	@rm -f runme
