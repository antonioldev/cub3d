#include "../../libs/unity/unity.h"
#include "../../../src/minishell.h"

void setUp(void) {
    //printf("Setting up...\n");
}

void tearDown(void) {
    //printf("Tearing down...\n");
}

void should_return_null(void)
{
	char *str = NULL;

	t_token_list	*result = tokenize(str, 0);
	TEST_ASSERT_NULL(result);
}

void should_create_the_token_correctly(void)
{
    char *str = "   echo 123";
    t_token_list *result = tokenize(str, ft_strlen(str));
    TEST_ASSERT_EQUAL_STRING("echo", result->value);
}

void should_handle_single_quotes_and_spaces_correctly(void)
{
    char *str = "  \'echo 123\'   ";
    t_token_list *result = tokenize(str, ft_strlen(str));
    TEST_ASSERT_EQUAL_STRING("echo 123", result->value);
}

void should_handle_double_quotes_and_spaces_correctly(void)
{
    char *str = "   \"echo 123\"   ";
    t_token_list *result = tokenize(str, ft_strlen(str));
    TEST_ASSERT_EQUAL_STRING("echo 123", result->value);
}

void should_handle_in_redirection_correctly(void)
{
	char *str = "<infile";
    t_token_list *result = tokenize(str, ft_strlen(str));
    TEST_ASSERT_EQUAL_CHAR('<', result->token);
}

void should_handle_out_redirection_correctly(void)
{
	char *str = ">outfile";
    t_token_list *result = tokenize(str, ft_strlen(str));
    TEST_ASSERT_EQUAL_CHAR('>', result->token);
}

void should_handle_double_in_redirection_correctly(void)
{
	char *str = "<<infile";
    t_token_list *result = tokenize(str, ft_strlen(str));
    TEST_ASSERT_EQUAL_INT(174, result->token);
}

void should_handle_double_out_redirection_correctly(void)
{
	char *str = ">>outfile";
    t_token_list *result = tokenize(str, ft_strlen(str));
    TEST_ASSERT_EQUAL_INT(175, result->token);
}

void should_handle_pipe_correctly(void)
{
	char *str = "   |outfile";
    t_token_list *result = tokenize(str, ft_strlen(str));
    TEST_ASSERT_EQUAL_CHAR('|', result->token);
}

void should_handle_path_in_quote_correctly(void)
{
    char *str = "\'  ./test/test   \'";
    t_token_list *result = tokenize(str, ft_strlen(str));
    TEST_ASSERT_EQUAL_STRING("  ./test/test   ", result->value);
}

void should_handle_path_in_double_quote_correctly(void)
{
    char *str = "\"  ./test/test   \"";
    t_token_list *result = tokenize(str, ft_strlen(str));
    TEST_ASSERT_EQUAL_STRING("  ./test/test   ", result->value);
}

void should_handle_path_correctly(void)
{
    char *str = "  ./test/test   ";
    t_token_list *result = tokenize(str, ft_strlen(str));
    TEST_ASSERT_EQUAL_STRING("./test/test", result->value);
}


int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(should_return_null);
	RUN_TEST(should_create_the_token_correctly);
	RUN_TEST(should_handle_single_quotes_and_spaces_correctly);
	RUN_TEST(should_handle_double_quotes_and_spaces_correctly);
	RUN_TEST(should_handle_in_redirection_correctly);
	RUN_TEST(should_handle_out_redirection_correctly);
	RUN_TEST(should_handle_double_in_redirection_correctly);
	RUN_TEST(should_handle_double_out_redirection_correctly);
	RUN_TEST(should_handle_pipe_correctly);
	RUN_TEST(should_handle_path_in_quote_correctly);
	RUN_TEST(should_handle_path_in_double_quote_correctly);
	RUN_TEST(should_handle_path_correctly);
	// RUN_TEST();

	if (Unity.TestFailures)
	{
    	printf("\033[31m");
    	printf("Some tests failed.\n");
    	printf("\033[0m");
    	UNITY_END();
    	return 1;
	}
	else
	{
    	printf("\033[32m");
    	printf("All tests passed.\n");
    	printf("\033[0m");
    	UNITY_END();
    	return 0;
	}
}