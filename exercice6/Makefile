##
## Objectif : Compiler notre programme exo6.c avec la SFML
## Date : 12/11/2023
## Auteur : Bousbia Ayoub
## Guide d'utilisation :
## - Installer la SFML sur votre machine
## - Remplacer le chemin de LDFLAGS par le chemin de votre librairie present sur
## 	 votre machine
## - Taper make depuis votre terminal puis lancer l'executable avec la commande ./exo6
##

CC	=	gcc
LDFLAGS = -L/usr/local/lib -lcsfml-window -lcsfml-graphics
LIBS= -lm

SRC	= main.c

OBJ	=	$(SRC:.c=.o)

TARGET	=	exo6

RM	=	rm -f

all:	$(TARGET)

$(TARGET):	$(OBJ)
	$(CC) -o  $(TARGET) $(SRC) $(LDFLAGS) $(LIBS)

clean:
	$(RM) $(OBJ)