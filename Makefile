CC = gcc	# le compilateur `a utiliser
CFLAGS = -Wall	# les options du compilateur
LDFLAGS =	# les options pour l’ ́editeur de liens
SRC = cal.c pile.cal# les fichiers sources
PROG = clean# nom de l’ex ́ecutable
OBJS =  $(SRC:.c=.o)	# les .o qui en d ́ecoulent

.SUFFIXES: .c .options# lien entre les suffixes
all: $(PROG)


#  ́etapes de compilation et d’ ́edition de liens

$(PROG): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^	# $@ la cible $^ toutes les d ́ependances

cal.o: pile.h

pile.o: pile.h


# le lien entre .o et .c
%.o: %.c
	$(CC) $(CFLAGS) -c $<	# $< derni`ere d ́ependance


# pour faire propre
.PHONY: clean

clean:
	rm -f *.o *~ core $(PROG)