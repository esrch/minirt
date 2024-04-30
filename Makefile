
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./inc -I./lib/libft
LDFLAGS = -L./lib/libft
LDLIBS = -lm -lft

SRC_DIR = src
INC_DIR = inc
SRCS = $(shell find $(SRC_DIR) -type f -name '*.c')
OBJS = $(SRCS:.c=.o)
OBJS_NO_MAIN = $(filter-out %main.o, $(OBJS))

LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a

TEST_DIR = tests
TESTS = $(shell find $(TEST_DIR) -type f -name '*.c')
TEST_BINS = $(patsubst $(TEST_DIR)/%.c, $(TEST_DIR)/bin/%, $(TESTS))

BIN_DIR = bin
BIN = $(BIN_DIR)/minirt

.PHONY: all clean fclean re

all: $(BIN)

$(BIN): $(BIN_DIR) $(OBJS) $(LIBFT)
	$(RM) $(BIN)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $@ $(LDLIBS)

$(OBJS): %.o: %.c $(LIBFT)
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_DIR)/bin/%: LDLIBS += -lcriterion
$(TEST_DIR)/bin/%: $(TEST_DIR)/%.c $(OBJS_NO_MAIN) $(LIBFT)
	$(CC) $(CFLAGS) $(LDFLAGS) $< $(OBJS_NO_MAIN) -o $@ $(LDLIBS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(BIN_DIR):
	mkdir $@

$(TEST_DIR)/bin:
	mkdir $@

test: $(OBJS_NO_MAIN) $(TEST_DIR)/bin $(TEST_BINS)
	for test in $(TEST_BINS) ; do ./$$test ; done

test-valgrind: $(OBJS_NO_MAIN) $(TEST_DIR)/bin $(TEST_BINS)
	for test in $(TEST_BINS) ; do valgrind --trace-children=yes -- ./$$test ; done

clean:
	$(RM) $(OBJS)
	$(RM) $(TEST_BINS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(BIN)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all