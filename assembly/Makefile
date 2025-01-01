
SRC := $(wildcard *.s)
OBJ := $(SRC:.s=.o)
NAME := a.out

all: $(NAME)
	@echo "[Run]\t'$<'"
	@echo "------ Running Program ------"
	@./$<
	@echo "-----------------------------"

$(NAME): $(OBJ)
	@echo "[Linking]\t'$@'"
	ld -o $@ $^ -lSystem \
	   -syslibroot `xcrun -sdk macosx --show-sdk-path` \
	   -e _start	\
	   -arch arm64	\
	   -macos_version_min 15.0

%.o: %.s
	@echo "[Compiling]\t'$<'"
	@as -arch arm64 -g -o $@ $<

clean:
	@rm -f $(OBJ) $(NAME)
	@echo "[Cleaned]"

re: clean all
	
debug: $(NAME)
	@echo "[Debugging]\t'$<'"
	lldb ./$(NAME)


.PHONY: all clean re
