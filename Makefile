# path macros
BIN_PATH := build
OBJ_PATH := obj
SRC_PATH := src
INC_PATH := include

# tool macros
CXX ?= g++
CFLAGS := -I./$(INC_PATH) -I./$(SRC_PATH) -lfl -ly
COBJFLAGS := $(CFLAGS) -c 

# compile macros
TARGET_NAME := main
ifeq ($(OS),Windows_NT)
	TARGET_NAME := $(addsuffix .exe,$(TARGET_NAME))
endif
TARGET := $(BIN_PATH)/$(TARGET_NAME)

# src files & obj files
SRC := $(foreach x, $(SRC_PATH), $(wildcard $(addprefix $(x)/*,.c*)))
OBJ := $(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))
DEP := $(foreach x, $(INC_PATH), $(wildcard $(addprefix $(x)/*,.h*)))

# clean files list
DISTCLEAN_LIST := $(OBJ)
CLEAN_LIST := $(TARGET) \
			  $(DISTCLEAN_LIST) \
			  $(SRC_PATH)/parser.tab.cpp \
			  $(SRC_PATH)/parser.tab.hpp \
			  $(SRC_PATH)/lexer.yy.cpp

# default rule
default: makedir parser all

# non-phony targets
$(TARGET): $(OBJ)
	$(CXX) -o $@ $(OBJ) $(CFLAGS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c* $(DEP)
	$(CXX) $(COBJFLAGS) -o $@ $<

# phony rules
.PHONY: makedir
makedir:
	@mkdir -p $(BIN_PATH) $(OBJ_PATH)

.PHONY: all
all: $(TARGET)

.PHONY: parser
parser : src/parser.y src/lexer.l
	bison -t -d src/parser.y -o src/parser.tab.cpp
	flex -o src/lexer.yy.cpp src/lexer.l

.PHONY: clean
clean:
	@echo CLEAN $(CLEAN_LIST)
	@rm -f $(CLEAN_LIST)
	@rm -r ${OBJ_PATH} ${BIN_PATH}