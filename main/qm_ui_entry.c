/***
* author:xnby
* platform: esp
* version: 1.0.0
* UIResolution: 320*240
*/

#include "qm_ui_entry.h"
#include <stdio.h>
#include <stdlib.h>

void lvgl_blockly_loop();
void lvgl_blockly_init();
    /*
    * includes
    */


    /*
    * declear screen_main
    */
lv_obj_t * screen_main;
lv_obj_t * label_7dc2;
    /*
    * declear main_screen
    */
lv_obj_t * main_screen;
lv_obj_t * label_de6a;

    LV_FONT_DECLARE(ali_font_16);

    void show_screen_screen_main();
    void show_screen_main_screen();
    /*
    * keyboard
    */
    lv_obj_t * g_kb = NULL;

static void g_kb_event_cb(lv_obj_t * event_kb, lv_event_t event)
{
    /* Just call the regular event handler */
    if (event == LV_EVENT_APPLY)
    {
        lv_obj_set_hidden(event_kb, true);
    }
    else if (event == LV_EVENT_CANCEL)
    {
        lv_obj_set_hidden(event_kb, true);
    }
    else
    {
        lv_keyboard_def_event_cb(event_kb, event);
    }
}
static void g_create_kb_ifneeded()
{
    if (g_kb == NULL)
    {
        g_kb = lv_keyboard_create(lv_scr_act(), NULL);
        lv_obj_set_pos(g_kb, 5, 90);
        lv_obj_set_event_cb(g_kb, g_kb_event_cb); /* Setting a custom event handler stops the keyboard from closing automatically */
        lv_obj_set_size(g_kb, LV_HOR_RES - 10, 140);
        lv_keyboard_set_cursor_manage(g_kb, true); /* Automatically show/hide cursors on text areas */
        lv_obj_set_hidden(g_kb, true);
    }
}
static void g_show_kb()
{
    lv_obj_set_parent(g_kb, lv_scr_act());
    lv_obj_set_hidden(g_kb, false);
    lv_obj_align(g_kb, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, 0);
}

    /**
    *开机启动屏相关
    */
static lv_style_t style_star, style_black, style_url;
lv_obj_t *logo;
lv_obj_t *logo_star;
lv_obj_t *url_label;
lv_obj_t *url_mask;
lv_obj_t *mask_layer;
int timer_cnt = 0;
/****
    * 临时变量用于数据传输
    */
char _tmpbuf[32];

/*
    * declear codes
    */



/*
 * callback functions begins
 */
/*
 * callback functions ends
 */
    /*
    * init codes
    */
void init_function()
{
#ifdef BLOCKLY_init
    blockly_init();
#endif
    }

void lv_8ms_label_7dc2_create()
{
	label_7dc2 = lv_label_create(screen_main, NULL);
	lv_label_set_long_mode(label_7dc2,LV_LABEL_LONG_BREAK);
	lv_obj_set_size(label_7dc2, 100, 40);
//set label style
	lv_obj_set_style_local_text_font(label_7dc2,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);

	lv_label_set_text(label_7dc2, "Label");
	lv_label_set_align(label_7dc2, LV_LABEL_ALIGN_CENTER);
#ifdef BLOCKLY_label_7dc2_EVENT_HANDLER
	lv_obj_set_event_cb(label_7dc2, label_7dc2_event_handler);
#endif
	if(label_7dc2->coords.x2-label_7dc2->coords.x1<100)
	{
		int x_offset=(100-(label_7dc2->coords.x2-label_7dc2->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_7dc2,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_7dc2,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_7dc2->coords.y2-label_7dc2->coords.y1<40)
	{
		int y_offset=(40-(label_7dc2->coords.y2-label_7dc2->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_7dc2,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_7dc2,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
		lv_obj_set_pos(label_7dc2, 110, 100);

}
void lv_8ms_label_de6a_create()
{
	label_de6a = lv_label_create(main_screen, NULL);
	lv_label_set_long_mode(label_de6a,LV_LABEL_LONG_BREAK);
	lv_obj_set_size(label_de6a, 100, 40);
//set label style
	lv_obj_set_style_local_text_font(label_de6a,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);

	lv_label_set_text(label_de6a, "Label");
	lv_label_set_align(label_de6a, LV_LABEL_ALIGN_CENTER);
#ifdef BLOCKLY_label_de6a_EVENT_HANDLER
	lv_obj_set_event_cb(label_de6a, label_de6a_event_handler);
#endif
	if(label_de6a->coords.x2-label_de6a->coords.x1<100)
	{
		int x_offset=(100-(label_de6a->coords.x2-label_de6a->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_de6a,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_de6a,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_de6a->coords.y2-label_de6a->coords.y1<40)
	{
		int y_offset=(40-(label_de6a->coords.y2-label_de6a->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_de6a,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_de6a,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
		lv_obj_set_pos(label_de6a, 110, 100);

}

void show_screen_screen_main()
{
        lv_scr_load(screen_main);

    
}
void show_screen_main_screen()
{
        lv_scr_load(main_screen);

    
}

int screen_loop_enter = 0;
int _delay = 0;
void lv_qm_ui_loop(void)
{
    #ifdef BLOCKLY_loop
    blockly_loop();
    #endif
}

void lv_qm_ui_entry(void)
{
    
    /*
    * create screens
    */
    screen_main = lv_obj_create(NULL, NULL);
    main_screen = lv_obj_create(NULL, NULL);
    main_screen = lv_obj_create(NULL, NULL);
    lv_scr_load(main_screen);

//CREATE STATIC OBJ
    lv_8ms_label_7dc2_create();
    lv_8ms_label_de6a_create();
  
    init_function();
}