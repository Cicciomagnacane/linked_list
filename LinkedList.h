#pragma once
#include <stddef.h> // required for NULL
#include <stdio.h>
#include <stdlib.h>

struct list_node
{
    struct list_node *next;
};

struct string_item
{
    struct list_node node;
    const char *string;
};


struct string_item *string_item_new(const char *string);
struct list_node *list_get_tail(struct list_node **head);
struct list_node *list_append(struct list_node **head, struct list_node *item);
struct list_node *list_pop(struct list_node **head);
struct list_node *list_remove(struct list_node **head, struct list_node *item);
static void *list_reverse(struct list_node **head);
// struct list_node *list_reverse2(struct string_item **list, struct string_item **reversed_list);