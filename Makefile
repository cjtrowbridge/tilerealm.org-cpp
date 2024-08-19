# Compiler
CC = clang++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude -pedantic -v
LDFLAGS = -pthread -lstdc++fs -ljsoncpp -llept

# Target executable
TARGET = tilerealm

# Source files
SRCS = src/main.cpp \
       src/state.cpp \
       src/server.cpp \
       src/logging.cpp \
       src/helpers.cpp \
       src/signals.cpp \
       src/generate_default_realm.cpp \
       src/discover_local_peers.cpp \
       src/discover_remote_peers.cpp \
       src/load_configuration.cpp \
       src/help.cpp

# Object files directory
OBJDIR = build/obj

# Object files (automatically generated from SRCS)
OBJS = $(patsubst src/%.cpp, $(OBJDIR)/%.o, $(SRCS))

# Default rule: compile and link
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $(TARGET) $(OBJS)

$(OBJDIR)/%.o: src/%.cpp | $(OBJDIR)
	$(CC) $(CXXFLAGS) -c $< -o $@

# Ensure the object directory exists
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Clean rule: remove all generated files
clean:
	rm -rf $(OBJDIR) $(TARGET)

# Run rule: execute the compiled binary
run: $(TARGET)
	./$(TARGET)

setup:
	apt-get install nlohmann-json3-dev libjsoncpp-dev

# PHONY targets to avoid file conflicts
.PHONY: all clean run