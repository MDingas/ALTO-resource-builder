TARGET = alto_resource_builder
CC = gcc
LDFLAGS = -l json-c
CFLAGS = -g -Wall
OBJECT = $(%.o)

default: $(TARGET)

argument_parser.o : argument_parser.c argument_parser.h
	$(CC) $(CFLAGS) -c argument_parser.c -o $@

alto_resource_builder.o : alto_resource_builder.c alto_resource_builder.h argument_parser.o
	$(CC) $(CFLAGS) -c alto_resource_builder.c argument_parser.o -o $@

main.o : main.c argument_parser.o alto_resource_builder.o
	$(CC) $(CFLAGS) -c main.c -o $@

alto_resource_builder: argument_parser.o alto_resource_builder.o main.o
	$(CC) $(LDFLAGS) argument_parser.o alto_resource_builder.o main.o $(CFLAGS) -o $@

clean:
	rm -f *.o
	rm -f $(TARGET)

