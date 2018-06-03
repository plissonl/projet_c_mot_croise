CC = gcc					# le compilateur `a utiliser
CFLAGS = -std=gnu99 -Wall	# les options du compilateur
LDFLAGS = -lsx				# les options pour l’editeur de liens
SRC = main.c callbacks.c data.c # les fichiers sources
PROG = interface				# nom de l’executable
OBJS =  $(SRC:.c=.o)		# les .o qui en decoulent
.SUFFIXES: .c .o 			# lien entre les suffixes


all: $(PROG)


#  ́etapes de compilation et d’ ́edition de liens
# $@ la cible $^ toutes les dependances
$(PROG): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^	$(LDFLAGS) 

callbacks.o: callbacks.h data.h
data.o: data.h
main.o: data.h callbacks.h


# le lien entre .o et .c
# $< derniere dependance
%.o: %.c
	$(CC) $(CFLAGS) -c $<	


# pour faire propre
.PHONY: clean

clean:
	rm -f *.o *~ core $(PROG)