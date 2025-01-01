

SRC_CPP = $(wildcard *.cpp)
SRC_RS = $(wildcard *.rs)
SRC = $(SRC_CPP) $(SRC_RS)
OUT = $(SRC:.cpp=.out) $(SRC:.rs=.out)

all: $(OUT)
	@echo "Compiling all source files"

%.out: %.rs
	@echo "Linking object files: $<"
	@rustc $< -o $@

%.out: %.cpp
	@echo "Linking object files: $<"
	@g++ $< -o $@

clean:
	@echo "Cleaning up..."
	@rm -f *.out

#
# %.cpp:
# 	@echo $(SRC_CPP)
# 	@echo "Compiling C++ code: $<"
# 	@g++ $@ -o $(@:.cpp=.out)
#
# # Rust 파일 컴파일 규칙
# %.rs:
# 	@echo "Compiling Rust code: $<"

.PHONY: all
