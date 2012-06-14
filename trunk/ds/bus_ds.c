#include "bus_ds.h"
#include <stdlib.h>
#include <stdio.h>

BUSLIST * make_bus_list()
{
        BUSLIST * list = malloc( sizeof (BUSLIST) );
        list->bus = NULL;
        list->next = NULL;

        return list;
}

void add_bus_to_list (BUSLIST * list, BUS * bus)
{
        if (list == NULL)
                return;
        if (list->bus == NULL)
        {
                list->bus = bus;
                list->next = NULL;
                return;
        }       
        
        BUSNODE * tmp = list;
        while (tmp->next != NULL)
                tmp = tmp->next;

        tmp->next = malloc( sizeof (BUSNODE) );
        tmp->next->bus = bus;
        tmp->next->next = NULL;
}

BUSLIST * delete_bus_list (BUSLIST * list)
{
        if (list == NULL)
                return NULL;
        recursive_delete (list);
        return NULL;
}

static void recursive_bus_delete (BUSLIST * list)
{
        if (list == NULL)
                return;
        recursive_bus_delete( list->next );
        free (list->bus);
        free (list);
}

void remove_bus (BUS * bus)
{
	if (bus == NULL)
		return;

	free (bus);
}

void debug_bus_list (BUSLIST * list)
{
        while (list)
        {
                if (list->bus == NULL)
                {
                        printf ("list->bus NULL");
                }
                else
                {
                        printf ("bus id = %d\n", list->bus->bus_id);
                }
                list = list->next;
        }
}
