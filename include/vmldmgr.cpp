#ifndef _DEBUG
void vmld_mgr_start(void) {}
void vmld_mgr_stop(void) {}
#endif // _DEBUG

#ifdef _DEBUG

#include <stdio.h>  // printf
#include <stdlib.h> // malloc

#include "vmldmgr.h"

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
	int max_cnt;
} vmld_mgr_t;

static vmld_mgr_t _vmld_mgr;

void vmld_mgr_start(void)
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
	_vmld_mgr.max_cnt = 0;
}

void vmld_mgr_stop(void)
{
	int i;
	int is_written;

	is_written = 0; // false
	for (i = 0; i < _vmld_mgr.max_cnt; i++)
	{
		vmld_mgr_item_t* item = &_vmld_mgr.items[i];
		if (item->ptr != NULL)
		{
			if (!is_written)
			{
				is_written = 1; // true
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
	if (is_written)
	{
		fprintf(stderr, "******************************************************************************\n");
	}
}

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

void vmld_mgr_del(void* ptr)
{
	int i, j;
	vmld_mgr_item_t* item;
	vmld_mgr_item_t* temp;
	int is_max_cnt_changed;

	if (ptr == NULL)
	{
		fprintf(stderr, "ptr is null\n");
		return;
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

			is_max_cnt_changed = 1; // true
			temp = item + 1;
			for (j = i + 1; j < _vmld_mgr.max_cnt; j++)
			{
				if (temp->ptr != NULL)
				{
					is_max_cnt_changed = 0; // false
					break;
				}
				temp++;
			}
			if (is_max_cnt_changed) _vmld_mgr.max_cnt = i + 1;
			return;
		}
	}
}

#endif // _DEBUG
