#include <stddef.h> // size_t
#include <stdio.h> // printf
#include <stdlib.h> // malloc

#include "vmld_mgr.h"

typedef struct
{
	void*  ptr;
	size_t size;
	char*  file;
	int    line;
} vmld_mgr_item_t;

struct vmld_mgr
{
	vmld_mgr_item_t* items;
	bool del_check;
	int count;
	int last_idx;
};

vmld_mgr_item_t* _vmld_mgr_find(void* ptr);
vmld_mgr_item_t* _vmld_mgr_add(void* ptr, size_t size, char* file, int line);
vmld_mgr_item_t* _vmld_mgr_del(void* ptr);

static const int VMLD_DEFAULT_CNT = 65536;

bool _vmld_mgr_initialized = false;
vmld_mgr_t _vmld_mgr = {
	NULL,
	false,
	0,
	0
};

vmld_mgr_t* vmld_mgr_instance()
{
	if (!_vmld_mgr_initialized)
	{
		vmld_mgr_start(&_vmld_mgr, false, VMLD_DEFAULT_CNT);
	}
	return &_vmld_mgr;
}

vmld_mgr_t* vmld_mgr_create()
{
	vmld_mgr_t* vmld_mgr = (vmld_mgr_t*)malloc(sizeof(vmld_mgr_t));
	vmld_mgr_start(vmld_mgr, false, VMLD_DEFAULT_CNT); // initialize memory
	return vmld_mgr;
}

void vmld_mgr_destroy(vmld_mgr_t* vmld_mgr)
{
	vmld_mgr_stop(vmld_mgr, false); // check last memory leak
	vmld_mgr_start(vmld_mgr, false, 0); // clear memory
	free(vmld_mgr);
}

void vmld_mgr_start(vmld_mgr_t* vmld_mgr, bool del_check, int count)
{
	int i;

	if (vmld_mgr->items != NULL)
	{
		free(vmld_mgr->items);
		vmld_mgr->items = NULL;
	}
	vmld_mgr->del_check = del_check;
	if (count != 0)
	{
		vmld_mgr->items = (vmld_mgr_item_t*)malloc(sizeof(vmld_mgr_item_t) * count);
		for (i = 0; i < count; i++)
		{
			vmld_mgr_item_t* item = &vmld_mgr->items[i];
			item->ptr = NULL;
			item->size = 0;
			item->file = NULL;
			item->line = 0;
		}
	}
	vmld_mgr->count = count;
	vmld_mgr->last_idx = 0;
}

void vmld_mgr_stop(vmld_mgr_t* vmld_mgr, bool auto_free)
{
	int i;

	vmld_mgr->del_check = false;
	bool write_start = false;
	for (i = 0; i < vmld_mgr->last_idx; i++)
	{
		vmld_mgr_item_t* item = &vmld_mgr->items[i];
		if (item->ptr != NULL)
		{
			if (!write_start)
			{
				write_start = true;
				printf("******************************************************************************\n");
			}
			printf("%p memory leak %p(%d bytes) %s:%d\n",
				vmld_mgr, item->ptr, (int)item->size, item->file, item->line);
			if (auto_free)
			{
				free(item->ptr);
				item->ptr = NULL;
				item->size = 0;
				item->file = NULL;
				item->line = 0;
			}
		}
	}
	if (write_start)
	{
		printf("******************************************************************************\n");
	}
}
