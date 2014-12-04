#include <stddef.h> // size_t
#include <stdio.h>  // printf
#include <stdlib.h> // malloc

#include "vmld_mgr.h"

#define VMLD_ITEM_CNT 65536

typedef struct
{
	void* ptr;
	size_t size;
	char* file;
	int line;
} vmld_mgr_item_t;

typedef struct
{
	vmld_mgr_item_t items[VMLD_ITEM_CNT];
	bool del_check;
	int max_cnt;
} vmld_mgr_t;

static vmld_mgr_t _vmld_mgr;

void* vmld_mgr_add(void* ptr, size_t size, const char* file, const int line)
{
	int i;
	vmld_mgr_item_t* item;

	if (ptr == NULL)
	{
		fprintf(stderr, "ptr is null size=%d file=%s line=%d\n", (int)size, file, line);
		return NULL;
	}
	for (i = 0; i < VMLD_ITEM_CNT; i++)
	{
		item = &_vmld_mgr.items[i];
		if (item->ptr == NULL)
		{
			item->ptr = ptr;
			item->size = size;
			item->file = (char*)file;
			item->line = (int)line;
			if (i + 1 > _vmld_mgr.max_cnt)
				_vmld_mgr.max_cnt = i + 1;
			return ptr;
		}
	}
	fprintf(stderr, "failed in vmld_mgr_add(%p, %d, %s, %d)\n", ptr, (int)size, file, line);
	return NULL;
}

bool vmld_mgr_del(void* ptr)
{
	int i, j;
	vmld_mgr_item_t* item;
	vmld_mgr_item_t* temp;

	if (ptr == NULL)
	{
		fprintf(stderr, "ptr is null\n");
		return false;
	}
	for (i = 0; i < _vmld_mgr.max_cnt; i++)
	{
		item = &_vmld_mgr.items[i];
		if (item->ptr == ptr)
		{
			item->ptr = NULL;
			item->size = 0;
			item->file = NULL;
			item->line = 0;

			bool change_max_cnt = true;
			temp = item + 1;
			for (j = i + 1; j < _vmld_mgr.max_cnt; j++)
			{
				if (temp->ptr != NULL)
				{
					change_max_cnt = false;
					break;
				}
				temp++;
			}
			if (change_max_cnt) _vmld_mgr.max_cnt = i + 1;
			return true;
		}
	}
	if (_vmld_mgr.del_check)
	{
		fprintf(stderr, "failed in vmld_mgr_del(%p)\n", ptr);
		return false;
	}
	return true;
}

void vmld_mgr_start(bool del_check)
{
	int i;
	vmld_mgr_item_t* item;

	for (i = 0; i < VMLD_ITEM_CNT; i++)
	{
		item = &_vmld_mgr.items[i];
		item->ptr = NULL;
		item->size = 0;
		item->file = NULL;
		item->line = 0;
	}
	_vmld_mgr.del_check = del_check;
	_vmld_mgr.max_cnt = 0;
}

void vmld_mgr_stop(void)
{
	int i;
	bool write_start;

	write_start = false;
	for (i = 0; i < _vmld_mgr.max_cnt; i++)
	{
		vmld_mgr_item_t* item = &_vmld_mgr.items[i];
		if (item->ptr != NULL)
		{
			if (!write_start)
			{
				write_start = true;
				fprintf(stderr, "******************************************************************************\n");
			}
			fprintf(stderr, "memory leak %p(%d bytes) %s:%d\n",
				item->ptr, (int)item->size, item->file, item->line);
			item->ptr = NULL;
			item->size = 0;
			item->file = NULL;
			item->line = 0;
		}
	}
	if (write_start)
	{
		fprintf(stderr, "******************************************************************************\n");
	}
	_vmld_mgr.del_check = false;
}
