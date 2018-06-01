CC = gcc				# le compilateur `a utiliser
CFLAGS = -ansi -Wall	# les options du compilateur
LDFLAGS = -lsx			# les options pour l’editeur de liens
SRC = conv.c callbacks.c data.c # les fichiers sources
PROG = conv				# nom de l’executable
OBJS =  $(SRC:.c=.o)	# les .o qui en decoulent
.SUFFIXES: .c .o 		# lien entre les suffixes


all: $(PROG)


#  ́etapes de compilation et d’ ́edition de liens

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^	$(LDFLAGS) # $@ la cible $^ toutes les dependances

callbacks.o: callbacks.h data.h
data.o: data.h
conv.o: data.h callbacks.h


# le lien entre .o et .c
%.o: %.c
	$(CC) $(CFLAGS) -c $<	# $< derniere dependance


# pour faire propre
.PHONY: clean

clean:
	rm -f *.o *~ core $(PROG)