##
# Project Settings
#
# NAME       - Used for includes (exclude extension)
# DEV_SRC    - Development source folder
# DEV_BIN    - Development executable folder
# HEADER     - Include without implementation
# IMPL_ENTRY - Include with implementation (uni-build)
# IMPL_PARTS - Implementations that IMPL_ENTY includes (for detecting changes)
# SPEC       - Test suite for library specification (uni-build)
##
    NAME       := code
    DEV_SRC    := ../src
    DEV_BIN    := .
    HEADER     := $(DEV_SRC)/$(NAME).h
    IMPL_ENTRY := $(DEV_SRC)/$(NAME).c
    IMPL_PARTS := $(shell find $(DEV_SRC)/$(NAME) -maxdepth 1 -name "*.c")
    SPEC       := $(DEV_SRC)/$(NAME).spec.c

##
# Compier Settings
#
# CC         - Only tested with clang, but should be universal
# CFLAGS     - Any compile flags you would like your editor to see
# TARGET     - The library name, be sure to change for your OS
#            - macOS libNAME.a
#            - linux libNAME.so
##
    CC         := clang
    CFLAGS     := @../compile_flags.txt
    TARGET     := lib$(NAME).a
    TESTS      := test-$(NAME)

##
# Make Commands
##
    .PHONEY : all clean lib tests test

    all: clean lib tests test

    clean:
	@rm -rf $(TARGET) $(TESTS)* $(NAME)* lib$(NAME)*

    lib: $(TARGET)

    tests: $(TESTS)

    test: $(TESTS)
	@./$<

##
# BUILD TARGETS
##
    $(DEV_BIN)/lib$(NAME).o: $(HEADER) $(IMPL_ENTRY) $(IMPL_PARTS)
	@$(CC) $(CFLAGS) -c -fPIC -O3 -o $@ $(IMPL_ENTRY)

    $(DEV_BIN)/$(TARGET): lib$(NAME).o
	@ar rcs $@ $<

    $(DEV_BIN)/$(TESTS): $(SPEC) $(HEADER) $(IMPL_ENTRY) $(IMPL_PARTS)
	@$(CC) $(CFLAGS) -g3 -o $@ $(SPEC)
