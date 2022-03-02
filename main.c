#include "LinkedList.h"

int main()
{
    struct string_item *my_linked_list= NULL;
    struct string_item *obj1=string_item_new("Hello World!");
    struct string_item *obj2=string_item_new("text1");
    struct string_item *obj3=string_item_new("text2");
    struct string_item *obj4=string_item_new("hi");
    list_append((struct list_node **)&my_linked_list, (struct list_node *)obj1);
    list_append((struct list_node **)&my_linked_list, (struct list_node *)obj2);
    list_append((struct list_node **)&my_linked_list, (struct list_node *)obj3);
    list_append((struct list_node **)&my_linked_list, (struct list_node *)obj4);
    struct string_item *string_item = my_linked_list;
    
    //list_remove((struct list_node **)&my_linked_list, (struct list_node *)obj2);
  
    while (my_linked_list)
    {
        printf("%s\n", string_item->string);
        string_item = (struct string_item *)string_item->node.next;
    }

    //struct string_item* reversed_list = NULL;
    //struct string_item *reversed_item = list_reverse(&my_linked_list,&reversed_list);
    // while (reversed_list)
    // {
    //     printf("%s\n", reversed_item->string);
    //     reversed_item = (struct string_item *)reversed_item->node.next;
    // }

    // list_reverse(&my_linked_list);
    // struct string_item* reversed_item = my_linked_list;

    // while (my_linked_list)
    // {
    //     printf("%s\n", reversed_item->string);
    //     reversed_item = (struct string_item *)reversed_item->node.next;
    // }
    return 0;
}