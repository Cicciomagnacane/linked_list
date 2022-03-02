#pragma once
#include "clove.h"
#include "..\LinkedList.h"

CLOVE_TEST(LINKED_LIST_APPEND)
{
    struct string_item *list = NULL;
    struct string_item *test001 = string_item_new("Test001");
    struct string_item *test002 = string_item_new("Test002");
    struct string_item *test003 = string_item_new("Test003");

    list_append((struct list_node **)&list, (struct list_node *)test001);
    list_append((struct list_node **)&list, (struct list_node *)test002);
    list_append((struct list_node **)&list, (struct list_node *)test003);

    CLOVE_PTR_EQ(list, test001);
    CLOVE_PTR_EQ(test001->node.next, test002);
    CLOVE_PTR_EQ(test002->node.next, test003);
    CLOVE_NULL(test003->node.next);
};

CLOVE_TEST(LINKED_LIST_POP)
{
    struct string_item *list = NULL;
    struct string_item *test001 = string_item_new("Test001");
    struct string_item *test002 = string_item_new("Test002");
    struct string_item *test003 = string_item_new("Test003");

    list_append((struct list_node **)&list, (struct list_node *)test001);
    list_append((struct list_node **)&list, (struct list_node *)test002);
    list_append((struct list_node **)&list, (struct list_node *)test003);

    list_pop((struct list_node **)&list);

    CLOVE_PTR_NE(list, test001);
    CLOVE_PTR_NE(list->node.next, test002);
    CLOVE_PTR_EQ(list, test002);
    CLOVE_PTR_EQ(test002->node.next, test003);
    CLOVE_NULL(test003->node.next);
}

CLOVE_TEST(LINKED_LIST_REMOVE)
{
    struct string_item *list = NULL;
    struct string_item *test001 = string_item_new("Test001");
    struct string_item *test002 = string_item_new("Test002");
    struct string_item *test003 = string_item_new("Test003");
    struct string_item *test004 = string_item_new("Test004");

    list_append((struct list_node **)&list, (struct list_node *)test001);
    list_append((struct list_node **)&list, (struct list_node *)test002);
    list_append((struct list_node **)&list, (struct list_node *)test003);
    list_append((struct list_node **)&list, (struct list_node *)test004);

    list_remove((struct list_node **)&list, (struct list_node *)test002);

    CLOVE_PTR_EQ(test001->node.next, test003);
    CLOVE_PTR_EQ(test003->node.next, test004);
    CLOVE_NULL(test004->node.next);
}
