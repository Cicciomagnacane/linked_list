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

struct string_item *string_item_new(const char *string)
{
    struct string_item *item = malloc(sizeof(struct string_item));
    if (!item)
    {
        return NULL;
    }
    item->string = string;
    return item;
}

struct list_node *list_get_tail(struct list_node **head)
{
    struct list_node *current_node = *head;
    struct list_node *last_node = NULL;
    while (current_node)
    {
    last_node = current_node;
    current_node = current_node->next;
    }
    return last_node;
}

struct list_node *list_append(struct list_node **head, struct list_node *item)
{
    struct list_node *tail = list_get_tail(head);
    if (!tail)
    {
        *head = item;
    }
    else
    {
        tail->next = item;
    }
    item->next = NULL;
    return item;
}

struct list_node *list_pop(struct list_node **head)
{
    struct list_node *current_head = *head;
    if (!current_head)
    {
        return NULL;
    }
    *head = (*head)->next;
    current_head->next = NULL;
    return current_head;
}

struct list_node *list_remove(struct list_node **head, struct list_node *item)
{
    struct list_node *current_node = *head;
    struct list_node *tmp_node = NULL;

    if (!current_node)
    {
        return NULL;
    }

    if (current_node==item)
    {
        list_pop(head);
    }
    
    while (current_node->next != item)
    {
        current_node = current_node->next;

        if (!current_node->next)
        {
            return NULL;
        }
        
    }
    
    tmp_node=current_node->next;
    current_node->next=tmp_node->next;
    current_node=tmp_node;
    current_node->next=NULL;

    return current_node;
}

static void *list_reverse(struct list_node **head)  //My first approach
{
    struct list_node* prev = NULL;
    struct list_node* current = *head;
    struct list_node* next = NULL;
    while (current != NULL) {
        // Store next
        next = current->next;
  
        // Reverse current node's pointer
        current->next = prev;
  
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *head = prev;
}


// struct list_node *list_reverse(struct string_item **list, struct string_item **reversed_list)
// {
//     struct string_item* removed_item = (struct string_item*)list_remove((struct list_node**)&list, (struct list_node*)list_get_tail(list));
    
//     while(removed_item)
//     {
//         list_append((struct list_node**)&reversed_list, (struct list_node *)string_item_new(removed_item->string));
//         struct list_node *tail= (struct list_node*)list_get_tail(list);

//         if (!tail)
//         {
//             removed_item=NULL;
//         }
//         else
//         {
//             removed_item= (struct string_item*)list_remove((struct list_node**)&list,(struct list_node*)list_get_tail(list));
            
//         }
//     }
//     return *reversed_list;
// }


int main()
{
    struct string_item *my_linked_list = NULL;
    struct string_item *obj1=string_item_new("Hello World!");
    struct string_item *obj2=string_item_new("text1");
    struct string_item *obj3=string_item_new("text2");
    struct string_item *obj4=string_item_new("hi");
    list_append((struct list_node **)&my_linked_list, (struct list_node *)obj1);
    list_append((struct list_node **)&my_linked_list, (struct list_node *)obj2);
    list_append((struct list_node **)&my_linked_list, (struct list_node *)obj3);
    list_append((struct list_node **)&my_linked_list, (struct list_node *)obj4);
    //struct string_item *string_item = my_linked_list;
    
    //list_remove((struct list_node **)&my_linked_list, (struct list_node *)obj2);
  
    // while (my_linked_list)
    // {
    //     printf("%s\n", string_item->string);
    //     string_item = (struct string_item *)string_item->node.next;
    // }

    //struct string_item* reversed_list = NULL;
    //struct string_item *reversed_item = list_reverse(&my_linked_list,&reversed_list);
    // while (reversed_list)
    // {
    //     printf("%s\n", reversed_item->string);
    //     reversed_item = (struct string_item *)reversed_item->node.next;
    // }

    list_reverse(&my_linked_list);
    struct string_item* reversed_item = my_linked_list;

    while (my_linked_list)
    {
        printf("%s\n", reversed_item->string);
        reversed_item = (struct string_item *)reversed_item->node.next;
    }
    return 0;
}

