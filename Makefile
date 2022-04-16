CC = gcc
CFLAGS = -W -Wall
TARGET = prod
DTARGET = prod_d
OBJECTS = main.c manager.o product.c

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
$(DTARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -DDEBUG -o $@ $^
clean:
	rm *.o prod prod_d

