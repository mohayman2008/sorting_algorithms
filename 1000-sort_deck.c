#include "sort.h"
#include "deck.h"

/**
 * card_val - Calculate the integer represents the value of a playing card
 *
 * @value: The string representaion of the card value
 *
 * Return: The value of the card
 */
int card_val(const char *value)
{
	int val;

	if (!value || !*value)
		return (0);

	if (!strcmp(value, "Ace"))
		val = 1;
	else if (!strcmp(value, "10"))
		val = 10;
	else if (!strcmp(value, "Jack"))
		val = 11;
	else if (!strcmp(value, "Queen"))
		val = 12;
	else if (!strcmp(value, "King"))
		val = 13;
	else if (value[0] >= '2' && value[0] <= '9' && !value[1])
		val = value[0] - '0';
	else
		val = 0;

	return (val);
}

/**
 * cmp_cards - Compares two nodes of a deck doubly linked list
 *		according to their kinds and values
 *
 * @node1: The first card
 * @node2: The second card
 *
 * Return: (1) if card1 > card2, (-1) card1 < card2 and (0) if they are equal
 */
int cmp_cards(const void *node1, const void *node2)
{
	const card_t *card1, *card2;
	int val1, val2;

	card1 = (*(deck_node_t **) node1)->card;
	card2 = (*(deck_node_t **) node2)->card;

	if (card1->kind < card2->kind)
	/* Card1 is higher priority rank card so it should come first */
		return (-1);

	if (card1->kind > card2->kind)
	/* Card2 is higher priority rank card so it should come first */
		return (1);

	/* The cards has equal ranks so the value is compared */
	val1 = card_val(card1->value);
	val2 = card_val(card2->value);

	if (val1 < val2)
		return (-1);
	if (val1 > val2)
		return (1);
	return (0);
}

/**
 * sort_deck - Sorts a deck of playing cards
 *
 * @deck: pointer to the deck doubly linked list head
 */
void sort_deck(deck_node_t **deck)
{
	size_t size = 0, i = 0;
	deck_node_t *current, **a;

	if (!deck || !*deck || !(*deck)->next)
		return;

	current = *deck;
	while (current)
	{
		size++;
		current = current->next;
	}

	a = malloc(sizeof(*a) * size);
	if (!a)
		return;

	current = *deck;
	while (current)
		a[i++] = current,
		current = current->next;

	qsort(a, size, sizeof(*a), cmp_cards);

	for (i = 0 ; i < size ; i++)
	{
		if (!i)
			*deck = a[i],
			a[i]->prev = NULL;
		else
			a[i]->prev = a[i - 1];

		if (i < size - 1)
			a[i]->next = a[i + 1];
		else
			a[i]->next = NULL;
	}

	free(a);
}
