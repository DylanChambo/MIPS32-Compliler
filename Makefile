# path macros
BIN_PATH := build
OBJ_PATH := obj
SRC_PATH := src
INC_PATH := include
LIB_PATH := lib
TEST_PATH := test

# tool macros
CXX := g++
CFLAGS := -I./$(INC_PATH) -I./$(LIB_PATH)
COBJFLAGS := $(CFLAGS) -c

# compile macros
TARGET_NAME := main
TEST_TARGET_NAME := test
ifeq ($(OS),Windows_NT)
	TARGET_NAME := $(addsuffix .exe,$(TARGET_NAME))
	TEST_TARGET_NAME := $(addsuffix .exe,$(TEST_TARGET_NAME))
endif
TARGET := $(BIN_PATH)/$(TARGET_NAME)
TEST_TARGET := $(BIN_PATH)/$(TEST_TARGET_NAME)

# src files & obj files
SRC := $(foreach x, $(SRC_PATH), $(wildcard $(addprefix $(x)/*,.c*)))
TEST_SRC := $(foreach x, $(TEST_PATH), $(wildcard $(addprefix $(x)/*,.c*)))
OBJ := $(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))
OBJ_TEST := $(filter-out $(OBJ_PATH)/main.o, $(OBJ)) $(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(notdir $(basename $(TEST_SRC)))))
DEP := $(foreach x, $(INC_PATH), $(wildcard $(addprefix $(x)/*,.h*)))

# clean files list
DISTCLEAN_LIST := $(OBJ)
CLEAN_LIST := $(TARGET) \
			  $(DISTCLEAN_LIST)

# default rule
default: makedir all

# non-phony targets
$(TARGET): $(OBJ)
	$(CXX) -o $@ $(OBJ) $(CFLAGS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c* $(DEP)
	$(CXX) $(COBJFLAGS) -o $@ $<

$(TEST_TARGET): $(OBJ_TEST)
	$(CXX) -o $@ $(OBJ_TEST) $(CFLAGS)

$(OBJ_PATH)/%.o: $(TEST_PATH)/%.c* $(DEP)
	$(CXX) $(COBJFLAGS) -o $@ $<

test: $(TEST_TARGET)
	@$(TEST_TARGET)

# phony rules
.PHONY: makedir
makedir:
	@mkdir -p $(BIN_PATH) $(OBJ_PATH)

.PHONY: all
all: $(TARGET)

.PHONY: clean
clean:
	@echo CLEAN $(CLEAN_LIST)
	@rm -f $(CLEAN_LIST)
	@rm -r ${OBJ_PATH} ${BIN_PATH}