#include "lvgl.h"
#include <stdio.h>
#include <sys/time.h>
#include "ak_thread.h"
#include "ak_common.h"

#include "qmsd_gui.h"
#include "qmsd_touch.h"
#include "qm_ui_entry.h"

static pthread_t g_qmsg_gui_tl;

static void* qmsd_gui_thread(void* argv);

int main(void)
{	
	// 在线程中执行lvgl相关任务。
	int err = ak_thread_create(&(g_qmsg_gui_tl), qmsd_gui_thread, NULL, ANYKA_THREAD_MIN_STACK_SIZE, 11);
	if(err < 0)
	{
		printf("fail to create lvgl thread !\n");
		return -1;
	}

	while(1)
	{	
		ak_sleep_ms(30);
	}

	pthread_join(g_qmsg_gui_tl,NULL);
	return 0;
}

static void* qmsd_gui_thread(void* argv)
{
	ak_thread_set_name("qmsd_gui_thread");

	qmsd_gui_init();
	qmsd_touch_init();

	lv_qm_ui_entry();

	while(1) {
		lv_task_handler();
		ak_sleep_ms(5);
		lv_tick_inc(5);
	}

	return NULL;
}
