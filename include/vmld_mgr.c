#include <stddef.h> // size_t
#include <stdio.h> // printf
#include <stdlib.h> // malloc

#include "vmld_mgr.h"

#define VMLD_ITEM_CNT 65536

typedef struct
{
	void*  ptr;
	size_t size;
	char*  file;
	int    line;
} vmld_mgr_item_t;

typedef struct
{
	vmld_mgr_item_t items[VMLD_ITEM_CNT];
	bool del_check;
	int max_cnt;
} vmld_mgr_t;

vmld_mgr_item_t* _find(void* ptr);
vmld_mgr_item_t* _add(void* ptr, size_t size, char* file, int line);
vmld_mgr_item_t* _del(void* ptr);

static vmld_mgr_t _vmld_mgr;

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

void vmld_mgr_stop(bool auto_free)
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
				printf("******************************************************************************\n");
			}
			printf("memory leak %p(%d bytes) %s:%d\n",
				item->ptr, (int)item->size, item->file, item->line);
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
	_vmld_mgr.del_check = false;
}

vmld_mgr_item_t* _vmld_mgr_find(void* ptr)
{
	for (int i = 0; i < _vmld_mgr.max_cnt; i++)
	{
		vmld_mgr_item_t* item = &_vmld_mgr.items[i];
		if (item->ptr == ptr)
		{
			return info;
		}
	}
	return NULL;
}

vmld_mgr_item_t* _vmld_mgr_add(void* ptr, size_t size, char* file, int line)
{
	for (int i = 0; i < m_cnt; i++)
	{
		VMemoryLeakInfo* info = &m_info[i];
		if (info->p == NULL)
		{
			info->p    = p;
			info->size = size;
			info->file = file;
			info->line = line;
			if (i + 1 > m_cur_max_cnt) m_cur_max_cnt = i + 1;
			return info;
		}
	}
	return NULL;
}

VMemoryLeakInfo* VMemoryLeak::del(void* p)
{
	for (int i = 0; i < m_cur_max_cnt; i++)
	{
		VMemoryLeakInfo* info = &m_info[i];
		if (info->p == p)
		{
			info->p    = NULL;
			info->size = 0;
			info->file = NULL;
			info->line = 0;

			bool m_cur_max_cnt_move = true;
			VMemoryLeakInfo* temp = info + 1;
			for (int j = i + 1; j < m_cur_max_cnt; j++)
			{
				if (temp->p != NULL)
				{
					m_cur_max_cnt_move = false;
					break;
				}
				temp++;
			}

			if (m_cur_max_cnt_move) m_cur_max_cnt = i + 1;

			return info;
		}
	}
	return NULL;
}
