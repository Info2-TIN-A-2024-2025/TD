#
# Makefile
#

# set the executable name
EXEC=app

LANGUAGE = DE

CC=gcc
CFLAGS+= -std=c17 -Wall -g
CFLAGS+=  -D=_XOPEN_SOURCE
CFLAGS += -DLANGUAGE=\"$(LANGUAGE)\"
LDLIBS:= -lm 

ODIR:=obj

SRC := $(wildcard *.c)
OBJS = $(patsubst %,$(ODIR)/%,$(SRC:.c=.o))

all: clean $(EXEC)

-include $(ODIR)/*.d

$(EXEC): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS)

$(ODIR)/%.o: %.c | $(ODIR)
	$(CC) $(CFLAGS) -c $< -o $@ -MMD -MF $(@:.o=.d)

$(ODIR):
	mkdir $@

clean:
	$(RM) $(EXEC)
	$(RM) -rf $(ODIR)

test:
	@echo "Running tests..."


.PHONY:	clean all test
.DEFAULT: all 