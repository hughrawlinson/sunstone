CFLAGS += $(shell pkg-config --cflags json-c)
LDFLAGS += $(shell pkg-config --libs json-c)

build:
	gcc $(CFLAGS) $(LDFLAGS) -o sunstone sunstone.c
