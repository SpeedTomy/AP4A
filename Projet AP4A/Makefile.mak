# Définitions des variables
CXX = g++
CXXFLAGS = -g -Wall
OBJ = main.o Server.o
TARGET = main

# Règle par défaut
all: $(TARGET)

# Règle pour créer l'exécutable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

# Règle pour compiler main.cpp
main.o: main.cpp Server.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Règle pour compiler Server.cpp
Server.o: Server.cpp Server.h
	$(CXX) $(CXXFLAGS) -c Server.cpp

# Règle pour nettoyer les fichiers générés
clean:
	rm -f $(OBJ) $(TARGET)
