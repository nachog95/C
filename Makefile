test: test.c
	gcc test.c -o test
clean:
	rm -f  test
	rm -f  *.o
