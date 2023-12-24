CC = clang
CFLAGS = -Iinclude -Wall
DEPS_DIR = include
SRC_DIR = src
BUILD_DIR = build

DEPS = $(wildcard $(DEPS_DIR)/*.h) $(wildcard $(DEPS_DIR)/*/*.h)
SRC = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))
EXECUTABLE = $(BUILD_DIR)/main

.SECONDEXPANSION:

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	@mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXECUTABLE): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

run: $(EXECUTABLE)
	./$<