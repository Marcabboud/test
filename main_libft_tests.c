/* Standalone Libft Part 1 + Part 2 test driver. NOT for submission. */
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>
#include <fcntl.h>
#include <errno.h>

static int g_pass;
static int g_fail;

static void check(int ok, const char *func, const char *case_name)
{
    if (ok)
        g_pass++;
    else
    {
        g_fail++;
        printf("FAIL %-16s %s\n", func, case_name);
    }
}
#define CHECK(fn, label, cond) check(!!(cond), (fn), (label))

static int equal_string(const char *actual, const char *expected)
{
    return actual && expected && strcmp(actual, expected) == 0;
}

static void test_classification(void)
{
    int c;
    int alpha;
    int digit;
    int ascii;
    int printable;

    for (c = -1; c <= 255; c++)
    {
        alpha = (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
        digit = c >= '0' && c <= '9';
        ascii = c >= 0 && c <= 127;
        printable = c >= 32 && c <= 126;
        CHECK("ft_isalpha", "all -1..255", ft_isalpha(c) == alpha);
        CHECK("ft_isdigit", "all -1..255", ft_isdigit(c) == digit);
        CHECK("ft_isalnum", "all -1..255", ft_isalnum(c) == (alpha || digit));
        CHECK("ft_isascii", "all -1..255", ft_isascii(c) == ascii);
        CHECK("ft_isprint", "all -1..255", ft_isprint(c) == printable);
        CHECK("ft_toupper", "all -1..255", ft_toupper(c) == ((c >= 'a' && c <= 'z') ? c - 32 : c));
        CHECK("ft_tolower", "all -1..255", ft_tolower(c) == ((c >= 'A' && c <= 'Z') ? c + 32 : c));
    }
}

static void test_strings_1(void)
{
    const char *s = "abcabc";
    const char *empty = "";
    char a[] = {(char)200, 'b', '\0'};
    char b[] = {(char)100, 'b', '\0'};

    CHECK("ft_strlen", "empty", ft_strlen("") == 0);
    CHECK("ft_strlen", "normal", ft_strlen("42 Paris") == 8);
    CHECK("ft_strlen", "stops at NUL", ft_strlen("abc\0def") == 3);
    CHECK("ft_strchr", "first match", ft_strchr(s, 'a') == s);
    CHECK("ft_strchr", "later match", ft_strchr(s, 'c') == s + 2);
    CHECK("ft_strchr", "missing", ft_strchr(s, 'z') == NULL);
    CHECK("ft_strchr", "NUL", ft_strchr(s, 0) == s + 6);
    CHECK("ft_strchr", "int converted to char", ft_strchr(s, 256 + 'b') == s + 1);
    CHECK("ft_strchr", "empty NUL", ft_strchr(empty, 0) == empty);
    CHECK("ft_strrchr", "last match", ft_strrchr(s, 'a') == s + 3);
    CHECK("ft_strrchr", "missing", ft_strrchr(s, 'z') == NULL);
    CHECK("ft_strrchr", "NUL", ft_strrchr(s, 0) == s + 6);
    CHECK("ft_strrchr", "empty NUL", ft_strrchr(empty, 0) == empty);
    CHECK("ft_strncmp", "n=0", ft_strncmp("a", "z", 0) == 0);
    CHECK("ft_strncmp", "equal", ft_strncmp("abc", "abc", 3) == 0);
    CHECK("ft_strncmp", "bounded equal", ft_strncmp("abcX", "abcY", 3) == 0);
    CHECK("ft_strncmp", "differ", ft_strncmp("abc", "abd", 3) < 0);
    CHECK("ft_strncmp", "prefix", ft_strncmp("abc", "abcd", 8) < 0);
    CHECK("ft_strncmp", "unsigned bytes", ft_strncmp(a, b, 1) > 0);
}

static void test_memory(void)
{
    unsigned char a[32];
    unsigned char b[32];
    unsigned char x[] = {0, 255, 23, 0, 8};
    unsigned char y[] = {0, 254, 23, 0, 8};
    char overlap1[16] = "123456789";
    char overlap2[16] = "123456789";
    size_t i;

    for (i = 0; i < sizeof(a); i++)
    {
        a[i] = (unsigned char)i;
        b[i] = (unsigned char)i;
    }
    CHECK("ft_memset", "return pointer", ft_memset(a + 4, 'Q', 5) == a + 4);
    memset(b + 4, 'Q', 5);
    CHECK("ft_memset", "same bytes", memcmp(a, b, 32) == 0);
    CHECK("ft_memset", "zero length", ft_memset(a, 'Z', 0) == a);
    CHECK("ft_bzero", "middle bytes", (ft_bzero(a + 7, 6), memset(b + 7, 0, 6), memcmp(a, b, 32) == 0));
    CHECK("ft_memcpy", "copy bytes and return", ft_memcpy(a, x, 5) == a && memcmp(a, x, 5) == 0);
    CHECK("ft_memcpy", "copy zero", ft_memcpy(a, x, 0) == a);
    CHECK("ft_memmove", "overlap to right", (ft_memmove(overlap1 + 2, overlap1, 5),
        memmove(overlap2 + 2, overlap2, 5), strcmp(overlap1, overlap2) == 0));
    strcpy(overlap1, "123456789");
    strcpy(overlap2, "123456789");
    CHECK("ft_memmove", "overlap to left", (ft_memmove(overlap1, overlap1 + 2, 5),
        memmove(overlap2, overlap2 + 2, 5), memcmp(overlap1, overlap2, 10) == 0));
    CHECK("ft_memmove", "same pointer", ft_memmove(overlap1, overlap1, 9) == overlap1);
    CHECK("ft_memmove", "zero length", ft_memmove(overlap1, overlap2, 0) == overlap1);
    CHECK("ft_memchr", "find zero", ft_memchr(x, 0, 5) == x);
    CHECK("ft_memchr", "find 255", ft_memchr(x, 255, 5) == x + 1);
    CHECK("ft_memchr", "out of range", ft_memchr(x, 8, 4) == NULL);
    CHECK("ft_memchr", "n=0", ft_memchr(x, 0, 0) == NULL);
    CHECK("ft_memcmp", "equal", ft_memcmp(x, x, 5) == 0);
    CHECK("ft_memcmp", "positive unsigned", ft_memcmp(x, y, 5) > 0);
    CHECK("ft_memcmp", "negative unsigned", ft_memcmp(y, x, 5) < 0);
    CHECK("ft_memcmp", "n=0", ft_memcmp(x, y, 0) == 0);
}

static void check_strlcpy_case(const char *name, const char *src, size_t size)
{
    char a[40];
    char b[40];
    size_t result;
    size_t expected;

    memset(a, '#', sizeof(a));
    memset(b, '#', sizeof(b));
    result = ft_strlcpy(a, src, size);
    expected = strlen(src);
    if (size)
    {
        size_t n = expected < size - 1 ? expected : size - 1;
        memcpy(b, src, n);
        b[n] = '\0';
    }
    CHECK("ft_strlcpy", name, result == expected && memcmp(a, b, sizeof(a)) == 0);
}

static void check_strlcat_case(const char *name, const char *initial, const char *src, size_t size)
{
    char a[48];
    char b[48];
    size_t original;
    size_t bounded;
    size_t n;
    size_t expected;
    size_t result;

    memset(a, '#', sizeof(a));
    memset(b, '#', sizeof(b));
    original = strlen(initial);
    memcpy(a, initial, original + 1);
    memcpy(b, initial, original + 1);
    bounded = original < size ? original : size;
    expected = bounded + strlen(src);
    if (original < size)
    {
        n = strlen(src);
        if (n > size - original - 1)
            n = size - original - 1;
        memcpy(b + original, src, n);
        b[original + n] = '\0';
    }
    result = ft_strlcat(a, src, size);
    CHECK("ft_strlcat", name, result == expected && memcmp(a, b, sizeof(a)) == 0);
}

static void test_bounded_strings(void)
{
    const char *hay = "abcabc";

    check_strlcpy_case("size 0", "abcdef", 0);
    check_strlcpy_case("size 1", "abcdef", 1);
    check_strlcpy_case("exact", "abcdef", 7);
    check_strlcpy_case("truncated", "abcdef", 4);
    check_strlcpy_case("empty", "", 5);
    check_strlcat_case("size 0", "abc", "XYZ", 0);
    check_strlcat_case("size < dest", "abc", "XYZ", 2);
    check_strlcat_case("size = dest", "abc", "XYZ", 3);
    check_strlcat_case("size 4", "abc", "XYZ", 4);
    check_strlcat_case("size 5", "abc", "XYZ", 5);
    check_strlcat_case("fits", "abc", "XYZ", 12);
    check_strlcat_case("empty dest", "", "XYZ", 4);
    check_strlcat_case("empty src", "abc", "", 12);
    CHECK("ft_strnstr", "empty needle n=0", ft_strnstr(hay, "", 0) == hay);
    CHECK("ft_strnstr", "full match", ft_strnstr(hay, "abc", 6) == hay);
    CHECK("ft_strnstr", "second match", ft_strnstr(hay, "bca", 6) == hay + 1);
    CHECK("ft_strnstr", "match too long", ft_strnstr(hay, "abc", 2) == NULL);
    CHECK("ft_strnstr", "cut at boundary", ft_strnstr(hay, "bca", 3) == NULL);
    CHECK("ft_strnstr", "exact boundary", ft_strnstr(hay, "bca", 4) == hay + 1);
    CHECK("ft_strnstr", "missing", ft_strnstr(hay, "zzz", 6) == NULL);
    CHECK("ft_strnstr", "needle longer", ft_strnstr(hay, "abcabcx", 7) == NULL);
    CHECK("ft_strnstr", "n=0", ft_strnstr(hay, "abc", 0) == NULL);
}

static void test_alloc_and_atoi(void)
{
    char *p;
    unsigned char *z;
    size_t i;

    CHECK("ft_atoi", "zero", ft_atoi("0") == 0);
    CHECK("ft_atoi", "spaces/sign", ft_atoi(" \t\n-42xx") == -42);
    CHECK("ft_atoi", "plus", ft_atoi("+42") == 42);
    CHECK("ft_atoi", "two signs", ft_atoi("--42") == 0);
    CHECK("ft_atoi", "no digits", ft_atoi("abc") == 0);
    CHECK("ft_atoi", "INT_MAX", ft_atoi("2147483647") == INT_MAX);
    CHECK("ft_atoi", "INT_MIN", ft_atoi("-2147483648") == INT_MIN);
    CHECK("ft_atoi", "leading zero", ft_atoi("00013") == 13);
    p = ft_strdup("some words");
    CHECK("ft_strdup", "contents", equal_string(p, "some words"));
    CHECK("ft_strdup", "independent", p && strcmp(p, "some words") == 0);
	free(p);
    p = ft_strdup("");
    CHECK("ft_strdup", "empty", equal_string(p, ""));
    free(p);
    z = ft_calloc(13, 4);
    if (z)
    {
        for (i = 0; i < 52 && z[i] == 0; i++)
            ;
    }
    else
        i = 0;
    CHECK("ft_calloc", "zero-filled", z && i == 52);
    free(z);
    z = ft_calloc(0, 16);
    CHECK("ft_calloc", "zero count freeable", z != NULL);
    free(z);
    z = ft_calloc(16, 0);
    CHECK("ft_calloc", "zero size freeable", z != NULL);
    free(z);
    z = ft_calloc(SIZE_MAX, 2);
    CHECK("ft_calloc", "overflow rejected", z == NULL);
    free(z);
}

static void test_alloc_string(const char *fn, const char *case_name, char *actual, const char *expected)
{
    CHECK(fn, case_name, equal_string(actual, expected));
    free(actual);
}

static int split_equals(char **parts, const char *const *expected, size_t n)
{
    size_t i;
    int ok;

    if (!parts)
        return 0;
    i = 0;
    ok = 1;
    while (i < n)
    {
        if (!parts[i] || strcmp(parts[i], expected[i]))
            ok = 0;
        if (!parts[i])
            break;
        i++;
    }
    if (i == n && parts[i] != NULL)
        ok = 0;
    i = 0;
    while (parts[i])
        free(parts[i++]);
    free(parts);
    return ok;
}

static void test_part2_strings(void)
{
    const char *words1[] = {"one", "two", "three"};
    const char *words2[] = {"hello"};
    const char *words3[] = {"a", "b", "c"};
    char *p;

    test_alloc_string("ft_substr", "middle", ft_substr("abcdef", 2, 3), "cde");
    test_alloc_string("ft_substr", "len too large", ft_substr("abc", 1, 100), "bc");
    test_alloc_string("ft_substr", "start = end", ft_substr("abc", 3, 2), "");
    test_alloc_string("ft_substr", "start > end", ft_substr("abc", 99, 2), "");
    test_alloc_string("ft_substr", "zero len", ft_substr("abc", 1, 0), "");
    test_alloc_string("ft_substr", "empty", ft_substr("", 0, 5), "");
    test_alloc_string("ft_substr", "SIZE_MAX len", ft_substr("abc", 1, SIZE_MAX), "bc");
    test_alloc_string("ft_strjoin", "normal", ft_strjoin("hello", " world"), "hello world");
    test_alloc_string("ft_strjoin", "both empty", ft_strjoin("", ""), "");
    test_alloc_string("ft_strjoin", "first empty", ft_strjoin("", "z"), "z");
    test_alloc_string("ft_strjoin", "second empty", ft_strjoin("a", ""), "a");
    test_alloc_string("ft_strtrim", "both ends", ft_strtrim("xxhelloxx", "x"), "hello");
    test_alloc_string("ft_strtrim", "mixed set", ft_strtrim(" \t!hello!\t ", " \t!"), "hello");
    test_alloc_string("ft_strtrim", "all trimmed", ft_strtrim("xxxx", "x"), "");
    test_alloc_string("ft_strtrim", "no trim", ft_strtrim("hello", "x"), "hello");
    test_alloc_string("ft_strtrim", "empty set", ft_strtrim("hello", ""), "hello");
    test_alloc_string("ft_strtrim", "empty source", ft_strtrim("", "x"), "");
    CHECK("ft_split", "three words", split_equals(ft_split(" one  two three ", ' '), words1, 3));
    CHECK("ft_split", "one word", split_equals(ft_split("hello", ' '), words2, 1));
    CHECK("ft_split", "only delimiters", split_equals(ft_split("::::", ':'), NULL, 0));
    CHECK("ft_split", "empty", split_equals(ft_split("", ','), NULL, 0));
    CHECK("ft_split", "NUL delimiter", split_equals(ft_split("hello", '\0'), words2, 1));
    CHECK("ft_split", "consecutive", split_equals(ft_split("a,,b,c", ','), words3, 3));
    p = ft_itoa(0); CHECK("ft_itoa", "zero", equal_string(p, "0")); free(p);
    p = ft_itoa(42); CHECK("ft_itoa", "positive", equal_string(p, "42")); free(p);
    p = ft_itoa(-42); CHECK("ft_itoa", "negative", equal_string(p, "-42")); free(p);
    p = ft_itoa(INT_MAX); CHECK("ft_itoa", "INT_MAX", equal_string(p, "2147483647")); free(p);
    p = ft_itoa(INT_MIN); CHECK("ft_itoa", "INT_MIN", equal_string(p, "-2147483648")); free(p);
}

static char transform(unsigned int i, char c)
{
    return (char)(c + (int)i);
}

static void transform_in_place(unsigned int i, char *c)
{
    *c = (char)(*c + (int)i);
}

static void test_callbacks(void)
{
    char src[] = "abcd";
    char *result;

    result = ft_strmapi("abcd", transform);
    CHECK("ft_strmapi", "indexes and new string", equal_string(result, "aceg"));
    free(result);
    result = ft_strmapi("", transform);
    CHECK("ft_strmapi", "empty", equal_string(result, ""));
    free(result);
    ft_striteri(src, transform_in_place);
    CHECK("ft_striteri", "mutates original", strcmp(src, "aceg") == 0);
    ft_striteri(src, NULL);
    CHECK("ft_striteri", "NULL callback no-op", strcmp(src, "aceg") == 0);
}

/* A pipe captures actual bytes emitted by the four _fd functions. */
static void test_fd_output(void)
{
    int pipefd[2];
    char received[256];
    char expected[256];
    ssize_t n;
    size_t used;

    if (pipe(pipefd) != 0)
    {
        CHECK("fd functions", "pipe creation", 0);
        return;
    }
    ft_putchar_fd('X', pipefd[1]);
    ft_putstr_fd("hello", pipefd[1]);
    ft_putendl_fd("!", pipefd[1]);
    ft_putstr_fd("", pipefd[1]);
    ft_putnbr_fd(0, pipefd[1]);
    ft_putchar_fd(' ', pipefd[1]);
    ft_putnbr_fd(42, pipefd[1]);
    ft_putchar_fd(' ', pipefd[1]);
    ft_putnbr_fd(-42, pipefd[1]);
    ft_putchar_fd(' ', pipefd[1]);
    ft_putnbr_fd(INT_MIN, pipefd[1]);
    ft_putchar_fd(' ', pipefd[1]);
    ft_putnbr_fd(INT_MAX, pipefd[1]);
    close(pipefd[1]);
    used = 0;
    while ((n = read(pipefd[0], received + used, sizeof(received) - used)) > 0)
        used += (size_t)n;
    close(pipefd[0]);
    strcpy(expected, "Xhello!\n0 42 -42 -2147483648 2147483647");
    CHECK("*_fd", "all output exact bytes", used == strlen(expected)
        && memcmp(received, expected, used) == 0);
}

int main(void)
{
    test_classification();
    test_strings_1();
    test_memory();
    test_bounded_strings();
    test_alloc_and_atoi();
    test_part2_strings();
    test_callbacks();
    test_fd_output();
    printf("\nRESULT: %d passed, %d failed\n", g_pass, g_fail);
    if (g_fail)
        return 1;
    return 0;
}
