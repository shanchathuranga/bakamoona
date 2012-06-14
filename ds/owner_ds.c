#include "owner_ds.h"
#include <stdlib.h>
#include <stdio.h>

OWNERLIST * make_owner_list()
{
  OWNERLIST * list = malloc( sizeof (OWNERLIST) );
  list->owner = NULL;
  list->next = NULL;

  return list;
}

void add_owner_to_list (OWNERLIST * list, OWNER * owner)
{
        if (list == NULL)
                return;
        if (list->owner == NULL)
        {
                list->owner = owner;
                list->next = NULL;
                return;
        }       
        
        OWNERNODE * tmp = list;
        while (tmp->next != NULL)
                tmp = tmp->next;

        tmp->next = malloc( sizeof (OWNERNODE) );
        tmp->next->owner = owner;
        tmp->next->next = NULL;
}

OWNERLIST * delete_owner_list (OWNERLIST * list)
{
        if (list == NULL)
                return NULL;
        recursive_owner_delete (list);
        return NULL;
}

static void recursive_owner_delete (OWNERLIST * list)
{
        if (list == NULL)
                return;
        recursive_owner_delete( list->next );
        free (list->owner);
        free (list);
}

void remove_owner (OWNER * owner)
{
        if (owner == NULL)
                return;

        free (owner);
}

void debug_owner_list (OWNERLIST * list)
{
        while (list)
        {
                if (list->owner == NULL)
                {
                        printf ("list->owner NULL");
                }
                else
                {
                        printf ("owner id = %d\n", list->owner->owner_id);
                }
                list = list->next;
        }
}
