
#include <stdint.h>
#include <stdbool.h>
#include "nordic_common.h"
#include "app_timer.h"

#define SIMPLE_TIMER_PRESCALER     0
#define SIMPLE_TIMER_OP_QUEUE_SIZE 4


#define SIMPLE_TIMER_INSTANTIATE(timer_name) APP_TIMER_DEF(timer_name)


void simple_timer_init () {
	APP_TIMER_INIT(SIMPLE_TIMER_PRESCALER,
                   SIMPLE_TIMER_OP_QUEUE_SIZE,
                   false);
}

uint32_t simple_timer_start (app_timer_id_t const* timer,
                             uint32_t milliseconds,
                             app_timer_timeout_handler_t callback) {

	uint32_t err_code;

	err_code = app_timer_create(timer, APP_TIMER_MODE_REPEATED, callback);
	if (err_code != NRF_SUCCESS) return err_code;

	err_code = app_timer_start(*timer,
	                           APP_TIMER_TICKS(milliseconds, SIMPLE_TIMER_PRESCALER),
	                           NULL);
	return err_code;
}



/* EXAMPLE

SIMPLE_TIMER_INSTANTIATE(my_timer);

static void timer_handler (void* p_context) {
	...
}

int main () {
	uint32_t err;

	simple_timer_init();
	err = simple_timer_start(&my_timer, 500, timer_handler);

	while (1);
}

*/


/* TODO

Just allocate some timers here and get the API I want

init();
start(100, callback);

*/