TARGET_EXEC := cetmodity

BIN_DIR := ./bin
SRC_DIR := ./src
OBJ_DIR := ./obj
INC_DIR := ./include

SRCS := $(shell find $(SRC_DIR) -name "*.c")

OBJS := $(SRCS:%=$(OBJ_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_FLAGS := $(addprefix -I,$(INC_DIR))
LDFLAGS := -lm

CPPFLAGS := $(INC_FLAGS) -MMD -MP

all: $(BIN_DIR)/$(TARGET_EXEC)

$(BIN_DIR)/$(TARGET_EXEC): $(OBJS)
	mkdir -p $(dir $(BIN_DIR))
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(BIN_DIR)/* $(OBJ_DIR)/*

-include $(DEPS)
