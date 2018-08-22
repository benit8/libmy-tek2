/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** dsa / list / sort.c
*/

#include "my/dsa/list.h"

static void split_list(list_node_t *head, list_node_t **a, list_node_t **b)
{
	list_node_t *slow = head;
	list_node_t *fast = head->next;

	while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}
	*a = head;
	*b = slow->next;
	slow->next = NULL;
}

static list_node_t *sorted_merge(list_node_t *a, list_node_t *b,
	comp_func_t *cmp)
{
	list_node_t *result = NULL;

	if (!a)
		return (b);
	else if (!b)
		return (a);
	if (cmp(a->data, b->data) <= 0) {
		result = a;
		result->next = sorted_merge(a->next, b, cmp);
	}
	else {
		result = b;
		result->next = sorted_merge(a, b->next, cmp);
	}
	return (result);
}

static void sort(list_node_t **headp, comp_func_t *cmp)
{
	list_node_t *head = *headp;
	list_node_t *a = NULL;
	list_node_t *b = NULL;

	if (!head || !head->next)
		return;
	split_list(head, &a, &b);
	sort(&a, cmp);
	sort(&b, cmp);
	*headp = sorted_merge(a, b, cmp);
}

void list_sort(list_t *this, comp_func_t *cmp)
{
	if (!this || !cmp)
		return;
	else if (list_get_size(this) < 2)
		return;
	sort(&this->head, cmp);
}